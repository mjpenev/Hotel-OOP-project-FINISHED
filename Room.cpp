#include "Room.h"

using namespace std;

void Room::copyRoom(Room &other)
{
    roomNumber = other.roomNumber;
    beds = other.beds;
    guests = other.guests;
    isFree = other.isFree;
}
void Room::setRoomNumber(int _roomNumber)
{
    roomNumber = _roomNumber;
}
void Room::setBeds(int _beds)
{
    beds = _beds;
}
void Room::setGuests(int _guests)
{
    guests = _guests;
}
void Room::freeRoom()
{
    isFree = true;
}
void Room::fullRoom()
{
    isFree = false;
}
int Room::getRoomNumber()
{
    return roomNumber;
}
int Room::getBeds()
{
    return beds;
}
int Room::getGuests()
{
    return guests;
}

Room::Room()
{
    roomNumber = 1;
    beds = 0;
    guests = beds;
    isFree = true;
}
Room::Room(int _num, int _beds, int _guests, bool _isFree)
{
    roomNumber = _num;
    beds = _beds;
    guests = _guests;
    isFree = _isFree;
}
Room::Room(Room &other)
{
    copyRoom(other);
}
Room& Room::operator=(Room &other)
{
    if (this != &other)
    {
        copyRoom(other);
    }

    return *this;
}
Room::~Room()
{

}