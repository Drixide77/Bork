#include "Item.h"

Item::Item(const string& name, const string& description, Thing* container, const ItemType& itemType): Thing(name, description, container), itemType(itemType)
{
  type = ITEM;
  value = 0;
}

Item::~Item()
{
  cout << "You see " << description << ".";
}
