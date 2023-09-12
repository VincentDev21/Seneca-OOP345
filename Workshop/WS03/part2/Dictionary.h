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
#ifndef SDDS_DICTIONARY_H_
#define SDDS_DICTIONARY_H_
#include <iostream>

namespace sdds
{
    class Dictionary
    {
        std::string m_term{};
        std::string m_definition{};

    public:
        Dictionary()=default;
        const std::string &getTerm() const { return m_term; }
        const std::string &getDefinition() const { return m_definition; }
        Dictionary(const std::string &term, const std::string &definition) : m_term{term}, m_definition{definition} {}
        
    };
    std::ostream &operator<<(std::ostream &os, const Dictionary &d);
    bool operator==(const Dictionary &left, const Dictionary &right);
}
#endif
