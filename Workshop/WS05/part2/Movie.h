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
#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <iostream>

namespace sdds
{
    class Movie
    {
        std::string Title{};
        int year{};
        std::string description{};
        std::string removeWhitespace(const std::string &str);

    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string&  strMovie);
        template<typename T>
        void fixSpelling(T& spellChecker){
            spellChecker(description);
            spellChecker(Title);
        }
        friend std::ostream& operator<<(std::ostream& os, const Movie& M);
    };
}
#endif
