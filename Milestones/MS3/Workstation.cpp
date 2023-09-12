// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"
using namespace std;
namespace sdds
{
    // extern std::deque<CustomerOrder> g_pending;
    // extern std::deque<CustomerOrder> g_completed;
    // extern std::deque<CustomerOrder> g_incomplete;

    // std::deque<CustomerOrder> m_orders;
    // Workstation *m_pNextStation;
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    void Workstation::fill(std::ostream &os)
    {
        if (!m_orders.empty())
        {
            m_orders.front().fillItem(*this, os);
        }
    }
    bool Workstation::attemptToMoveOrder()
    {
        bool flag;
        if (!m_orders.empty())
        {
            if (m_orders.front().isItemFilled(getItemName())|| this->getQuantity() == 0)
            {
                if (m_pNextStation != nullptr)
                {
                    (*m_pNextStation) += move(m_orders.front());
                }
                else
                {
                    if (m_orders.front().isOrderFilled())
                    {
                        g_completed.push_back(std::move(m_orders.front()));
                    }
                    else
                    {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }
                m_orders.pop_front();
                flag = true;
            }
        }
        else
        {
            flag = false;
        }
        return flag;
    }
    void Workstation::setNextStation(Workstation *station)
    {
        m_pNextStation = station;
    }
    Workstation *Workstation::getNextStation() const
    {

        return m_pNextStation;
    }
    void Workstation::display(std::ostream &os) const
    {
        // Nighttable --> Desk
        // Dresser --> Armchair
        // Filing Cabinet --> Bookcase
        // Bookcase --> End of Line
        // Bed --> Dresser
        // Office Chair --> Filing Cabinet
        // Armchair --> Nighttable
        // Desk --> Office Chair
        os << getItemName() << " --> ";
        if (m_pNextStation != nullptr)
        {
            os << m_pNextStation->getItemName();
        }
        else
        {
            os << "End of Line";
        }
        os << endl;
    }
    Workstation &Workstation::operator+=(CustomerOrder &&newOrder)
    {
        m_orders.push_back(move(newOrder));
        return *this;
    }
    
}