#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
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
            s._open(address);
        }
        else if(command == "close")
        {
            s._close();
        }
        /*else if(command == "save")
        {
            s._save();
        }
        else if(s._checkWord(0) == "saveas")
        {
            s._saveas();
        }*/
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
            if (successful)
            {
                cout << "successfuly made registration!" << endl;
                h.addRegistration(currRoom);
            }

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
            h.printAllRegistrations();
        }   
        else if(s._checkWord(0) == "find!")
        {
            cout << "find! yeah" << endl;
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