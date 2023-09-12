/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NCC
Date       : 07/23/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool isValidSIN(const std::string &sin)
		{
			int sum = 0;
			bool alternate = false;
			for (int i = sin.length() - 1; i >= 0; --i)
			{
				int digit = sin[i] - '0';
				if (alternate)
				{
					digit *= 2;
					if (digit > 9)
					{
						digit = (digit % 10) + 1;
					}
				}
				sum += digit;
				alternate = !alternate;
			}
			return (sum % 10 == 0);
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		
		void operator+=(const std::unique_ptr<T> obj)
		{
			list.push_back(*obj);
		}
		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T* obj)
		{
			list.push_back(*obj);
		}

		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
