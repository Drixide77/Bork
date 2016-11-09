#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* room): Thing(name, description, room)
{
  health = 1;
  type = CREATURE;
}

Creature::~Creature()
{
  
}
