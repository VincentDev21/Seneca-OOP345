/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/08/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "Reservation.h"
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

namespace sdds
{
    Reservation::Reservation()
    {
    }
    Reservation::~Reservation()
    {
    }
    void Reservation::update(int m_day, int time)
    {
        day = m_day;
        hour = time;
    }

    std::string Reservation::removeWhitespace(const std::string &str)
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

    Reservation::Reservation(const std::string &res)
    {

        string nospace = res;
        int pos = 0;
        int commapos;
        //setting ID
        string tempID = nospace.substr(0, nospace.find(':', 0) + 1);

        string ID = res.substr(0, res.find(':', 0));
        string IDS = removeWhitespace(ID);

        string abc = nospace.substr(tempID.length());
        strcpy(reservation_id, IDS.c_str());

        for (int i = 0; i < 5; i++)
        {
            commapos = abc.find(',', pos);

            if (i == 0)
            {
                name = removeWhitespace(abc.substr(pos, commapos - pos));
            }
            if (i == 1)
            {
                email = removeWhitespace(abc.substr(pos, commapos - pos));
            }
            if (i == 2)
            {
                numParty = stoi(abc.substr(pos, commapos - pos));
            }
            if (i == 3)
            {
                day = stoi(abc.substr(pos, commapos - pos));
            }
            if (i == 4)
            {
                hour = stoi(abc.substr(pos, commapos - pos));
            }
            pos = commapos + 1;
        }
    }
    std::ostream &operator<<(std::ostream &os, const Reservation &r)
    {
        os << "Reservation " << std::right << std::setw(10) << r.reservation_id << ": ";
        os << std::setw(20) << r.name << "  ";
        os << std::left << std::setw(24) << "<" + r.email + ">";
        if (r.hour >= 6 && r.hour <= 9)
        {
            os << "Breakfast";
        }
        else if (r.hour >= 11 && r.hour <= 15)
        {
            os << "Lunch";
        }
        else if (r.hour >= 17 && r.hour <= 21)
        {
            os << "Dinner";
        }
        else
        {
            os << "Drinks";
        }
        os << " on day " << r.day << " @ " << r.hour << ":00 "
           << "for";
        if (r.numParty == 1)
        {
            os << " 1 person.";
        }
        else
        {
            os << " " << r.numParty << " people.";
        }
        os << std::endl;
        return os;
    }
}
