#include "Player.h"

Player::Player(const string& name, const string& description, Room* room): Creature(name, description, room)
{
  level = 1;
  currentExp = 0;
  expToLevelUp = INITIAL_EXP;
  weapon = armor = NULL;
  type = PLAYER;
}

Player::~Player()
{

}

void Player::Look()
{
  cout << description << ".";
}

bool Player::parseCommands(string& input)
{
  list<string> tokens;
  Uncase(input);
  Split(input, tokens);
  list<string>::iterator it = tokens.begin();

  // L O O K
  if (*it == "look")
  {
    ++it;
    if (it == tokens.end())
    {
      cout << "You look at nothing in particular.\n"; // Player just typed "look"
      return true;
    }
    if (*it == "around") // Player typed "look around"
    {
      parent->Look();
      return true;
    }
    if (*it == "inventory" || *it == "items") // Player typed "look inventory/items"
    {
      cout << "You take a look at your inventory. ";
      if (contains.empty() == true) cout << "It's completely empty.";
      for (list<Thing*>::iterator it = contains.begin(); it != contains.end(); ++it)
      {
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
        target->Look();
        cout << "\n";
        return true;
      }
      else //Looking at the Players Inventory
      {
        target = Find(*it);
        if (target != NULL)
        {
          target->Look();
          cout << " It's inside your inventory.\n";
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
      else if (*it == "self" | *it == name) // Player typed "take self"
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
      cout << "You drop an imaginary sweetroll on the floor.\n"; // Player just typed "drop"
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

  // G O
  if (*it == "go")
  {

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
    cout << "You can \"look around\" to explore your surroundings. You can \"look\" pretty much everything.\n";
    cout << "You can \"take\" things you find and place them in your \"inventory\".\nYou can check it by \"look\"ing at \"inventory\" or \"items\".\n";
    cout << "You can \"drop\" items from your inventory on the floor. You can \"take\" them back later.\n";
    //---
    cout << "You can \"quit\" your adventure and abandon your progress.\n";
    cout << "If you can't remember all this information, you can always use \"help\" and bring it up again.\n";
    return true;
  }

  //If nothing matches...
  cout << "I didn't understand any of that. Try \"help\" if you are lost.\n";
  return true;
}
