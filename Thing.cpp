#include "Thing.h"

Thing::Thing(const string& name, const string& description, const ThingType& type)
{
  this->name = name;
  this->description = description;
  this->type = type;
}

Thing::~Thing()
{
  for (list<Thing*>::iterator it = contains.begin(); it != contains.end(); ++it)
  {
    delete (*it);
  }
}
