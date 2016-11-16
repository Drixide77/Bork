#include "Exit.h"

Exit::Exit(const string& name, const string& description, Thing* room1, const Direction& dir1, Thing* room2, const Direction& dir2) :
  Thing(name, description, room1), parent2(room2), dir1 (dir1), dir2 (dir2)
{
  if (parent2 != NULL) (parent2)->contains.push_back(this);
  type = EXIT;
  isLocked = false;
}

Exit::~Exit()
{
  
}

void Exit::LookExit(const Direction& dir)
{
  if (dir == NORTH) cout << "You see " << description << " to the north.";
  else if (dir == EAST) cout << "You see " << description << " to the east.";
  else if (dir == SOUTH) cout << "You see " << description << " to the south.";
  else if (dir == WEST) cout << "You see " << description << " to the west.";
  if (isLocked == true)
  {
    cout << " It's locked.";
  }
}

Direction Exit::GetDirection(const string& name) {
  if (parent->name == name) return dir1;
  else return dir2;
}
