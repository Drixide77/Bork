#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* room): Thing(name, description, room)
{
  currentHealth = 1;
  maxHealth = 1;
  baseDamage = 1;
  baseDefense = 1;
  type = CREATURE;
}

Creature::~Creature()
{
  
}

bool Creature::isAlive()
{
  return (currentHealth > 0);
}
