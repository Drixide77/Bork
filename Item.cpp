#include "Item.h"

Item::Item(const string& name, const string& description, Thing* container): Thing(name, description, ITEM)
{
  this->parent = container;
  (container)->contains.push_back(this);
}

Item::~Item()
{
  Thing::~Thing();
}
