// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"
#include "Utilities.h"
#include <iomanip>
#include <string>

using namespace std;

namespace sdds
{
    // int station_id;
    // std::string name;
    // std::string desc;
    // size_t serial_num;
    // size_t inStock;
    // static size_t m_widthField{}
    // static size_t id_generator{}
    size_t Station::m_widthField = 0u;
    size_t Station::id_generator = 0u;

    Station::Station(const std::string &str)
    {
        Utilities util;
        size_t pos = 0;
        bool more = true;
        station_id = ++id_generator;
        try
        {
            name = util.extractToken(str, pos, more);
            serial_num = stoi(util.extractToken(str, pos, more));
            inStock = stoi(util.extractToken(str, pos, more));
            Station::m_widthField = max(util.getFieldWidth(),Station::m_widthField);
            desc = util.extractToken(str, pos, more);
            
        }
        catch (std::string err)
        {
            cout << err;
        }
    }
    const std::string &Station::getItemName() const
    {
        return name;
    }
    size_t Station::getNextSerialNumber()
    {
        serial_num++;
        return serial_num-1;
    }
    size_t Station::getQuantity() const
    {
        return inStock;
    }
    void Station::updateQuantity()
    {
        if (inStock != 0)
        {
            inStock--;
        }
        else
        {
            inStock = 0;
        }
    }

    // int station_id;
    // std::string name;
    // std::string desc;
    // size_t serial_num;
    // size_t inStock;
    void Station::display(std::ostream &os, bool full) const
    {
        os << std::right << std::setfill('0')<< std::setw(3) << station_id << " | ";
        os << std::left<< std::setfill(' ') << std::setw(m_widthField) << name << " | ";
        os << std::right << std::setw(6) << std::setfill('0') << serial_num << " | ";

        if (full)
        {
            os << std::right << std::setw(4) << std::setfill(' ') << inStock << " | ";
            os << desc;
        }

        os << std::endl;
    }
}