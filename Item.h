#ifndef __Item__
#define __Item__

#include "Thing.h"
#include "Utils.h"

enum ItemType
{
  CONSUMABLE,
  KEY,
  WEAPON,
  ARMOR
};

class Item: public Thing
{
public:
  int value;
  ItemType itemType;

  Item(const string& name, const string& description, Thing* container, const ItemType& itemType);
  virtual ~Item();
};

#endif
