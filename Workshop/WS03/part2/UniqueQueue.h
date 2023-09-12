/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/04/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_UNIQUEQUEUE_H_
#define SDDS_UNIQUEQUEUE_H_
#include "Queue.h"
#include <iostream>
#include <cmath>

namespace sdds
{
    template <typename T>
    class UniqueQueue : public Queue<T, 100>
    {
        bool push(const T &item) override
        {
            bool temp = false;
            for (size_t i = 0; i < Queue<T, 100>::size(); i++)
            {

                if (this->operator[](i) == item)
                {
                    temp = true;
                }
            }
            if (temp)
            {
                return false;
            }
            else
            {
                Queue<T, 100>::push(item);
                return true;
            }
        }
    };
    template <>
    bool UniqueQueue<double>::push(const double &item)
    {
        bool temp = false;

        for (size_t i = 0; i < size(); i++)
        {
            if (std::fabs(this->operator[](i) - item) <= 0.005)
            {
                temp=true;
            }
            
        }
        if(temp){
                return false;
            }
            else{
                Queue<double, 100>::push(item);
                return true;
            }
    }
}

#endif