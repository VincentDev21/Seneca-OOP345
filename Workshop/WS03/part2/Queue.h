/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 06/01/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_QUEUE_H_
#define SDDS_QUEUE_H_
#include "Dictionary.h"
#include <iostream>
namespace sdds
{
    template <typename T, size_t CAPACITY>
    class Queue
    {
    private:
        T object[CAPACITY]{};
        static T m_obj;
        size_t number{};

    public:
        virtual ~Queue() = default;
        Queue() = default;
        virtual bool push(const T &item)
        {
            if (number < CAPACITY)
            {
                object[number] = item;
                number++;
                return true;
            }
            else
            {
                return false;
            }
        }
        T pop()
        {
            T temp{};
            temp = object[0];
            for (size_t i = 0; i < number; i++)
            {
                object[i] = object[i + 1];
            }
            number--;
            return temp;
        }

        size_t size() { return number; }
        std::ostream &display(std::ostream &os = std::cout) const
        {
            os << "----------------------" << std::endl;
            os << "| Dictionary Content |" << std::endl;
            os << "----------------------" << std::endl;
            for (size_t i = 0; i < number; i++)
            {
                os << object[i] << std::endl;
            }
            os << "----------------------" << std::endl;
            return os;
        }
        T operator[](size_t data) const
        {
            if (data < number && data >= 0)
            {
                return object[data];
            }
            else
            {
                return m_obj;
            }
        }
    };
    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::m_obj{};
    template <>
    Dictionary Queue<Dictionary, 100u>::m_obj{"Empty Term", "Empty Substitute"};
}
#endif
