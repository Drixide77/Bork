#ifndef __Creature__
#define __Creature__

#include "Thing.h"
#include "Room.h"
#include "Utils.h"

class Creature: public Thing
{
public:
  int health;
  //items

  Creature(const string& name, const string& description, Room* room);
  virtual ~Creature();
};

#endif
