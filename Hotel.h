#ifndef HOTEL_H_
#define HOTEL_H_

#include "Room.h"
#include <vector>
#include <string>

class Hotel
{
    private:
        const int Rooms = 100;
        int size;

        Room *rooms;
        Room availableRooms[100];

    public:
        void generateHotel();
        void addRegistration(Room room);
        void deleteRegistration(int numOfRoom);
        void printAllRegistrations();
        void printAvailableRooms();
        int getRegisterSize();
        int getSizeOfHotel();
        void isRoomAvailable(Date onThisDate);
        Room currentRoom(int i);
        int getRoomNum(int i);
        int getBedI(int i);
        int getAvBedsI(int i);
        Date& getStartDateI(int i);
        Date& getEndDateI(int i);
        const int getRooms();
        Hotel();
        Hotel(Hotel& other);
        Hotel& operator=(Hotel &other);
        ~Hotel();
        
};

#endif 