#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* room): Thing(name, description, room)
{
  this->health = 1;
  this->type = CREATURE;
  (room)->contains.push_back(this);
}

Creature::~Creature()
{
  Thing::~Thing();
}
