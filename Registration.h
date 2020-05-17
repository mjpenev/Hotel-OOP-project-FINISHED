#ifndef REGISTRATION_H_
#define REGISTRATION_H_

#include "Date.h"

class Registration
{
    private:
        Date startDate;
        Date endDate;
        char *note;
        void copyRegistration(Registration &other);
    public:
        void setStartDate(Date _startDate);
        void setEndDate(Date _endDate);
        void setNote(const char *_note);

        Date getStartDate();
        Date getEndDate();
        char *getNote();
        Registration();
        Registration(Registration &other);
        Registration(Date _startDate, Date _endDate, char *_note);
        Registration& operator=(Registration &other);
        ~Registration();

};
#endif