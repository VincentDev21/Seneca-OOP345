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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <iostream>
#include "Vehicle.h"
namespace sdds
{
    class Car : public Vehicle
    {
        std::string Maker{};
        std::string Condition{};
        double Top_speed{};
        std::string removeWhitespace(const std::string &str);

    public:
        Car(){}
        Car(std::istream &);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream &out) const;
    };
}
#endif
