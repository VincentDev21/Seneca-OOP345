/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/15/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "Autoshop.h"
using namespace std;
// std::vector<Vehicle*> m_vehicles;

namespace sdds
{
    Autoshop::~Autoshop()
    {
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
            delete (*i);
    }
    Autoshop &Autoshop::operator+=(Vehicle *theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream &out) const
    {
        cout << "--------------------------------" << endl;
        cout << "| Cars in the autoshop!        |" << endl;
        cout << "--------------------------------" << endl;
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
        {
            (*i)->display(out);
            out << endl;
        }
        cout << "--------------------------------" << endl;
    }
}