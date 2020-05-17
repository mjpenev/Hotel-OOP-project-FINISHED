#include <iostream>
#include <cstring>
#include "Registration.h"

void Registration::copyRegistration(Registration &other)
{
    startDate = other.startDate;
    endDate = other.endDate;
    note = new char [strlen(other.note) + 1];
    strcpy(note, other.note);
}

void Registration::setStartDate(Date _startDate)
{
    startDate = _startDate;
}

void Registration::setEndDate(Date _endDate)
{
    endDate = _endDate;
}

void Registration::setNote(const char *_note)
{
    delete[] note;
    note = new char [strlen(_note) + 1];
    strcpy(note, _note);

}

Date Registration::getStartDate()
{
    return startDate;
}

Date Registration::getEndDate()
{
    return endDate;
}

char *Registration::getNote()
{
    return note;
}

Registration::Registration()
{
    Date startDate();
    Date endDate();
    note = nullptr;
}

Registration::Registration(Registration &other)
{
    copyRegistration(other);
}

Registration::Registration(Date _startDate, Date _endDate, char *_note)
{
    startDate = _startDate;
    endDate = _endDate;
    note = new char[strlen(_note) + 1];
    strcpy(this->note, _note);
}

Registration& Registration::operator=(Registration &other)
{
    if (this != &other)
    {
        copyRegistration(other);
    }
    return *this;
    
}

Registration::~Registration()
{
    delete[] note;
}