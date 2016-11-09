#include "Item.h"

Item::Item(const string& name, const string& description, Thing* container): Thing(name, description, container)
{
  type = ITEM;
}

Item::~Item()
{

}
