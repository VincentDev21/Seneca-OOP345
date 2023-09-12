// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H_
#define SDDS_LINEMANAGER_H_
#include <iostream>
#include <vector>
#include "Workstation.h"

namespace sdds
{
    class LineManager{
        std::vector<Workstation*> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;
        public:
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}
#endif