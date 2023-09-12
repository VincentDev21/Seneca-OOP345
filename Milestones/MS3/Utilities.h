// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include <iostream>

namespace sdds
{
    class Utilities{
        size_t m_widthField{ 1u }; 
        static char m_delimiter;
        public:
        
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;

        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

        static void setDelimiter(char newDelimiter);
        static char getDelimiter();

    };
}
#endif