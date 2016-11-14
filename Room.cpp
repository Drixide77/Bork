#include "Room.h"

Room::Room(const string& name, const string& description) : Thing(name, description, NULL)
{
  type = ROOM;
}


Room::~Room()
{

}

void Room::Look()
{
  cout << "You look at your surroundings. ";
  cout << "You are in " << description << ".";
  list<Thing*> things = contains;
  if (things.size() > 0)
  {
    for (list<Thing*>::iterator it = things.begin(); it != things.end(); ++it)
    {
      if ((*it)->name != "player")
      {
        cout << " ";
        (*it)->Look();
      }
    }
    cout << "\n";
  }
}
