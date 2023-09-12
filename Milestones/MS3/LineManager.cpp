// Name: Vincent Le
// Seneca Student ID: 1311117228
// Seneca email: vle21@myseneca.ca
// Date of completion: 8/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"
#include "Utilities.h"
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
namespace sdds
{
    // std::vector<Workstation*> m_activeLine;
    // size_t m_cntCustomerOrder;
    // Workstation* m_firstStation;

    LineManager::LineManager(const std::string &file, const std::vector<Workstation *> &stations)
    {
        Utilities util;

        string line;
        ifstream fp(file);
        // c_station = current station
        // n_station = next station
        // std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        std::vector<string> c_station, n_station;
        if (!fp.is_open())
        {
            throw string("\n***Failed to open file ") + string(file) + string(" ***\n");
        }
        else
        {
            while (getline(fp, line))
            {
                size_t pos = 0;
                bool more = true;
                if (!line.empty())
                {
                    string current;
                    string next;
                    current = util.extractToken(line, pos, more);
                    c_station.push_back(current);
                    if (!more)
                    {
                        n_station.push_back("");
                    }
                    else
                    {
                        next = util.extractToken(line, pos, more);
                        n_station.push_back(next);
                    }

                    Workstation *curWorkstation = nullptr;
                    Workstation *nextWorkstation = nullptr;
                    for_each(stations.begin(), stations.end(), [&curWorkstation, &nextWorkstation, current, next](Workstation *ws)
                             {
                    if (ws->getItemName() == current) {
                        curWorkstation = ws;
                    }
                    else if (ws->getItemName() == next) {
                        nextWorkstation = ws;
                    } });

                    if (m_activeLine.size() == 0)
                    {
                        m_firstStation = curWorkstation;
                    }

                    curWorkstation->setNextStation(nextWorkstation);
                    m_activeLine.push_back(curWorkstation);
                }
            }
            fp.close();
            m_cntCustomerOrder = g_pending.size();
        }
    }
    void LineManager::reorderStations()
    {
        vector<Workstation *> newStations;
        Workstation *lastStation = nullptr;
        unsigned int count = 0;
        while (count < m_activeLine.size())
        {
            for (unsigned int i = 0; i < m_activeLine.size(); i++)
            {
                if (m_activeLine[i]->getNextStation() == lastStation)
                {
                    newStations.push_back(m_activeLine[i]);
                    lastStation = m_activeLine[i];
                    count++;
                    break;
                }
            }
        }
        reverse(newStations.begin(), newStations.end());
        m_firstStation = newStations[0];
        m_activeLine = newStations;
    }
    bool LineManager::run(std::ostream &os)
    {
        static unsigned int count = 0;
        count++;

        os << "Line Manager Iteration: " << count << std::endl;

        if (!g_pending.empty())
        {
            auto &frontLine = *m_activeLine.front();
            frontLine += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto &source : m_activeLine)
        {
            source->fill(os);
        }
        for (auto &source : m_activeLine)
        {
            source->attemptToMoveOrder();
        }

        return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());

    }
    void LineManager::display(std::ostream &os) const
    {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *src)
                 { src->display(os); });
    }
}