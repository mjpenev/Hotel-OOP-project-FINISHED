#ifndef ROOM_H_
#define ROOM_H_

class Room
{
    private:
        int roomNumber;
        int beds;
        int guests;
        bool isFree;

        void copyRoom(Room &other);
    public:
        void setRoomNumber(int _roomNumber);
        void setBeds(int _beds);
        void setGuests(int _guests);
        void freeRoom();
        void fullRoom();
        int getRoomNumber();
        int getBeds();
        int getGuests();     
        Room();
        Room(int _num, int _beds, int _guests, bool _isFree);
        Room(Room &other);
        Room& operator=(Room &other);
        ~Room();
};

#endif 