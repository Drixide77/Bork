#include "Room.h"

Room::Room(const string& name, const string& description) : Thing(name, description, NULL)
{
  type = ROOM;
}


Room::~Room()
{

}
