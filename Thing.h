#ifndef __Thing__
#define __Thing__

#include <list>
#include "Utils.h"

enum ThingType
{
  ROOM,
  ITEM,
  EXIT,
  CREATURE,
  PLAYER,
  NPC
};

//Defines the most generic entity of the game
class Thing
{
  
public:
  ThingType type;
  string name;
  string description;
  Thing* parent;
  list<Thing*> contains;

  Thing(const string& name, const string& description, const ThingType& type);
  virtual ~Thing();
};

#endif