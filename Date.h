#ifndef DATE_H_
#define DATE_H_

#include <string>

class Date
{
    private:
        int day;
        int month;
        int year;
        void copyDate(Date &other);
    public:
        bool isValid(int day, int month, int year);
        void setDay(int _day);
        void setMonth(int _month);
        void setYear(int _year);
        int getDay();
        int getMonth();
        int getYear();
        void printDate();
        bool checkIfLeap(int _year);
        Date turnStringToDate(std::string _date);
        Date();
        Date(int _day, int _month, int _year);
        Date(Date &other);
        int operator - (Date &other);
        Date& operator =(Date &other);
        bool operator == (Date other);
        bool operator < (Date other);
        bool operator > (Date other);
        bool operator <= (Date &other);
        bool operator >= (Date &other);
        ~Date();
};

#endif 