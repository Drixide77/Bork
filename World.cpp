#include "World.h"

World::World()
{
  Room* cell = new Room("cell", "a cobblestone walled cell");
  Room* storage = new Room("storage", "a small storage room");
  Room* post = new Room("post", "a rudimentary guard post");
  Room* entrance = new Room("entrance", "the entrance to the prison");

  things.push_back(cell);
  things.push_back(storage);
  things.push_back(post);
  things.push_back(entrance);

  Exit* door = new Exit("door", "a wooden cell door", cell, WEST, post, EAST);
  Exit* stairs = new Exit("stairs", "a set of stone stairs", storage, NORTH, post, SOUTH);
  Exit* hallway = new Exit("hallway", "a short hallway", post, NORTH, entrance, SOUTH);
  Exit* exit = new Exit("exit", "the exit to the outside", entrance, NORTH, NULL, SOUTH);
  exit->isLocked = true;

  things.push_back(door);
  things.push_back(stairs);
  things.push_back(hallway);
  things.push_back(exit);

  Item* sword = new Item("sword", "an awesome looking sword", post, WEAPON);
  Item* armor = new Item("armor", "a decent looking armor", storage, ARMOR);
  Item* lockpick = new Item("lockpick", "a small iron lockpick", entrance, KEY);
  Item* chest = new Item("chest", "a small chest with a lock", storage, CONTAINER);
  chest->isLocked = false;
  Item* key = new Item("key", "a rusty brass key", chest, KEY);

  things.push_back(sword);
  things.push_back(armor);
  things.push_back(lockpick);
  things.push_back(chest);
  things.push_back(key);

  player = new Player("Serlian", "I, me and myself", cell);

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
  cout << "               + + +   Welcome to BORK!   + + +\n";
  cout << "\n";
  cout << "If at any time you feel you don't know what to do. Try typing \"help\".\n";
  cout << "\n";

  //Intro text
  cout << "You wake up in what looks like a prison cell. You don't remember how you got in here. You don't see or hear anyone around. The cell door is open.\n";
  cout << "\n";
}
