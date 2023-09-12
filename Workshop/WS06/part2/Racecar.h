/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 07/06/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_RACECAR_H_
#define SDDS_RACECAR_H_
#include "Car.h"
#include <iostream>
namespace sdds
{
    class Racecar : public Car
    {
        double m_booster{};

    public:
        Racecar(std::istream &in);
        void display(std::ostream &out) const;

        double topSpeed() const;
    };
}
#endif
