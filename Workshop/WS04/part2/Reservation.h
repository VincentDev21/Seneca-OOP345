/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/11/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_RESERVATION_H_
#define SDDS_RESERVATION_H_
#include <iostream>
constexpr int ID_SIZE{11};

namespace sdds
{
    class Reservation
    {
        char reservation_id[ID_SIZE];
        std::string name{};
        std::string email{};
        int numParty{};
        int day{};
        int hour{};

    public:
        Reservation();
        ~Reservation();

        void update(int day, int time);
        Reservation(const std::string &res);
        std::ostream &display(std::ostream &ostr) const;
        friend std::ostream &operator<<(std::ostream &os, const Reservation &R);
        std::string removeWhitespace(const std::string &str);
    };
}
#endif
