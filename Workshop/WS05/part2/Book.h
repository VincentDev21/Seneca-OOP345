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
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>

namespace sdds
{
    class Book
    {
        std::string Author;
        std::string Title;
        std::string Country;
        size_t Year;
        double Price;
        std::string Description;
        std::string removeWhitespace(const std::string &str);

    public:
        Book();
        const std::string &title() const;
        const std::string &country() const;
        const size_t &year() const;
        double& price();
        Book(const std::string &strBook);
        friend std::ostream &operator<<(std::ostream &os, const Book &b);
        template <typename T>
        void fixSpelling(T& spellChecker){
            spellChecker(Description);
        }
    };
}
#endif
