#include "Player.h"

Player::Player(const string& name, const string& description, Room* room): Creature(name, description, room)
{
  level = 1;
  exp = 0;
  type = PLAYER;
}

Player::~Player()
{

}

bool Player::parseCommands(const string& input)
{
  if (input == "exit" || input == "Exit") return false;
  else return true;
}
