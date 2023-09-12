/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 5/28/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include "TennisLog.h"
using namespace std;

namespace sdds
{
    TennisLog::TennisLog()
    {
        tennisMatch = nullptr;
    }
    TennisLog::TennisLog(const char* filename)
    {
        string buffer;
        string temp;
        ifstream file;
        ifstream temp_file;
        int size = 0;
        temp_file.open(filename);
        file.open(filename);
        if (temp_file.is_open())
        {
            getline(temp_file, temp);
            while (getline(temp_file, temp))
            {
                size++;
            }
            temp_file.close();
        }

        tennisMatch = new TennisMatch[size];
        std::getline(file, buffer);
        while (file)
        {
            std::getline(file, buffer, ',');
            if (file)
            {
                tennisMatch[temp_number].TournamentID = buffer;
                std::getline(file, buffer, ',');
                tennisMatch[temp_number].TournamentName = buffer;
                std::getline(file, buffer, ',');
                unsigned long num = 0;
                unsigned long placeValue = 1;

                for (int i = buffer.length() - 1; i >= 0; i--)
                {
                    char digit = buffer[i];

                    if (digit >= '0' && digit <= '9')
                    {
                        num += (digit - '0') * placeValue;
                        placeValue *= 10;
                    }
                    else
                    {
                        break;
                    }
                }
                tennisMatch[temp_number].MatchID = num;
                std::getline(file, buffer, ',');
                tennisMatch[temp_number].Winner = buffer;
                std::getline(file, buffer);
                tennisMatch[temp_number].Loser = buffer;
                temp_number++;
            }
        }

        file.close();
    }

    TennisLog::~TennisLog()
    {
        if (tennisMatch != nullptr)
        {
            delete[] tennisMatch;
            tennisMatch = nullptr;
        }
    }

    TennisLog::TennisLog(const TennisLog& other)
    {
        *this = other;
    }
    TennisLog& TennisLog::operator=(const TennisLog& other)
    {
        if (this != &other) {
            delete[]tennisMatch;
            tennisMatch = nullptr;
            temp_number = other.temp_number;
            tennisMatch = new TennisMatch[temp_number];
            for (size_t i = 0; i < temp_number; i++) {
                tennisMatch[i] = other.tennisMatch[i];
            }
        }
        return *this;
    }
    TennisLog::TennisLog(TennisLog&& other)
    {
        *this = move(other);
    }
    TennisLog& TennisLog::operator=(TennisLog&& other)
    {
        if (this != &other && other.temp_number > 0) {
            delete[]tennisMatch;
            temp_number = other.temp_number;
            tennisMatch = other.tennisMatch;
            other.tennisMatch = nullptr;
            other.temp_number = 0;
        }
        return *this;
    }
    void TennisLog::addMatch(TennisMatch& data)
    {
        TennisMatch* temp;
        temp = new TennisMatch[temp_number];
        for (size_t i = 0; i < temp_number; i++)
        {
            temp[i] = tennisMatch[i];
        }
        delete[] tennisMatch;
        tennisMatch = new TennisMatch[temp_number + 1];
        for (size_t i = 0; i < temp_number; i++)
        {
            tennisMatch[i] = temp[i];
        }
        tennisMatch[temp_number] = data;
        temp_number++;
        delete[] temp;
        temp = nullptr;
    }
    TennisLog TennisLog::findMatches(string name)
    {
        TennisLog temp;
        for (size_t i = 0; i < temp_number; i++)
        {
            if (strcmp(tennisMatch[i].Winner.c_str(), name.c_str()) == 0 || strcmp(tennisMatch[i].Loser.c_str(), name.c_str()) == 0)
            {
                temp.addMatch(tennisMatch[i]);
            }
        }
        return temp;
    }
    TennisMatch TennisLog::operator[](size_t index)
    {
        TennisMatch match;
        if (index < temp_number)
        {
            match = tennisMatch[index];
        }
        return match;
    }
    TennisLog::operator size_t()
    {
        return temp_number;
    }

    std::ostream& operator<<(std::ostream& os, const TennisMatch& match)
    {
        if (match.Winner.empty() || match.Loser.empty() || match.TournamentName.empty() || match.TournamentID.empty() || match.MatchID <= -1)
        {
            os << "Empty Match";
        }
        else
        {

            os << setw(20) << right << setfill('.') << "Tourney ID";
            os << " : ";
            os << setw(30) << left << setfill('.') << match.TournamentID << endl;
            os << setw(20) << right << setfill('.') << "Match ID";
            os << " : ";
            os << setw(30) << left << setfill('.') << match.MatchID << endl;
            os << setw(20) << right << setfill('.') << "Tourney";
            os << " : ";
            os << setw(30) << left << setfill('.') << match.TournamentName << endl;
            os << setw(20) << right << setfill('.') << "Winner";
            os << " : ";
            os << setw(30) << left << setfill('.') << match.Winner << endl;
            os << setw(20) << right << setfill('.') << "Loser";
            os << " : ";
            os << setw(30) << left << setfill('.') << match.Loser << endl;
        }
        return os;
    }

}
