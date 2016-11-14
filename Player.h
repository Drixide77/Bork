#ifndef __Player__
#define __Player__

#include "Creature.h"
#include "Item.h"
#include "Utils.h"

#define INITIAL_EXP 50
#define EXP_FACTOR 2

class Player: public Creature
{
public:
  int level;
  int currentExp;
  int expToLevelUp;
  Item* weapon;
  Item* armor;

  Player(const string& name, const string& description, Room* room);
  virtual ~Player();

  void Look();

  bool parseCommands(string& input);

};

#endif
