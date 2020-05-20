#include "Hotel.h"
#include "Room.h"
#include <iostream>

using namespace std;

void Hotel::generateHotel()
{
    Date genDate;
    Room genRoom;
    int num = 1;
    genDate.setDay(0);
    genDate.setMonth(0);
    genDate.setYear(0);
    for (int i = 0; i < Rooms; i++)
    {
        genRoom.setStartDate(genDate);
        genRoom.setEndDate(genDate);
        genRoom.setRoomNumber(num);
        int randomBeds = rand()%5 + 1;
        genRoom.setBeds(randomBeds);
        genRoom.setGuests(0);
        availableRooms[i] = genRoom;
        num++;
    }

}

int Hotel::getSizeOfHotel()
{
    return Rooms;
}
int Hotel::getBedI(int i)
{
    return availableRooms[i].getBeds();
}

const int Hotel::getRooms()
{
    return Rooms;
}
Room Hotel::currentRoom(int i)
{
    return rooms[i];
}
int Hotel::getRoomNum(int i)
{
    return rooms[i].getRoomNumber();
}
int Hotel::getAvBedsI(int i)
{
    return availableRooms[i].getBeds();
}

void Hotel::addRegistration(Room room)
{
    Room* new_arr = new Room[size + 1];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = rooms[i];
    }
    size++;
    delete[] rooms;
    rooms = new_arr;
    rooms[size - 1] = room;

}

void Hotel::deleteRegistration(int numOfRoom)
{
    Room* new_arr = new Room[size + 1];
    for (int i = 0; i < size; i++)
    {
        if (numOfRoom == rooms[i].getRoomNumber())
        {
            // don't set room in new array
        }
        new_arr[i] = rooms[i];
    }
    size--;
    rooms = new_arr;
}
int Hotel::getRegisterSize()
{
    return size;
}

Date& Hotel::getStartDateI(int i)
{
    return rooms[i].getFromDate();
}

Date& Hotel::getEndDateI(int i)
{
    return rooms[i].getToDate();
}

void Hotel::isRoomAvailable(Date onThisDate)
{
    for (int i = 0; i < size; i++)
    {
        if (rooms[i].getFromDate() <= onThisDate && rooms[i].getToDate() >= onThisDate)
        {
            int num = rooms[i].getRoomNumber();
            availableRooms[num - 1].setAvailability(false);
        }
        
    }
    
}

Room Hotel::findRoom(int beds)
{
    for (int i = 0; i < Rooms; i++)
    {
        if (availableRooms[i].getBeds() >= beds)
        {
            bool flag = true;
            for (int j = 0; j < size; j++)
            {
                if (availableRooms[i].getRoomNumber() == rooms[i].getRoomNumber())
                {
                    flag = false;
                }

            }
            if (flag)
            {
                return availableRooms[i];
            }
            
        }
        
    }
    
}
void Hotel::printAvailableRooms()
{
    for (int i = 0; i < Rooms; i++)
    {
        if (availableRooms[i].getAvailabilty())
        {
            cout << "Room " << availableRooms[i].getRoomNumber() << " with " << availableRooms[i].getBeds() << " is available on this date " << endl;
        }
        
    }
    
}

Hotel::Hotel()
{
    size = 0;
}   
Hotel::Hotel(Hotel& other)
{
    size = other.size;
}
Hotel& Hotel::operator=(Hotel &other)
{
    if (this != &other)
    {
        size = other.size;
    }
    return *this;
}
Hotel::~Hotel()
{

}