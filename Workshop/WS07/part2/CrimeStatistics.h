/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 07/16/2023

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
#include <list>
namespace sdds
{
    struct Crime
    {
        std::string Province;
        std::string district;
        std::string crime;
        int num_cases;
        int year;
        int m_resolved;
    };
    class CrimeStatistics
    {
        std::vector<Crime> crimes;
        int resolved=0;
        int cases=0;

    public:
        CrimeStatistics(std::string filename);
        void display(std::ostream &out) const;
        void sort(std::string feild);
        void cleanList();
        bool inCollection(std::string crime_name) const;
        std::list<Crime> getListForProvince( std::string name) const;
    };
    std::ostream &operator<<(std::ostream &out, const Crime &theCrime);
}
#endif
