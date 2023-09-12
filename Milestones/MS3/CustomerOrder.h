// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H_
#define SDDS_CUSTOMERORDER_H_
#include <iostream>
#include "Station.h"

namespace sdds
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };
    class CustomerOrder
    {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item **m_lstItem{};
        static size_t m_widthField;

    public:
        CustomerOrder();
        ~CustomerOrder();
        CustomerOrder(const std::string &str);
        CustomerOrder(const CustomerOrder &other);

        CustomerOrder &operator=(const CustomerOrder &other) = delete;
        CustomerOrder(CustomerOrder &&src) noexcept;
        CustomerOrder &operator=(CustomerOrder &&src) noexcept;

        bool isOrderFilled()const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;
    };
}
#endif