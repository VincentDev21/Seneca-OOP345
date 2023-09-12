/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/25/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "Movie.h"
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
namespace sdds
{
    std::string Movie::removeWhitespace(const std::string &str)
    {
        std::string result = str;

        size_t start = 0;
        while (start < result.length() && result[start] == ' ')
        {
            ++start;
        }
        result.erase(0, start);

        size_t end = result.length() - 1;
        while (end >= 0 && result[end] == ' ')
        {
            --end;
        }
        result.erase(end + 1);

        return result;
    }
    Movie::Movie()
    {
    }
    const std::string &Movie::title() const
    {
        return Title;
    }
    Movie::Movie(const std::string &strMovie)
    {
        string inputString = strMovie;
        size_t commaPos = inputString.find(',');

        Title = removeWhitespace(inputString.substr(0, commaPos));
        inputString = inputString.substr(commaPos + 1);

        commaPos = inputString.find(',');
        year = stoi(inputString.substr(0, commaPos));
        inputString = inputString.substr(commaPos + 1);

        description = removeWhitespace(inputString);
    }
    std::ostream &operator<<(std::ostream &os, const Movie &M)
    {
        os<<setw(40)<<M.Title<<" | ";
        os<<setw(4)<<M.year<<" | ";
        os<<M.description<<endl;
        return os;
    }

}
