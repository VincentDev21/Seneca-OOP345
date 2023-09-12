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
#include <iomanip>
#include <string>
#include "Car.h"
using namespace std;
/*
std::string Maker;
std::string Condition;
double Top_speed;
*/
namespace sdds
{
    std::string Car::removeWhitespace(const std::string &str)
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
    Car::Car(std::istream &in)
    {
        string tag_temp, Maker_temp, Condition_temp;
        getline(in, tag_temp, ',');
        tag_temp = removeWhitespace(tag_temp);
        if (tag_temp == "c" || tag_temp == "C")
        {
            getline(in, Maker_temp, ',');
            Maker = removeWhitespace(Maker_temp);
            getline(in, Condition_temp, ',');
            Condition_temp = removeWhitespace(Condition_temp);
            if (Condition_temp == "n" || Condition_temp == "N")
            {
                Condition = "new";
            }
            if (Condition_temp == "u" || Condition_temp == "U")
            {
                Condition = "used";
            }
            if (Condition_temp == "b" || Condition_temp == "B")
            {
                Condition = "broken";
            }
            in >> Top_speed;
        }
    }
    std::string Car::condition() const
    {
        return Condition;
    }
    double Car::topSpeed() const
    {
        return Top_speed;
    }
    void Car::display(std::ostream &out) const
    {
        cout<<"| "<<right<<setw(10)<<Maker<<" | ";
        cout<<left<<setw(6)<<Condition<<" | ";
        cout<<setw(6)<< fixed << setprecision(2)<<Top_speed<<" |";
    }
}