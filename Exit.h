#ifndef __Exit__
#define __Exit__

#include "Thing.h"
#include "Utils.h"

enum Direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

class Exit : public Thing
{
public:
  Thing* parent2;
  Direction dir1;
  Direction dir2;
  bool isLocked;

  Exit(const string& name, const string& description, Thing* room1, const Direction& dir1, Thing* room2, const Direction& dir2);
  virtual ~Exit();

  void LookExit(const Direction& dir);
  Direction GetDirection(const string& name);
};

#endif
