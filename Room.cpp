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
      if ((*it)->type == EXIT)
      {
        cout << " ";
        Direction dir = ((Exit*)(*it))->GetDirection(name);
        ((Exit*)(*it))->LookExit(dir);
      }
      else if ((*it)->type != PLAYER)
      {
        cout << " ";
        (*it)->Look();
      }
    }
    cout << "\n";
  }
}

Exit* Room::FindExit(const Direction& dir, const string& name) {
  for (list<Thing*>::iterator it = contains.begin(); it != contains.end(); ++it)
  {
    if ((*it)->type == EXIT)
    {
      if (((Exit*)*it)->dir1 == dir && ((Exit*)*it)->parent == this) return ((Exit*)*it);
      if (((Exit*)*it)->dir2 == dir && ((Exit*)*it)->parent2 == this) return ((Exit*)*it);
    }
  }
  return NULL;
}
