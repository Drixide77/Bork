#include "Thing.h"

Thing::Thing(const string& name, const string& description, Thing* parent = NULL): name(name), description(description), parent(parent), type(THING)
{
  if (parent != NULL) (parent)->contains.push_back(this);
}

Thing::~Thing()
{
  
}
