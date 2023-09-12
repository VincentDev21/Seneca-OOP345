#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
    // struct Item
    // {
    //     std::string m_itemName;
    //     size_t m_serialNumber{0};
    //     bool m_isFilled{false};

    //     Item(const std::string &src) : m_itemName(src){};
    // };
    // std::string m_name;
    // std::string m_product;
    // size_t m_cntItem;
    // Item **m_lstItem;
    // static size_t m_widthField;
    size_t CustomerOrder::m_widthField = 0u;

    CustomerOrder::CustomerOrder() {}
    CustomerOrder::~CustomerOrder()
    {
        if (m_lstItem)
        {
            for (auto i = 0u; i < m_cntItem; ++i)
                delete m_lstItem[i];

            delete[] m_lstItem;
            m_lstItem = nullptr;
        }
    }
    CustomerOrder::CustomerOrder(const std::string &str)
    {
        Utilities util;
        size_t pos = 0;
        bool more = true;
        try
        {
            m_name = util.extractToken(str, pos, more);
            m_product = util.extractToken(str, pos, more);
            m_cntItem = count(str.begin(), str.end(), util.getDelimiter()) - 1;
            if (m_cntItem)
                m_lstItem = new Item *[m_cntItem];
            for (size_t i = 0; i < m_cntItem && more; i++)
            {
                m_lstItem[i] = new Item(util.extractToken(str, pos, more));
            }
            CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
        }
        catch (std::string err)
        {
            cout << err;
        }
    }
    CustomerOrder::CustomerOrder(const CustomerOrder &other)
    {
        throw false;
    }

    CustomerOrder::CustomerOrder(CustomerOrder &&other) noexcept
    {
        *this = move(other);
    }
    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&other) noexcept
    {
        if (this != &other)
        {
            if (m_lstItem)
            {
                for (size_t i = 0; i < m_cntItem; i++)
                {
                    delete m_lstItem[i];
                }
                delete[] m_lstItem;
            }
            m_cntItem = other.m_cntItem;
            m_lstItem = other.m_lstItem;
            m_name = other.m_name;
            m_product = other.m_product;
            other.m_name = "";
            other.m_product = "";
            other.m_lstItem = nullptr;
            other.m_cntItem = 0u;
        }
        return *this;
    }

    bool CustomerOrder::isOrderFilled() const
    {
        bool flag = true;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (!m_lstItem[i]->m_isFilled)
            {
                flag = false;
            }
        }
        return flag;
    }
    bool CustomerOrder::isItemFilled(const std::string &itemName) const
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == itemName)
            {
                if (!m_lstItem[i]->m_isFilled)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void CustomerOrder::fillItem(Station &station, std::ostream &os)
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == station.getItemName())
            {
                if (!m_lstItem[i]->m_isFilled)
                {
                    if (station.getQuantity() > 0)
                    {
                        station.updateQuantity(); // Subtract 1 from inventory
                        m_lstItem[i]->m_isFilled = true;
                        m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                        os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                    }
                    else
                    {
                        os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                    }
                }
                return;
            }
        }
    }

    void CustomerOrder::display(std::ostream &os) const
    {
        os << m_name << " - " << m_product << endl;

        for (auto i = 0u; i < m_cntItem; ++i)
        {
            os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
            os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName;
            os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
        }
    }
}