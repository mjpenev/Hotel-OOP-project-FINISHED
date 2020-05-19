#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include "Date.h"

class Room
{
    private:
        int roomNumber;
        int beds;
        int guests;
        Date startDate;
        Date endDate;
        std::string note;
        bool isFree;

        void copyRoom(Room &other);
    public:
        void setStartDate(Date _startDate);
        void setEndDate(Date _endDate);
        void setRoomNumber(int _roomNumber);
        void setNote(std::string _note);
        void setBeds(int _beds);
        void setGuests(int _guests);
        void setAvailability(bool _isFree);
        std::string getNote();
        Date& getFromDate();
        Date& getToDate();
        int getRoomNumber();
        int getBeds();
        int getGuests(); 
        bool getAvailabilty(); 
        void printRoom(); 
        void printAvailable();  
        Room();
        Room(int _num, int _beds, int _guests, bool _isFree, Date from, Date to, std::string _note);
        Room(Room &other);
        Room& operator=(Room &other);
        ~Room();
};

#endif 