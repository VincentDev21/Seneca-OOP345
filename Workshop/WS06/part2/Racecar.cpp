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
#include <string>
#include "Racecar.h"
using namespace std;
// std::vector<Vehicle*> m_vehicles;

namespace sdds
{
    Racecar::Racecar(std::istream &in) : Car(in)
    {
        string str;
        getline(in, str);
        m_booster = stod(str.substr(0, str.find('\n')));
    }
    void Racecar::display(std::ostream& out) const
    {
        Car::display(out);
        out << "*";
    }
    double Racecar::topSpeed() const
    {
        return Car::topSpeed() * (1 + m_booster);
    }
}