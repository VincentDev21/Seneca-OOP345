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
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		GeneratingList<EmployeeWage> activeEmp;

		GeneratingList<Employee> E;
		GeneratingList<Salary> S;

		EmployeeWage *employees = nullptr;
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{

					employees = new EmployeeWage(emp[i].name, sal[j].salary);
					try
					{
						employees->rangeValidator();

						if (!E.isValidSIN(emp[i].id))
						{
							throw string("SIN is not Valid");
						}

						if (!S.isValidSIN(sal[j].id))
						{
							throw string("SIN is not Valid");
						}
					}
					catch (const string &)
					{
						delete employees;
						employees = nullptr;
						throw string("*** Employees salaray range is not valid");
					}

					if (employees)
					{
						activeEmp += employees;
					}
					delete employees;
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		GeneratingList<EmployeeWage> activeEmp;

		GeneratingList<Employee> E;
		GeneratingList<Salary> S;

		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{

					std::unique_ptr<EmployeeWage>employees(new EmployeeWage(emp[i].name, sal[j].salary));
					try
					{
						employees->rangeValidator();

						if (!E.isValidSIN(emp[i].id))
						{
							throw string("SIN is not Valid");
						}

						if (!S.isValidSIN(sal[j].id))
						{
							throw string("SIN is not Valid");
						}
					}
					catch (const string &)
					{
						throw string("*** Employees salaray range is not valid");
					}

					if (employees)
					{
						activeEmp += move(employees);
					}
				}
			}
		}
		return activeEmp;
	}
}