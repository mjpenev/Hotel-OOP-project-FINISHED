#include "Room.h"
#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

void Room::copyRoom(Room &other)
{
    roomNumber = other.roomNumber;
    beds = other.beds;
    guests = other.guests;
    isFree = other.isFree;
    startDate = other.startDate;
    endDate = other.endDate;
    note = other.note;
}
void Room::setStartDate(Date _startDate)
{
    startDate = _startDate;
}
void Room::setEndDate(Date _endDate)
{
    endDate = _endDate;
}
void Room::setNote(string _note)
{
    note = _note;
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
void Room::setAvailability(bool _isFree)
{
    isFree = _isFree;
}
std::string Room::getNote()
{
    return note;
}
Date& Room::getFromDate()
{
    return startDate;
}
Date& Room::getToDate()
{
    return endDate;
}
bool Room::getAvailabilty()
{
    return isFree;
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
void Room::printRoom()
{
    cout << "============================================" << endl;
    cout << "Room number: " << getRoomNumber() << endl;
    cout << "Reserved from " << startDate.getDay() << '.' << startDate.getMonth() << '.' << startDate.getYear() << " to " << 
    endDate.getDay() << '.' << endDate.getMonth() << '.' << endDate.getYear() << endl;
    cout << "Note: " << note << endl;
    cout << "Room has: " << beds << " beds" << endl;
    cout << "Reserved for: " << guests << " guests" << endl;
    cout << "Days: " << endDate - startDate << endl;
    cout << "============================================" << endl;
}

void Room::printAvailable()
{
    cout << "Room number: " << roomNumber << " Status: available " << " beds: " << beds << endl;
}

Room::Room()
{
    roomNumber = 1;
    beds = 0;
    guests = beds;
    isFree = true;

}
Room::Room(int _num, int _beds, int _guests, bool _isFree, Date from, Date to, string _note)
{
    roomNumber = _num;
    beds = _beds;
    guests = _guests;
    isFree = _isFree;
    startDate = from;
    endDate = to;
    note = _note;

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