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
#include "SpellChecker.h"
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
namespace sdds
{
    SpellChecker::SpellChecker(const char *filename)
    {
        ifstream _readFile(filename);

        if (!_readFile)
        {
            throw "Bad file name!";
        }
        else
        {
            string _line{""};
            size_t _count{0u};
            int _space{0u};

            while (_count < 6 && getline(_readFile, _line))
            {
                _line.erase(0, _line.find_first_not_of(' '));
                _space = _line.find(' ');
                m_badWords[_count] = _line.substr(0, _space);
                _line.erase(0, _space);

                _line.erase(0, _line.find_first_not_of(' '));
                _space = _line.find(' ');
                m_goodWords[_count] = _line.substr(0, _space);
                ++_count;
            }
        }
    }
    void SpellChecker::operator()(std::string &text)
    {
        for (int i = 0; i < 6; i++)
        {
            unsigned pos = text.find(m_badWords[i]);
            while (pos < text.length())
            {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                pos = text.find(m_badWords[i], pos + m_badWords[i].length());
                ++replace[i];
            }
        }
    }
    void SpellChecker::showStatistics(std::ostream &out) const
    {
        out << "Spellchecker Statistics" << endl;

        for (int i = 0; i < 6; i++)
        {
            out << right << setw(15) << m_badWords[i] << ": ";
            out << replace[i] << " replacements" << endl;
        }
    }
}
