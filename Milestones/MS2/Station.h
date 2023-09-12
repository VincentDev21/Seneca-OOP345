#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_
#include <iostream>

namespace sdds
{
    class Station
    {
        int station_id;
        std::string name;
        std::string desc;
        size_t serial_num;
        size_t inStock;
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const std::string &str);
        const std::string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &os, bool full) const;
    };
}
#endif