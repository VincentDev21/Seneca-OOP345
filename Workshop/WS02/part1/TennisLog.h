/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 5/25/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_TENNISLOG_H_
#define SDDS_TENNISLOG_H_
#include <iostream>
namespace sdds
{
    struct TennisMatch
    {
        std::string TournamentID;
        std::string TournamentName;
        int MatchID;
        std::string Winner;
        std::string Loser;
    };
    class TennisLog
    {
    private:
        TennisMatch *tennisMatch;
        size_t  temp_number=0;
        
    public:
        TennisLog();
        TennisLog(const char *filename);
        ~TennisLog();
        void addMatch(TennisMatch &data);
        TennisLog findMatches(std::string name);
        TennisMatch operator[](size_t);
        operator size_t();
    };
    std::ostream &operator<<(std::ostream &os, const TennisMatch &match);

}
#endif
