#ifndef DATE_H_
#define DATE_H_

class Date
{
    private:
        int day;
        int month;
        int year;
        void copyDate(Date &other);
    public:
        bool isValid(int day, int month, int year);
        int getDay();
        int getMonth();
        int getYear();
        void printDate();
        Date();
        Date(int _day, int _month, int _year);
        Date(Date &other);
        Date& operator =(Date &other);
        ~Date();
};

#endif 