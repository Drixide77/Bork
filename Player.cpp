#include "Player.h"

Player::Player(const string& name, const string& description, Room* room): Creature(name, description, room)
{
  this->level = 1;
  this->exp = 0;
  this->type = PLAYER;
  // (room)->contains.push_back(this);  Thing already does this!!!
}

Player::~Player()
{

}

bool Player::parseCommands(const string& input)
{
  if (input == "exit" || input == "Exit") return false;
  else return true;
}
