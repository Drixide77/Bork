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

bool Player::parseCommands(string& input)
{
  list<string> tokens;
  Uncase(input);
  Split(input, tokens);
  list<string>::iterator it = tokens.begin();

  if (*it == "quit") //Quiting the game
  {
    TextColor(12);
    cout << "You seem to be trying to quit the game. If you really want to quit, type 'quit' again.\n";
    TextColor(15);

    string next;
    cin >> next;
    Uncase(next);
    if (next == "quit") return false;

    cout << "You decided not to quit.\n";
    cin.ignore();
    return true;
  }

  //If nothing matches...
  cout << "I didn't understand any of that.\n";
  return true;
}
