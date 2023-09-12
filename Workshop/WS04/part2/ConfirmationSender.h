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

#ifndef SDDS_CONFIRMATIONSENDER_H_
#define SDDS_CONFIRMATIONSENDER_H_
#include <iostream>
#include "Reservation.h"
namespace sdds
{
    class ConfirmationSender{
        const Reservation**ptr{};
        size_t NumReservation{};
        public:
        ConfirmationSender();
        ~ConfirmationSender();
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream &operator<<(std::ostream &os, const ConfirmationSender &c);
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender& operator=(const ConfirmationSender&other);

        ConfirmationSender(ConfirmationSender&&other);
        ConfirmationSender& operator=(ConfirmationSender&& other);

    };
}
#endif
