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
#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_
#include "Vehicle.h"
#include <iostream>
#include <vector>
#include <list>
namespace sdds
{
    class Autoshop
    {
        std::vector<Vehicle *> m_vehicles;

    public:
        ~Autoshop();
        Autoshop &operator+=(Vehicle *theVehicle);
        void display(std::ostream &out) const;
        
        template <typename T>
        void select(T test, std::list<const Vehicle *> &vehicles)
        {
            for (auto temp : m_vehicles)
            {
                if (test(temp))
                    vehicles.push_back(temp);
            }
        }
    };
}
#endif
