#ifndef __Item__
#define __Item__

#include "Thing.h"
#include "Utils.h"

class Item: public Thing
{
public:
  Item(const string& name, const string& description, Thing* container);
  virtual ~Item();
};

#endif
