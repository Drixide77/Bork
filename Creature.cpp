#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* room): Thing(name, description, CREATURE)
{
  this->parent = room;
  this->health = 1;
}

Creature::~Creature()
{
  Thing::~Thing();
}
