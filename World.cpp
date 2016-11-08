#include "World.h"

World::World()
{
  Room* forest = new Room("forest", "a rather dense forest");

  player = new Player("player", "I, me and myself", forest);

  Item* sword = new Item("sword", "an awesome looking sword", forest);

  things.push_back(forest);

  things.push_back(player);
}

World::~World()
{
  for (vector<Thing*>::iterator it = things.begin(); it != things.end(); ++it)
  {
    delete (*it);
  }
}
