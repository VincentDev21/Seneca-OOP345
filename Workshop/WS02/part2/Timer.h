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
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>

namespace sdds {

class Timer
{
private:
 std::chrono::time_point<std::chrono::system_clock> Start;

 public:
   void start();     
   long long stop(); 
};

} 
#endif // SDDS_TIMER_H