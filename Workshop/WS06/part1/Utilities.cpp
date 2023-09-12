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
#include <sstream>
#include "Utilities.h"

using namespace std;
namespace sdds
{
    Vehicle *createInstance(std::istream &in)
    {
        string temp;
        getline(in, temp);
        stringstream str;
        size_t start = 0;
        while (start < temp.length() && temp[start] == ' ')
        {
            ++start;
        }
        str.str(temp);
        temp.erase(0, start);
        if (temp[0] == 'c' || temp[0] == 'C')
        {
            return new Car(str);
        }
        else{
            return nullptr;
        }
    }
}