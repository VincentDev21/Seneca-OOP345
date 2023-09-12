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
#include "CrimeStatistics.h"
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
namespace sdds
{
    CrimeStatistics::CrimeStatistics(std::string filename)
    {

        ifstream file(filename);
        Crime crime;

        auto removespaces = [](string line)
        {
            line.erase(0, line.find_first_not_of(' '));
            line.erase(line.find_last_not_of(' ') + 1);
            return line;
        };
        if (!file)
        {
            throw "Filename incorrect";
        }
        else
        {
            string line;
            while (getline(file, line))
            {
                crime.Province = removespaces(line.substr(0, 25));
                crime.district = removespaces(line.substr(25, 25));
                crime.crime = removespaces(line.substr(50, 25));
                crime.year = stoi(line.substr(75, 5));
                crime.num_cases = stoi(line.substr(80, 5));
                crime.num_resolved = stoi(line.substr(85, 5));
                crimes.push_back(crime);
            }
        }
    }
    void CrimeStatistics::display(std::ostream &out) const
    {
        for (auto &crime : crimes)
        {
            out<<crime<<endl;
        }
    }
    std::ostream &operator<<(std::ostream &out, const Crime &theCrime)
    {
        out<<"| ";
        out<<left<<setw(21)<< theCrime.Province<<" | ";
        out<<left<<setw(15)<<theCrime.district<<" | ";
        out<<left<<setw(20)<<theCrime.crime<<" | ";
        out<<right<<setw(6)<<theCrime.year<<" | ";
        out<<right<<setw(4)<<theCrime.num_cases<<" | ";
        out<<right<<setw(3)<<theCrime.num_resolved<<" |";
        return out;
    }
}