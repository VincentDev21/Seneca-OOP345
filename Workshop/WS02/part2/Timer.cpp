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
#include "Timer.h"
#include <chrono>
#include<iostream>
using namespace std;
namespace sdds {
   void Timer::start(){
      Start=std::chrono::system_clock::now();
   }
   long long Timer::stop(){
        std::chrono::time_point<std::chrono::system_clock> Stop =std::chrono::system_clock::now();
       auto nano= std::chrono::duration_cast<std::chrono::nanoseconds>(Stop-Start);
       return nano.count();
   }


} 