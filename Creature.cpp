#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* room): Thing(name, description, room)
{
  type = CREATURE;
}

Creature::~Creature()
{
  
}
