/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/01/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "Dictionary.h"
namespace sdds
{
    std::ostream &operator<<(std::ostream &os, const Dictionary &d)
    {
        os.width(20);
        os.setf(std::ios::right);
        os << d.getTerm() << ": " << d.getDefinition();
        return os;
    }
    bool operator==(const Dictionary &left, const Dictionary &right)
    {
        return left.getTerm() == right.getTerm();
    }
}
