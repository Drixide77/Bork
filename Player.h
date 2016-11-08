#ifndef __Player__
#define __Player__

#include "Creature.h"
#include "Utils.h"

class Player: public Creature
{
public:
  int level;
  int exp;

  Player(const string& name, const string& description, Room* room);
  virtual ~Player();

  bool parseCommands(const string& input);
};

#endif
