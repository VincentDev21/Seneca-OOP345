/*
*****************************************************************************
                          Workshop - #5 (P1)
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

#include "Book.h"
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

namespace sdds
{
    std::string Book::removeWhitespace(const std::string &str)
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
    Book::Book()
    {
    }

    const std::string &Book::title() const
    {
        return Title;
    }
    const std::string &Book::country() const
    {
        return Country;
    }
    const size_t &Book::year() const
    {
        return Year;
    }
    double& Book::price(){
        return Price;
    }
    Book::Book(const std::string &strBook)
    {
        string inputString = strBook;
        size_t commaPos = inputString.find(',');

        Author = inputString.substr(0, commaPos);
        inputString = inputString.substr(commaPos + 1);

        commaPos = inputString.find(',');
        Title = removeWhitespace(inputString.substr(0, commaPos));
        inputString = inputString.substr(commaPos + 1);

        commaPos = inputString.find(',');
        Country = removeWhitespace(inputString.substr(0, commaPos));
        inputString = inputString.substr(commaPos + 1);

        commaPos = inputString.find(',');
        Price = std::stod(inputString.substr(0, commaPos));
        inputString = inputString.substr(commaPos + 1);

        commaPos = inputString.find(',');
        Year = std::stoi(inputString.substr(0, commaPos));
        inputString = inputString.substr(commaPos + 1);

        Description = removeWhitespace(inputString);
    }
    std::ostream &operator<<(std::ostream &os, const Book &b)
    {
        os<<setw(20);
        os<<b.Author<<" | ";
        os<<setw(22);
        os<<b.Title<<" | ";
        os<<setw(5);
        os<<b.Country<<" | ";
        os<<setw(4);
        os<<b.Year<<" | ";
        os<<fixed<<setprecision(2)<<setw(6)<<b.Price<<" | ";
        os<<b.Description;



      
        return os;
    }
}
