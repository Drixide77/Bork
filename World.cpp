#include "World.h"

World::World()
{
  Room* forest = new Room("forest", "a rather dense forest");

  things.push_back(forest);

  Item* sword = new Item("sword", "an awesome looking sword", forest, WEAPON);

  things.push_back(sword);

  player = new Player("player", "I, me and myself", forest);

  things.push_back(player);
}

World::~World()
{
  for (list<Thing*>::iterator it = things.begin(); it != things.end(); ++it)
    delete *it;

  things.clear();
}

bool World::sendCommands(string& input) {
  return (player)->parseCommands(input);
}
