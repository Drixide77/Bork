#ifndef __World__
#define __ World__

#include "Thing.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include "Utils.h"

//Contains all the instances that make up the game world
class World
{
public:
  Player* player;
  vector<Thing*> things;

  World();
  virtual ~World();
};

#endif
