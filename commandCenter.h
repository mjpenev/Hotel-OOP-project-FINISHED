#ifndef COMMAND_H_
#define COMMAND_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class workFile
{
    private:
        fstream file;
        string fileName;
        string fileInfo;
        string address;
        string toWrite;
        vector <string> words;
        void copy(workFile &other);
    public:
        void _open(string Adress);
        void _close();
        void _save();
        void _saveas(string path);
        void _help();
        void _exit();
        void _fileReservation();
        void writeInString(string anotherString);
        string getAddress();
        void _updateFile(string _Address);
        void _insertCommand(string word);
        int getSize();
        string _checkWord(int num);
        void _clearVector();
        workFile() = default;
        workFile(char *_fileName) = delete;
        ~workFile() = default;

};

#endif