#include "World.h"

World::World()
{
  Room* forest = new Room("forest", "a rather dense forest");

  things.push_back(forest);
}

World::~World()
{
  for (vector<Thing*>::iterator it = things.begin(); it != things.end(); ++it)
  {
    delete (*it);
  }
  delete this;
}
