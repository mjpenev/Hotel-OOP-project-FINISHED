#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>
#include "commandCenter.h"
#include "Hotel.h"
#include "Room.h"
#include "Date.h"

using namespace std;

int main()
{
    string command;
    workFile s;
    Hotel h;
    Room currRoom;
    Date currFromDate;
    Date currToDate;
    Date d;
    
    h.generateHotel();

    while(command != "exit")
    {
        cout << "Insert command: " << endl;
        getline(cin, command);
        istringstream lineIn(command);
        string word;
        while(lineIn >> word)
        {
            s._insertCommand(word);
        }
        if (s._checkWord(0) == "open")
        {
            string address = s._checkWord(1);
            s._open(h, address);
        }
        else if(command == "close")
        {
            s._close();
        }
        else if(command == "save")
        {
            s._save();
        }
        else if(s._checkWord(0) == "saveas")
        {
            string copyPath = s._checkWord(1);
            s._saveas(copyPath);
        }
        else if (command == "help")
        {
            s._help();
        }
        else if (s._checkWord(0) == "checkin")
        {
            bool successful = true;
            string roomNum = s._checkWord(1);
            string fromDate = s._checkWord(2);
            for (int i = 0; i < fromDate.length(); i++)
            {
                if (fromDate[i] == '-')
                {
                    fromDate[i] = ' ';
                }
                
            }
            string toDate = s._checkWord(3);
            for (int i = 0; i < toDate.length(); i++)
            {
                if (toDate[i] == '-')
                {
                    toDate[i] = ' ';
                }
                
            }
            vector <int> nums;
            int num;
            istringstream lineOfNums(roomNum + ' ' + fromDate +  ' ' + toDate);
            while(lineOfNums >> num)
            {
                nums.push_back(num);
            }
            
            if (nums[0] < h.getRooms())
            {
                currRoom.setRoomNumber(nums[0]);
            }
            else
            {
                cout << "Invalid number of room!" << endl;
                successful = false;
            }

            if (d.isValid(nums[3], nums[2], nums[1]))
            {
                currFromDate.setDay(nums[3]);
                currFromDate.setMonth(nums[2]);
                currFromDate.setYear(nums[1]);
                currRoom.setStartDate(currFromDate);
            }
            else
            {
                cout << "Invalid date!" << endl;
                successful = false;
            }
            if (d.isValid(nums[6], nums[5], nums[4]))
            {
                currToDate.setDay(nums[6]);
                currToDate.setMonth(nums[5]);
                currToDate.setYear(nums[4]);
                currRoom.setEndDate(currToDate);
            }
            else
            {
                cout << "Invalid date!" << endl;
                successful = false;
            }
            currRoom.setBeds(h.getBedI(nums[0]));
            currRoom.setGuests(h.getBedI(nums[0]));
            string noteRoom;
            for (int i = 4; i < s.getSize(); i++)
            {
                if (s._checkWord(i) != "[")
                {
                    noteRoom += s._checkWord(i);
                    noteRoom += ' ';
                }
                
            }
            currRoom.setNote(noteRoom);
            for (int i = 0; i < h.getRegisterSize(); i++)
            {
                if (h.getRoomNum(i) == nums[0])
                {
                    if (currRoom.getFromDate() >= h.getStartDateI(i) && currRoom.getToDate() <= h.getEndDateI(i))
                    {
                        successful = false;
                        cout << "Room is already taken!" << endl;
                    } 
                }
                
            }
            if (currFromDate > currToDate)
            {
                successful = false;
                cout << "The first date must be before the second!" << endl;
            }
            
            if (successful)
            {
                cout << "successfuly made registration!" << endl;
                s.writeInString("Make reservation: Room number " + s._checkWord(1) + " from " + s._checkWord(2) + " to " + s._checkWord(3) + " " + noteRoom + " | \n");
                h.addRegistration(currRoom);
            }

        }
        else if(command == "availability")
        {
            time_t t = std::time(0);
            std::tm *now = std::localtime(&t);   // algorithm for local time from Internet
            Date currDate;
            currDate.setYear(now->tm_year + 1900);
            currDate.setMonth(now->tm_mon + 1);
            currDate.setDay(now->tm_mday);
            h.isRoomAvailable(currDate);
            h.printAvailableRooms();
        }
        else if (s._checkWord(0) == "availability")
        {
            string dateToCheck = s._checkWord(1);
            Date toCheck;
            for (int i = 0; i < dateToCheck.length(); i++)
            {
                if (dateToCheck[i] == '-')
                {
                    dateToCheck[i] = ' ';
                }
                
            }
            std::vector <int> nums;
            int num;
            std::istringstream lineOfNums(dateToCheck);
            while(lineOfNums >> num)
            {
                nums.push_back(num);
            }
            if (d.isValid(nums[2], nums[1], nums[0]))
            {
                toCheck.setDay(nums[2]);
                toCheck.setMonth(nums[1]);
                toCheck.setYear(nums[0]);
            }
            h.isRoomAvailable(toCheck);
            h.printAvailableRooms();
            nums.clear();
        }
        else if(s._checkWord(0) == "checkout")
        {
            istringstream turnToInt(s._checkWord(1));
            int x;
            turnToInt >> x;
            bool check = false;
            for (int i = 0; i < h.getRegisterSize(); i++)
            {
                if (x == h.getRoomNum(i))
                {
                    check = true;
                }
                
            }
            if (check)
            {
                h.deleteRegistration(x);
                cout << "Reservation deleted! " << endl;
            }
            
        }
        else if(s._checkWord(0) == "report")
        {
            string fromDate = s._checkWord(1);
            string toDate = s._checkWord(2);

            for (int i = 0; i < h.getRegisterSize(); i++)
            {
                bool check = false;
                if (d.turnStringToDate(fromDate) <= h.getStartDateI(i) && d.turnStringToDate(toDate) >= h.getEndDateI(i))
                {
                    h.currentRoom(i).printRoom();
                    check = true;
                } 
                if (!check)
                {
                    cout << "No reserved rooms in this period!" << endl;
                }
                
                
            }
            

        }
        else if(s._checkWord(0) == "find")
        {
            string roomBeds = s._checkWord(1);
            string startD = s._checkWord(2);
            string endD = s._checkWord(3);
            istringstream readNum(roomBeds);
            int num;
            vector <int> pushNum;
            while(readNum >> num)
            {
                pushNum.push_back(num);
            }
            cout << "We found room just for you: " << endl;
            cout << "====================================" << endl;
            cout << "Room number " << h.findRoom(num).getRoomNumber() << " with " << h.findRoom(num).getBeds() << " bed/s!" << endl;
            cout << "====================================" << endl;
            cout << "Free from " << startD << " to " << endD << endl;
            cout << "Type checkin, room num, dates and note to reserve!" << endl;

        }   
        else if(s._checkWord(0) == "find!")
        {
            // currently empty
        }
        else if(s._checkWord(0) == "unavailable") // function is almost same as checkin
        {
            bool successful = true;
            string roomNum = s._checkWord(1);
            string fromDate = s._checkWord(2);
            for (int i = 0; i < fromDate.length(); i++)
            {
                if (fromDate[i] == '-')
                {
                    fromDate[i] = ' ';
                }
                
            }
            string toDate = s._checkWord(3);
            for (int i = 0; i < toDate.length(); i++)
            {
                if (toDate[i] == '-')
                {
                    toDate[i] = ' ';
                }
                
            }
            vector <int> nums;
            int num;
            istringstream lineOfNums(roomNum + ' ' + fromDate +  ' ' + toDate);
            while(lineOfNums >> num)
            {
                nums.push_back(num);
            }
            
            if (nums[0] < h.getRooms())
            {
                currRoom.setRoomNumber(nums[0]);
            }
            else
            {
                cout << "Invalid number of room!" << endl;
                successful = false;
            }

            if (d.isValid(nums[3], nums[2], nums[1]))
            {
                currFromDate.setDay(nums[3]);
                currFromDate.setMonth(nums[2]);
                currFromDate.setYear(nums[1]);
                currRoom.setStartDate(currFromDate);
            }
            else
            {
                cout << "Invalid date!" << endl;
                successful = false;
            }
            if (d.isValid(nums[6], nums[5], nums[4]))
            {
                currToDate.setDay(nums[6]);
                currToDate.setMonth(nums[5]);
                currToDate.setYear(nums[4]);
                currRoom.setEndDate(currToDate);
            }
            else
            {
                cout << "Invalid date!" << endl;
                successful = false;
            }
            currRoom.setBeds(h.getBedI(nums[0]));
            currRoom.setGuests(h.getBedI(nums[0]));
            string noteRoom;
            for (int i = 4; i < s.getSize(); i++)
            {
                noteRoom += s._checkWord(i);
                noteRoom += ' ';
                
            }
            currRoom.setNote(noteRoom);
            for (int i = 0; i < h.getRegisterSize(); i++)
            {
                if (h.getRoomNum(i) == nums[0])
                {
                    if (currRoom.getFromDate() >= h.getStartDateI(i) && currRoom.getToDate() <= h.getEndDateI(i))
                    {
                        successful = false;
                        cout << "Room is already taken!" << endl;
                    } 
                }
                
            }
            if (successful)
            {
                cout << "Successfully updated room status to unavailable!" << endl;
                s.writeInString("Make room unavailable: Room number " + s._checkWord(1) + " from " + s._checkWord(2) + " to " + s._checkWord(3) + " " + noteRoom + " | \n");
                h.addRegistration(currRoom);
            }
        }
        else if(s._checkWord(0) == "exit")
        {
            s._exit();
            break;
        }
        else
        {
            cout << "You've inputed an invalid command!" << endl;
        }
        s._clearVector();
        lineIn.clear();
    }
    
    return 0;
}