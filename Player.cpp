#include "Player.h"

Player::Player(const string& name, const string& description, Room* room): Creature(name, description, room)
{
  type = PLAYER;
}

Player::~Player()
{

}

void Player::Look()
{
  cout << description << ".";
}

Thing* Player::Find(const string& name)
{
  for (list<Thing*>::iterator it = contains.begin(); it != contains.end(); ++it)
  {
    if ((*it)->name == name) return (*it);
    if ((*it)->type == ITEM)
    {
      if (((Item*)*it)->itemType == CONTAINER && ((Item*)*it)->isLocked == false)
      {
        list<Thing*>::iterator it2 = (*it)->contains.begin();
        if (it2 != (*it)->contains.end()) if ((*it2)->name == name) return (*it2);
      }
    }
  }
  return NULL;
}

bool Player::parseCommands(string& input)
{
  list<string> tokens;
  Uncase(input);
  Split(input, tokens);
  list<string>::iterator it = tokens.begin();
  string uncasedName = name;
  Uncase(uncasedName);

  // L O O K
  if (*it == "look")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "You look at nothing in particular.\n"; // Player just typed "look"
      return true;
    }
    else if (*it == "around") // Player typed "look around"
    {
      parent->Look();
      return true;
    }
    else if (*it == "self" | *it == uncasedName) // Player typed "look self"
    {
      cout << description << ".\n";
      return true;
    }
    else if (*it == "inventory" || *it == "items") // Player typed "look inventory/items"
    {
      cout << "You take a look at your inventory.";
      if (contains.empty() == true) cout << "It's completely empty.";
      for (list<Thing*>::iterator it = contains.begin(); it != contains.end(); ++it)
      {
        cout << " ";
        (*it)->Look();
      }
      cout << "\n";
      return true;
    }
    else // Player typed "look <thing>"
    {
      //Looking at the Room
      if (parent->name == *it)
      {
        parent->Look();
        return true;
      }
      //Looking at the Rooms contents
      Thing* target = parent->Find(*it);
      if (target != NULL)
      {
        if (target->type == EXIT)
        {
          Direction dir = ((Exit*)target)->GetDirection(parent->name);
          ((Exit*)target)->LookExit(dir);
        }
        else target->Look();
        cout << "\n";
        return true;
      }
      else //Looking at the Players Inventory
      {
        target = Find(*it);
        if (target != NULL)
        {
          target->Look();
          if (target == weapon) cout << " You are holding it.\n";
          else if (target == armor)cout << " You are wearing it.\n";
          else cout << " It's inside your inventory.\n";
          return true;
        }
        //Nothing else matched
        else cout << "You don't see \"" << *it << "\" anywhere around you.\n";
        return true;
      }
    }
  }

  // T A K E
  if (*it == "take")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "You try to grab the air.\n"; // Player just typed "take"
      return true;
    }
    else
    {
      if (*it == parent->name) // Player typed "take <room>"
      {
        cout << "You can't possibly \"take\" the space that surrounds you.\n";
        return true;
      }
      else if (*it == "self" | *it == uncasedName) // Player typed "take self"
      {
        cout << "That's not the meaning of \"picking yourself up\".\n";
        return true;
      }
      else // Player typed "take <thing>"
      {
        Thing* target = parent->Find(*it);
        if (target != NULL)
        {
          if (target->type == ITEM)
          {
            parent->contains.remove(target);
            contains.push_back(target);
            cout << "You take \"" << *it << "\" an place it in your inventory.\n";
          }
          else
          {
            cout << "You can't take \"" << *it << "\".\n";
          }
          return true;
        }
        else
        {
          Thing* target = Find(*it);
          if (target != NULL)
          {
            target->parent->contains.remove(target);
            contains.push_back(target);
            cout << "You take \"" << *it << "\" an place it in your inventory.\n";
            return true;
          }
        }
        //Nothing else matched
        cout << "You don't see \"" << *it << "\" anywhere around you.\n";
        return true;
      }
    }
  }

  // D R O P
  if (*it == "drop")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "You drop your expectation on the floor.\n"; // Player just typed "drop"
      return true;
    }
    if (*it == "self" | *it == name)
    {
      cout << "Giving up already?\n"; // Player typed "drop player"
      return true;
    }
    else // Player typed "drop <thing>"
    {
      Thing* target = Find(*it);
      if (target != NULL)
      {
        contains.remove(target);
        parent->contains.push_back(target);
        if (target == weapon)
        {
          weapon = NULL;
          cout << "You stop holding \"" << *it << "\". ";
        }
        if (target == armor)
        {
          armor = NULL;
          cout << "You remove \"" << *it << "\". ";
        }
        cout << "You place \"" << *it << "\" on the floor.\n";
      }
      else
      {
        //Nothing else matched
        cout << "You can't find \"" << *it << "\" in your inventory.\n";
      }
      return true;
    }
  }

  // P L A C E
  if (*it == "place")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "This is not the \"place\" for that.\n"; // Player just typed "place"
      return true;
    }
    else // Player typed "place <thing> ..."
    {
      Thing* target = Find(*it);
      string item = *it;
      ++it;
      if (it == tokens.end()) // Player just typed "place <thing>"
      {
        cout << "You need somewhere to place \"" << item << "\" in.\n";
        return true;
      }
      if (target != NULL)
      {
        Thing* destination = Find(*it);
        if (destination == NULL) destination = parent->Find(*it);

        if (destination != NULL)
        {
          if (destination->type == ITEM)
          {
            if (((Item*)destination)->itemType == CONTAINER)
            {
              if (destination->contains.empty() == false)
              {
                cout << "There's something already inside \"" << *it << "\".";
                return true;
              }
              contains.remove(target);
              destination->contains.push_back(target);
              if (target == weapon)
              {
                weapon = NULL;
                cout << "You stop holding \"" << *it << "\". ";
              }
              if (target == armor)
              {
                armor = NULL;
                cout << "You remove \"" << *it << "\". ";
              }
              cout << "You place \"" << item << "\" inside \"" << *it << "\".\n";
              return true;
            }
          }
          cout << "You can't place \"" << item << "\" inside \"" << *it << "\".\n";
        }
        else
        {
          cout << "You can't find \"" << *it << "\" anywhere.\n";
        }
      }
      else
      {
        //Nothing else matched
        cout << "You can't find \"" << item << "\" in your inventory.\n";
      }
      return true;
    }
  }

  // E Q U I P
  if (*it == "equip")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "You try to equip yourself with confidence.\n"; // Player just typed "equip"
      return true;
    }
    else // Player typed "equip <thing>"
    {
      Thing* target = Find(*it);
      if (target != NULL)
      {
        if (target->type == ITEM)
        {
          if (((Item*)target)->itemType == WEAPON)
          {
            weapon = (Item*)target;
            cout << "You are now holding \"" << *it << "\".\n";
          } else if (((Item*)target)->itemType == ARMOR)
          {
            armor = (Item*)target;
            cout << "You are wearing \"" << *it << "\".\n";
          }
          else
          {
            cout << "You cannot equip \"" << *it << "\".\n";
          }
        }
      }
      else
      {
        //Nothing else matched
        cout << "You can't find \"" << *it << "\" in your inventory.\n";
      }
      return true;
    }
  }

  // U N E Q U I P
  if (*it == "unequip")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "Needing to choose between to options, you still achieve to be ambiguous.\n"; // Player just typed "unequip"
      return true;
    }
    else // Player typed "unequip <thing>"
    {
      if (*it == weapon->name | *it == "weapon")
      {
        weapon = NULL;
        cout << "You stop holding \"" << *it << "\".\n";
      } 
      else if (*it == armor->name | *it == "armor")
      {
        armor = NULL;
        cout << "You remove \"" << *it << "\".\n";
      }
      else cout << "You don't have \"" << *it << "\" equiped.\n";
      return true;
    }
  }

  // O P E N
  if (*it == "open") // Doors or items
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "You open your mind to new life expiriences.\n";
      return true;
    }
    else
    {
      // Looking in your inventory
      Thing* target = Find(*it);
      if (target != NULL)
      {
        if (target->name != "chest")
        {
          cout << "You can't open \"" << *it << "\".\n";
          return true;
        }
        else
        {
          Thing* key = Find("lockpick");
          if (key != NULL)
          {
            cout << "You unlocked the chest with the lockpick.\n";
            ((Item*)target)->isLocked = false;
          }
          else cout << "You need something to unlock the chest.\n";
          return true;
        }
        return true;
      }
      target = parent->Find(*it);
      if (target != NULL)
      {
        if (target->name != "exit")
        {
          cout << "You can't open \"" << *it << "\".\n";
          return true;
        }
        else
        {
          Thing* key = Find("key");
          if (key != NULL)
          {
            cout << "You unlocked the exit door with the brass key.\n";
            ((Exit*)target)->isLocked = false;
            AWinnerIsYou();
            return false;
          }
          else cout << "You need something to unlock the exit door.\n";
          return true;
        }
        cout << "You can't find \"" << *it << "\" anywhere.\n";
        return true;
      }
      cout << "You can't find \"" << *it << "\" anywhere.\n";
      return true;
    }
  }

  // G O
  if (*it == "go")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "Where are you going?.\n"; // Player just typed "go"
      return true;
    }
    else // Player typed "go <thing>"
    {
      Direction dir;
      if (*it == "north") dir = NORTH;
      else if (*it == "east") dir = EAST;
      else if (*it == "south") dir = SOUTH;
      else if (*it == "west") dir = WEST;
      else
      {
        cout << "That's not a direction.\n"; // Player just typed "go something"
        return true;
      }

      Exit* target = ((Room*)parent)->FindExit(dir, parent->name);
      if (target != NULL)
      {
        if (target->isLocked == true)
        {
          cout << "The " << target->name << " is locked.\n";
        }
        else
        {
          if (target->parent == parent)
          {
            parent->contains.remove(this);
            parent = target->parent2;
            parent->contains.push_back(this);
          }
          else if (target->parent2 == parent)
          {
            parent->contains.remove(this);
            parent = target->parent;
            parent->contains.push_back(this);
          }
          cout << "You go through the " << target->name << ".\n";
        }
      }
      else
      {
        //Nothing else matched
        cout << "You can't go \"" << *it << "\". There's nothing there.\n";
      }
      return true;
    }
  }

  // Q U I T
  if (*it == "quit") //Quiting the game
  {
    TextColor(12);
    cout << "You seem to be trying to quit the game. If you really want to quit, type 'quit' again.\n";
    TextColor(15);

    string next;
    getline(cin, next);
    Uncase(next);
    if (next == "quit") return false;

    cout << "You decided not to quit.\n";
    cin.ignore();
    return true;
  }

  // H E L P
  if (*it == "help")
  {
    cout << "Let me remind you of the things you can do in BORK.\n";
    cout << "Use \"look around\" to check your surroundings. Use \"look <thing>\" to check anything else. You can refer yourself as \"self\".\n";
    cout << "You can \"take\" things you find and place them in your \"inventory\". You can check it by \"look\"ing at \"inventory\" or \"items\".\n";
    cout << "You can \"place\" items inside containers by using \"place <item> <container>\".\n";
    cout << "You can \"drop\" items from your inventory on to the floor. You can \"take\" them back later.\n";
    cout << "You can \"equip\" yourself with a \"weapon\" and an \"armor\". You can use \"unequip weapon\" or \"unequip armor\" to remove them.\n";
    cout << "You can move in a direction with \"go <direction>\". The valid directions are north, south, east and west.\n";
    cout << "Some objects or doors are locked. If you find the proper key, you can \"open\" them.\n";
    cout << "In the case of containers, you can \"take\" the items inside if you first put them in your inventory.\n";
    cout << "You can \"quit\" your adventure and abandon your progress.\n";
    cout << "If you can't remember all this information, you can always use \"help\" and bring it up again.\n";
    return true;
  }

  //If nothing matches...
  cout << "I didn't understand any of that. Try \"help\" if you are lost.\n";
  return true;
}
