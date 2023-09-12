// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H_
#define SDDS_WORKSTATION_H_
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders;
        Workstation *m_pNextStation;

    public:
        Workstation(std::string src) : Station(src) {}
        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station);
        Workstation *getNextStation() const;
        void display(std::ostream &os) const;
        Workstation &operator+=(CustomerOrder &&newOrder);
    };

    
}
#endif