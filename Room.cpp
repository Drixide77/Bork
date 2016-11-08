#include "Room.h"

Room::Room(const string& name, const string& description) : Thing(name, description, NULL)
{
  this->type = ROOM;
}


Room::~Room()
{

}
