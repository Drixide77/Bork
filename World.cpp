#include "World.h"

World::World()
{
  Room* forest = new Room("forest", "a rather dense forest");

  things.push_back(forest);

  Item* sword = new Item("sword", "an awesome looking sword", forest, WEAPON);

  things.push_back(sword);

  player = new Player("Serlian", "I, me and myself", forest);

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

void World::PrintIntro() {
  //Pre adventure text
  cout << "  + + +   Welcome to BORK: A Tale of Tails!   + + +   \n";
  cout << "\n";
  cout << "If at any time you feel you don't know what to do. Try typing \"help\".\n";
  cout << "\n";

  //Intro text
  cout << "You have arrived at the forest near Greenvale. You have been tasked with a mighty quest.\n";
  cout << "\n";
}
