#include <iostream>
#include "commandCenter.h"
#include <cstring>
#include <fstream>

void workFile::_open(string Address) 
{
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
/*void workFile::_save() 
{
    if (this->file.is_open())
    {
        file.close();
        file.open(fileName, std::ios::in | std::ios::out | std::ios::trunc);
        _writeFile();
    }
}
void workFile::_saveas() 
{
    fileName = words[1];
    ofstream newFile(fileName);
    _writeFile(newFile);

}*/
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
/*void workFile::_readFile() 
{

}
void workFile::_writeFile() 
{

}*/
void workFile::_insertCommand(string word)
{
    words.push_back(word);
}
string workFile::_checkWord(int num)
{
    return words[num];
}
void workFile::_clearVector()
{
    words.clear();
}
