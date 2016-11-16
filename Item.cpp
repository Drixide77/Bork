#include "Item.h"

Item::Item(const string& name, const string& description, Thing* container, const ItemType& itemType): Thing(name, description, container), itemType(itemType)
{
  type = ITEM;
  value = 0;
  isLocked = false;
}

Item::~Item()
{

}

void Item::Look()
{
  cout << "You see " << description << ".";
  if (itemType == CONTAINER)
  {
    if (isLocked == true)
    {
      cout << " It's locked.";
    }
    else if (contains.empty() == true)
    {
      cout << " It's empty.";
    }
    else
    {
      cout << " It has something inside. ";
      (*contains.begin())->Look();
    }
  }
}
