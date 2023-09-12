/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 07/13/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_CRIMESTATISTICS_H_
#define SDDS_CRIMESTATISTICS_H_
#include <iostream>
#include <vector>
namespace sdds
{
    struct Crime
    {
        std::string Province;
        std::string district;
        std::string crime;
        int num_cases;
        int year;
        int num_resolved;
    };
    class CrimeStatistics
    {
        std::vector<Crime> crimes;

    public:
        CrimeStatistics(std::string filename);
        void display(std::ostream &out) const;
    };
    std::ostream &operator<<(std::ostream& out, const Crime &theCrime);
}
#endif
