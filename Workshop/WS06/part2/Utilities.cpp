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
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds
{
    Vehicle *createInstance(std::istream &in)
    {
        string str;
        char type;
        char comma;

        getline(in, str);
        str.erase(0, str.find_first_not_of(' '));
        stringstream sstr(str);
        sstr >> type >> comma;

        if (sstr)
        {
            if (type == 'c' || type == 'C')
            {
                return new Car(sstr);
            }
            else if (type == 'r' || type == 'R')
            {
                return new Racecar(sstr);
            }
            else
            {
                str = type;
                throw "Unrecognized record type: [" + str + "]";
            }
        }
        return nullptr;
    }

}