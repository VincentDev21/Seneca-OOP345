// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
#include <string>
#include <sstream>
using namespace std;

namespace sdds
{
    // size_t m_widthField=1;
    // static char m_delimiter;
    char Utilities::m_delimiter = ' ';

    void Utilities::setFieldWidth(size_t newWidth)
    {
        if (newWidth > 0)
        {
            m_widthField = newWidth;
        }
    }
    size_t Utilities::getFieldWidth() const { return m_widthField; }

    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
    {

        size_t startPos = next_pos;
        size_t endPos = str.find(m_delimiter, next_pos);
        if (startPos == endPos)
        {
            more = false;
            throw "   ERROR: No token.\n";
        }

        else if (endPos == std::string::npos)
        {
            next_pos = std::string::npos;
            more = false;
        }
        else
        {
            next_pos = endPos + 1;
        }

        std::string token = str.substr(startPos, endPos - startPos);
        size_t startOfToken = token.find_first_not_of(" \t\n\r\f\v");
        size_t endOfToken = token.find_last_not_of(" \t\n\r\f\v");

        if (startOfToken != std::string::npos && endOfToken != std::string::npos)
        {
            token = token.substr(startOfToken, endOfToken - startOfToken + 1);
            m_widthField = std::max(token.length(), m_widthField);
        }
        else
        {
            token = "";
            throw "   ERROR: No token.\n";
        }

        return token;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        if (newDelimiter != ' ')
        {
            m_delimiter = newDelimiter;
        }
    }
    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }

}