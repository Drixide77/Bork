#include "Item.h"

Item::Item(const string& name, const string& description, Thing* container): Thing(name, description, container)
{
  this->type = ITEM;
  // (container)->contains.push_back(this); Thing already does this!!!
}

Item::~Item()
{

}
