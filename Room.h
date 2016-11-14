#ifndef __Room__
#define __Room__

#include "Thing.h"
#include "Utils.h"

//Defines a location in our game
class Room: public Thing
{
public:
  Room(const string& name, const string& description);
  virtual ~Room();

  void Look();
};

#endif
