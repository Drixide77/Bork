#ifndef __Creature__
#define __Creature__

#include "Thing.h"
#include "Room.h"
#include "Utils.h"

class Creature: public Thing
{
public:
  //Combat Stats
  int currentHealth;
  int maxHealth;
  int baseDamage;
  int baseDefense;

  Creature(const string& name, const string& description, Room* room);
  virtual ~Creature();

  bool isAlive();
};

#endif
