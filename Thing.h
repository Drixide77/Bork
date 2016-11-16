#ifndef __Thing__
#define __Thing__

#include <list>
#include "Utils.h"

class Item;

enum ThingType
{
  THING,
  ROOM,
  ITEM,
  EXIT,
  CREATURE,
  PLAYER,
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

public:
  Thing(const string& name, const string& description, Thing* parent);
  virtual ~Thing();

  virtual void Look();
  virtual Thing* Find(const string& name);
};

#endif
