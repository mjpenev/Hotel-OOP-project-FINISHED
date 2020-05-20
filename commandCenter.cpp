#include <iostream>
#include "commandCenter.h"
#include <cstring>
#include <fstream>
#include <sstream>
#include "Room.h"
#include "Date.h"
#include "Hotel.h"

void workFile::_fileReservation(Hotel &h)
{
    vector <string> fileWords;
    istringstream readWords(fileInfo);
    string word;
    Room currRoom;
    Date d;
    string num;
    while(readWords >> word)
    {
        fileWords.push_back(word);
    }
    for (int i = 0; i < fileWords.size(); i++)
    {
        if (fileWords[i] == "number")
        {
            num = fileWords[i + 1];
            istringstream readNums(num);
            int NUM;
            vector <int> nums;
            while(readNums >> NUM)
            {
                nums.push_back(NUM);
            }
            int roomNUM;
            roomNUM = nums[0];
            currRoom.setBeds(h.getAvBedsI(roomNUM));
            
            currRoom.setRoomNumber(roomNUM);
            nums.clear();
        }
        if (fileWords[i] == "from")
        {
            string start = fileWords[i + 1];
            Date result;
            for (int i = 0; i < start.length(); i++)
            {
                if (start[i] == '-')
                {
                    start[i] = ' ';
                }
                
            }
            std::vector <int> nums;
            int num;
            std::istringstream lineOfNums(start);
            while(lineOfNums >> num)
            {
                nums.push_back(num);
            }
            Date d;
            if (d.isValid(nums[2], nums[1], nums[0]))
            {
                result.setDay(nums[2]);
                result.setMonth(nums[1]);
                result.setYear(nums[0]);
            }
            currRoom.setStartDate(result);
            nums.clear();             

        }
        if (fileWords[i] == "to")
        {
            string end = fileWords[i + 1];
            Date result;
            for (int i = 0; i < end.length(); i++)
            {
                if (end[i] == '-')
                {
                    end[i] = ' ';
                }
                
            }
            std::vector <int> nums;
            int num;
            std::istringstream lineOfNums(end);
            while(lineOfNums >> num)
            {
                nums.push_back(num);
            }
            Date d;
            if (d.isValid(nums[2], nums[1], nums[0]))
            {
                result.setDay(nums[2]);
                result.setMonth(nums[1]);
                result.setYear(nums[0]);
            }
            currRoom.setEndDate(result);
            nums.clear();

        }        
        if (fileWords[i] == "Note")
        {
            int startIndex = i + 1;
            int endIndex;
            for (int j = 0; j < fileWords.size(); j++)
            {
                if (i + j > fileWords.size())
                {
                    break;
                }
                
                if (fileWords[i + j] == "|" || fileWords[i + j] == "*" || fileWords[i + j] == "guests")
                {
                    endIndex = i + j;
                    break;
                }
                
            }
            string _note;
            for (int k = startIndex; k < endIndex; k++)
            {
                _note+= fileWords[k];
                _note+= " ";
            }
            currRoom.setNote(_note);
            _note.clear();
        }
        if (fileWords[i] == "guests")
        {
            num = fileWords[i + 1];
            istringstream readNums(num);
            int NUM;
            vector <int> nums;
            while(readNums >> NUM)
            {
                nums.push_back(NUM);
            }
            int roomNUM;
            int guests = nums[0];
            currRoom.setGuests(guests);
            nums.clear();
        }
        
        if (fileWords[i] == "|")
        {
           h.addRegistration(currRoom);
        }

    }
    

}

void workFile::_updateFile(std::string _Address)
{
    ofstream writeInFile(_Address);
    writeInFile << toWrite;
    writeInFile << fileInfo << "*" << endl;
}

void workFile::writeInString(string anotherString)
{
    toWrite += anotherString;
}

string workFile::getAddress()
{
    return address;
}

void workFile::_open(Hotel &h, string Address) 
{
    address = Address;
    file.open(Address);
    string backwords;

    for (int i = Address.length(); i > 0; i--)
    {
        if (Address[i] == '\\')
        {
            break;
        }
        backwords += Address[i];
    }
    string real;
    for (int i = backwords.length(); i > 0; i--)
    {
        real += backwords[i];
    }
    fileName = real;
    

    if (this->file.is_open())
    {
        std::cout << "Successfully opened" << fileName << std::endl; 
        ifstream myFile(Address);
        getline(myFile, fileInfo, '*');
        _fileReservation(h);

    }
    else
    {
        std::cout << "A problem occurred in opening file!" << std::endl;
    }
    
}
void workFile::_close() 
{
    if (this->file.is_open())
    {
        this->file.close();
        std::cout << "Successfully closed" << fileName << endl;
    }
    else
    {
        std::cout << "No opened file!" << endl;
    }
}
void workFile::_save() 
{
    _updateFile(address);
    cout << "Successfully made changes to file!" << endl;
}
void workFile::_saveas(string path) 
{
    address = path;
    ofstream newFile(address);
    _updateFile(address);
    cout << "Successfully made new file and added all registrations! " << endl;

}
void workFile::_help()
{
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "open <file>         opens <file>" << std::endl;
    std::cout << "close               closes currently opened file" << std::endl;
    std::cout << "save                saves the currently opened file" << std::endl;
    std::cout << "saveas <file>       saves the currently opened file in <file>" << std::endl;
    std::cout << "help                prints this information'" << std::endl;
}
void workFile::_exit()
{
    if (this->file.is_open())
    {
        this->file.close();
    }
    cout << "Closing opened files... Ending program!" << endl;
    
}

void workFile::_insertCommand(string word)
{
    words.push_back(word);
}
string workFile::_checkWord(int num)
{
    return words[num];
}
int workFile::getSize()
{
    int counter = 0;
    for (int i = 0; i < words.size(); i++)
    {
        counter++;
    }
    return counter;
}
void workFile::_clearVector()
{
    words.clear();
}
