#include "Room.h"

Room::Room(const string& name, const string& description) : Thing(name, description, ROOM)
{

}


Room::~Room()
{
  Thing::~Thing();
}
