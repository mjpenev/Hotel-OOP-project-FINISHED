#ifndef HOTEL_H_
#define HOTEL_H_

#include "Room.h"
#include <vector>

class Hotel
{
    private:
        std::vector <Room> rooms;
        const int Rooms = 100;
        void copy(Hotel &other);
        
    public:
        void generateHotel();
        
        Hotel();
        Hotel(Hotel& other);
        Hotel& operator=(Hotel &other);
        ~Hotel();
        
};

#endif 