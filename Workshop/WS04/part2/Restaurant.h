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

#ifndef SDDS_RESTAURANT_H_
#define SDDS_RESTAURANT_H_
#include <iostream>
#include "Reservation.h"
namespace sdds
{
    class Restaurant{
         Reservation **ptr{};
        size_t NumReservation{};
        public:
        ~Restaurant();
        Restaurant(const Reservation* reservations[], size_t cnt);
        
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant&other);

        Restaurant(Restaurant&&other);
        Restaurant& operator=(Restaurant&& other);
        size_t size() const;
        friend std::ostream &operator<<(std::ostream &os, const Restaurant &r);

    };
}
#endif
