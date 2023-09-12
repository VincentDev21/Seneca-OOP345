/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/11/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "ConfirmationSender.h"
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

namespace sdds
{
    ConfirmationSender::ConfirmationSender() {}
    ConfirmationSender::~ConfirmationSender() {
        delete[]ptr;
    }
    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res)
    {
        bool boolean = false;
        for (size_t i = 0; i < NumReservation; i++)
        {
            if (ptr[i] == &res)
            {
                boolean = true;
            }
        }
        if (!boolean)
        {
            const Reservation **temp = new const Reservation *[NumReservation + 1];
            for (size_t i = 0; i < NumReservation; i++)
            {
                temp[i] = ptr[i];
            }
            temp[NumReservation++] = &res;
            delete[] ptr;
            ptr = temp;
        }
        return *this;
    }
    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res)
    {
        bool boolean = false;
        size_t index;
        for (size_t i = 0; i < NumReservation&&!boolean; i++)
        {
            if (ptr[i] == &res)
            {
                boolean = true;
                index = i;
            }
        }
        if (boolean)
        {
            const Reservation **temp = new const Reservation *[NumReservation-1];
            --NumReservation;
            for (size_t i = index; i < NumReservation; i++)
            {
                ptr[i] = ptr[i+1];
            }
            for (size_t i = 0; i < NumReservation; i++)
            {
                temp[i] = ptr[i];
            }
            delete[]ptr;
            ptr=temp;
           

        }
        return *this;
    }
    std::ostream &operator<<(std::ostream &os, const ConfirmationSender &c)
    {

        os << "--------------------------" << endl;
        os << "Confirmations to Send" << endl;
        os << "--------------------------" << endl;
        if (c.NumReservation != 0)
        {
            for (size_t i = 0; i < c.NumReservation; i++)
            {
                os << *c.ptr[i];
            }
        }
        else
        {
            os << "There are no confirmations to send!" << endl;
        }
        os << "--------------------------" << endl;
        return os;
    }
    ConfirmationSender::ConfirmationSender(const ConfirmationSender &other)
    {
        *this = other;
    }
    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &other)
    {
        if (this != &other)
        {
            
            delete[] ptr;
            NumReservation = other.NumReservation;
            ptr = new const Reservation *[other.NumReservation];
            for (size_t i = 0; i < other.NumReservation; i++)
            {
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender &&other)
    {
        *this = move(other);
    }
    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&other) {
        if (this != &other)
        {
            for (size_t i = 0; i < NumReservation; i++)
            {
                delete ptr[i];
            }
            delete[] ptr;
            NumReservation = other.NumReservation;
            ptr = other.ptr;
            other.ptr = nullptr;
            other.NumReservation = 0;
        }
        return *this;
    }
}
