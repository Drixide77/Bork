#include "Thing.h"

Thing::Thing(const string& name, const string& description, Thing* parent)
{
  this->name = name;
  this->description = description;
  this->parent = parent;
}

Thing::~Thing()
{
  
}
