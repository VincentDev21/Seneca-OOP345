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
#include "CrimeStatistics.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
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
                crime.m_resolved = stoi(line.substr(85, 5));
                crimes.push_back(crime);
            }
        }
    }
    void CrimeStatistics::display(std::ostream &out) const
    {
        int cases = 0;
        int resolved = 0;
        for (auto &crime : crimes)
        {
            out << crime << endl;
            cases += crime.num_cases;
            resolved += crime.m_resolved;
        }
        out << std::setw(89) << std::setfill('-') << '\n'
            << std::setfill(' ');

        out << "| " << right << setw(78) << setfill(' ') << "Total Crimes: " << setw(6) << cases << " |" << endl;
        out << "| " << right << setw(78) << setfill(' ') << "Total Resolved Cases: " << setw(6) << resolved << " |" << endl;
    }
    std::ostream &operator<<(std::ostream &out, const Crime &theCrime)
    {
        out << "| ";
        out << left << setw(21) << theCrime.Province << " | ";
        out << left << setw(15) << theCrime.district << " | ";
        out << left << setw(20) << theCrime.crime << " | ";
        out << right << setw(6) << theCrime.year << " | ";
        out << right << setw(4) << theCrime.num_cases << " | ";
        out << right << setw(3) << theCrime.m_resolved << " |";
        return out;
    }
    void CrimeStatistics::sort(std::string feild)
    {
        if (feild == "Province")
        {
            std::sort(crimes.begin(), crimes.end(), [](Crime &A, Crime &B)
                      { return A.Province < B.Province; });
        }
        if (feild == "Crime")
        {
            std::sort(crimes.begin(), crimes.end(), [](Crime &A, Crime &B)
                      { return A.crime < B.crime; });
        }
        if (feild == "Cases")
        {
            std::sort(crimes.begin(), crimes.end(), [](Crime &A, Crime &B)
                      { return A.num_cases < B.num_cases; });
        }
        if (feild == "Resolved")
        {
            std::sort(crimes.begin(), crimes.end(), [](Crime &A, Crime &B)
                      { return A.m_resolved < B.m_resolved; });
        }
    }
    void CrimeStatistics::cleanList()
    {
        for_each(crimes.begin(), crimes.end(), [](Crime &temp) {
            if (temp.crime == "[None]")
            {
                temp.crime = "      ";
            }
        });
    }
    bool CrimeStatistics::inCollection(std::string crime_name) const
    {
        bool aaaaa = false;
        for (auto &temp : crimes)
        {
            if (temp.crime == crime_name)
            {
                aaaaa = true;
            }
        }
        return aaaaa;
    }
    std::list<Crime> CrimeStatistics::getListForProvince(std::string province) const
    {
        std::list<Crime> result;

        std::copy_if(crimes.begin(), crimes.end(), std::back_inserter(result), [province](const Crime &crime)
                     { return crime.Province == province; });
        return result;
    }

}