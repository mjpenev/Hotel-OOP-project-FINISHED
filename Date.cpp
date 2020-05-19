#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include "Date.h"

void Date::copyDate(Date &other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

Date Date::turnStringToDate(std::string _date)
{
    Date result;
    for (int i = 0; i < _date.length(); i++)
    {
        if (_date[i] == '-')
        {
            _date[i] = ' ';
        }
        
    }
    std::vector <int> nums;
    int num;
    std::istringstream lineOfNums(_date);
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
    nums.clear();
    return result;
}

bool Date::checkIfLeap(int _year)
{
    if (_year % 4 == 0)
    {
        if (_year % 100 == 0) 
        {
            if (_year % 400 == 0) 
            {
                return true;
            }
        }

    } 
    return false;
}

bool Date::isValid(int day, int month, int year)
{
    if (day > 31 || day < 1 || month > 12 || month < 1 || year < 0 || year > 2100)
    {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }
    if (month == 2 && !checkIfLeap(year) && day > 28)
    {
        return false;
    }
    if (checkIfLeap(year) && month == 2 && day > 29)
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

int Date::operator - (Date &other)
{
    int yearRes;
    int monthRes;
    if (this->year != other.year)
    {
        yearRes = year - other.year;
        if (this->month != other.month)
        {
            monthRes = month - other.month;
            if (day == other.day)
            {
                return 365*yearRes + monthRes*30;
            }
            else
            {
                return 365*yearRes + monthRes*30 + (day - other.day);
            }
            
        }
        else
        {
            return 365*yearRes + (day - other.day);
        }
        
    }
    else
    {
        if (month == other.month)
        {
            return day - other.day;
        }
        else
        {
            monthRes = month - other.month;
            if (day == other.day)
            {
                return monthRes*30;
            }
            else
            {
                return monthRes*30 + (day - other.day);
            }
            
        }
        
    }
    

}

bool Date::operator < (Date other)
{
    if (this->year < other.year)
    {
        return true;
    }
    else if (this->year == other.year && this->month < other.month)
    {
        return true;
    }
    else if (this->year == other.year && this->month == other.month && this->day < other.day)
    {
        return true;
    }

    return false;
}

bool Date::operator > (Date other)
{
    if (this->year > other.year)
    {
        return true;
    }
    else if (this->year == other.year && this->month > other.month)
    {
        return true;
    }
    else if (this->year == other.year && this->month == other.month && this->day > other.day)
    {
        return true;
    }

    return false;
}

bool Date::operator <= (Date &other)
{
    if (this->year < other.year)
    {
        return true;
    }
    else if (this->year == other.year && this->month < other.month)
    {
        return true;
    }
    else if (this->year == other.year && this->month == other.month && this->day <= other.day)
    {
        return true;
    }

    return false;
}
bool Date::operator >= (Date &other)
{
    if (this->year > other.year)
    {
        return true;
    }
    else if (this->year == other.year && this->month > other.month)
    {
        return true;
    }
    else if (this->year == other.year && this->month == other.month && this->day >= other.day)
    {
        return true;
    }

    return false;
}


Date::~Date()
{

}