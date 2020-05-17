#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include "commandCenter.h"

using namespace std;

int main()
{
    string command;
    workFile s;

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
            
        }
        else if (s._checkWord(0) == "availability")
        {
            cout << "availability yeah" << endl;
        }
        else if(s._checkWord(0) == "checkout")
        {
            cout << "checkout yeah" << endl;
        }
        else if(s._checkWord(0) == "find")
        {
            cout << "find yeah" << endl;
        }
        else if(s._checkWord(0) == "find!")
        {
            cout << "find! yeah" << endl;
        }
        else if(s._checkWord(0) == "unavailable")
        {
            cout << "unavailable yeah" << endl;
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