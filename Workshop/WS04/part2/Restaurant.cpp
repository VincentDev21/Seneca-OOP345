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

#include "Restaurant.h"
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

namespace sdds
{
    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt)
    {
        ptr = new Reservation *[cnt];

        for (size_t i = 0; i < cnt; i++)
        {
            ptr[i] = new Reservation;
            *ptr[i] = *reservations[i];
        }
        NumReservation = cnt;
    }
    Restaurant::~Restaurant()
    {
        for (size_t i = 0; i < NumReservation; i++)
            {
                delete ptr[i];
            }
	delete[] ptr;
    }

    Restaurant::Restaurant(const Restaurant &other)
    {
        *this = other;
    }
    Restaurant &Restaurant::operator=(const Restaurant &other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < NumReservation; i++)
            {
                delete ptr[i];
            }
            delete[] ptr;
            NumReservation = other.NumReservation;
            ptr = new Reservation *[other.NumReservation];
            for (size_t i = 0; i < other.NumReservation; i++)
            {
                ptr[i] = new Reservation;
                *ptr[i] = *other.ptr[i];
            }
        }
        return *this;
    }
    Restaurant::Restaurant(Restaurant &&other)
    {
        *this = move(other);
    }
    Restaurant &Restaurant::operator=(Restaurant &&other)
    {
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
    size_t Restaurant::size() const
    {
        return NumReservation;
    }
    std::ostream &operator<<(std::ostream &os, const Restaurant &r)
    {
        static int call = 0;
        call++;

        os << "--------------------------" << endl;
        os << "Fancy Restaurant (" << call << ')' << endl;
        os << "--------------------------" << endl;
        if (r.NumReservation != 0)
        {
            for (size_t i = 0; i < r.NumReservation; i++)
            {
                os << *r.ptr[i];
            }
        }
        else
        {
            os << "This restaurant is empty!\n";
        }
        os << "--------------------------\n";
        return os;
    }
}