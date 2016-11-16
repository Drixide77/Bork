#ifndef __World__
#define __ World__

#include "Thing.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "Utils.h"

//Contains all the instances that make up the game world
class World
{
public:
  World();
  virtual ~World();

  bool sendCommands(string& input);

  void PrintIntro();

private:
  Player* player;
  list<Thing*> things;
};

#endif
