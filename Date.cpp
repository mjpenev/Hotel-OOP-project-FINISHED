#include <iostream>
#include <cstring>
#include "Date.h"

void Date::copyDate(Date &other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

bool Date::isValid(int day, int month, int year)
{
    if (day > 31 || day < 1 || month > 12 || month < 1 || year < 0 || year > 2020)
    {
        return false;
    }
    if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }
    return true;
    
}

void Date::setDay(int _day)
{
    day = _day;
}

void Date::setMonth(int _month)
{
    month = _month;
}

void Date::setYear(int _year)
{
    year = _year;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;   
}

int Date::getYear()
{
    return year;
}

void Date::printDate()
{
    std::cout << day << "-" << month << "-" << year << std::endl;
}


Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::Date(int _day, int _month, int _year)
{
    this->day = _day;
    this->month = _month;
    this->year = _year;
}

Date::Date(Date &other)
{
    copyDate(other);
}

Date& Date::operator =(Date &other)
{
    if (this != &other)
    {
        copyDate(other);
    }
    return *this;
    
}

Date::~Date()
{

}
