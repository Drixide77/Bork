#ifndef __Item__
#define __Item__

#include "Thing.h"
#include "Utils.h"

enum ItemType
{
  CONSUMABLE,
  KEY,
  WEAPON,
  ARMOR,
  CONTAINER
};

class Item: public Thing
{
public:
  int value;
  ItemType itemType;
  bool isLocked;

  Item(const string& name, const string& description, Thing* container, const ItemType& itemType);
  virtual ~Item();

  void Look();
};

#endif
