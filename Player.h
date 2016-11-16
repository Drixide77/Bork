#ifndef __Player__
#define __Player__

#include "Creature.h"
#include "Item.h"
#include "Room.h"
#include "Utils.h"

class Player: public Creature
{
public:
  Item* weapon;
  Item* armor;

  Player(const string& name, const string& description, Room* room);
  virtual ~Player();

  void Look();

  Thing* Find(const string& name);

  bool parseCommands(string& input);

};

#endif
