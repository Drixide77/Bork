#include "Player.h"

Player::Player(const string& name, const string& description, Room* room): Creature(name, description, room)
{
  this->type = PLAYER;
  this->level = 1;
  this->exp = 0;
}

Player::~Player()
{
  Creature::~Creature();
}

bool Player::parseCommands(const string& input)
{
  if (input == "exit" || input == "Exit") return false;
  else return true;
}
