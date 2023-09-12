#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds
{
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee> &emp, const GeneratingList<Salary> &sal)
	{
		GeneratingList<EmployeeWage> activeEmp;

		GeneratingList<Employee> E;
		GeneratingList<Salary> S;

		EmployeeWage *employees = nullptr;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
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
}

