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

        size_t start = result.find_first_not_of(' ');
        if (start != std::string::npos)
        {
            result.erase(0, start);
        }

        size_t end = result.find_last_not_of(' ');
        if (end != std::string::npos)
        {
            result.erase(end + 1);
        }

        return result;
    }

    Car::Car(std::istream &in)
    {
        
            string Maker_temp, Condition_temp, speed_temp;
            getline(in, Maker_temp, ',');
            Maker = removeWhitespace(Maker_temp);
            getline(in, Condition_temp, ',');
            Condition_temp = removeWhitespace(Condition_temp);
            if (Condition_temp == "n" || Condition_temp == "N" || Condition_temp == "" || Condition_temp == " ")
            {
                Condition = "new";
            }
            else if (Condition_temp == "u" || Condition_temp == "U")
            {
                Condition = "used";
            }
            else if (Condition_temp == "b" || Condition_temp == "B")
            {
                Condition = "broken";
            }
            else
            {
                throw "Invalid record!";
            }
            getline(in, speed_temp, ',');
            try
            {
                Top_speed = stod(speed_temp);
            }
            catch (...)
            {
                throw "Invalid record!";
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
        out << "| " << right << setw(10) << Maker << " | ";
        out << left << setw(6) << condition() << " | ";
        out << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
    }
}