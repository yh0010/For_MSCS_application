//DISPLAY 15.7 Using Derived Classes
#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"
#include "CommissionEmployee.h"
#include <vector>
using namespace std;

// payday function - using vector of pointers
void paydayPtrs(const vector<Employee*>& employeePtrs);

// payday function - using vector of pointers
void paydaySlices(const vector<Employee>& employeeSlices);

int main( )
{
  vector<Employee*> employeePtrs;
  vector<Employee> employeeSlices;
	int numberEmployees;

	cout << "Welcome to ABC Corporation!!\n";
	cout << "Enter the number of employees: ";
	cin >> numberEmployees;

	// Enter the number of employees
	for (int i=0; i<numberEmployees; i++)
    {
		cout <<"Enter employee #"<<(i+1)<<":\n";
		string type;
        cout <<"Enter the type of employee (hourly, salaried, admin, commission):";
        cin >> type;

		// Request an hourly employee
		if (type=="hourly")
		{
			// Construct an HourlyEmployee
			HourlyEmployee * hourly = new HourlyEmployee();

			// Prompt for input
			hourly->promptInput(cin, cout);

			// Store in the vectors
			employeePtrs.push_back(hourly);
			employeeSlices.push_back(*hourly);
		}
		else if (type=="salaried")
		{
			// Construct a SalariedEmployee
			SalariedEmployee * mgmt = new SalariedEmployee();

			// Prompt for input
			mgmt->promptInput(cin, cout);

			// Add to the lists
			employeePtrs.push_back(mgmt);
			employeeSlices.push_back(*mgmt);
		}
		else if (type =="admin")
		// Construct an Administrator
		{
      Administrator * ad = new Administrator();
   			//ToDo: Test your Administrator class here...


			//ToDo: prompt for input
      ad->promptInput(cin,cout);

			//ToDo: Add to the lists as above
      employeePtrs.push_back(ad);
			employeeSlices.push_back(*ad);
		}
		else if (type == "commission")
		{
			//ToDo: Test your Commission class here...
      CommissionEmployee * com = new CommissionEmployee();

			//ToDo: prompt for input
      com->promptInput(cin, cout);

			//ToDo: Add to the lists as above
      employeePtrs.push_back(com);
			employeeSlices.push_back(*com);
		}

   }

	// Print pointers
	paydayPtrs(employeePtrs);
	paydaySlices(employeeSlices);

    //ToDo: free up dynamically allocated memory
    for (int i =0; i< employeePtrs.size();i++)
   {
     delete (employeePtrs[i]);
   }
   employeePtrs.clear();

    return 0;
}

//Payday!
void paydaySlices(const vector<Employee>& employeeSlices)
{
   cout <<"***********************************************\n";
   cout <<"Payday Slices! Print all checks in a batch!\n";
   for (int i=0;i<employeeSlices.size();i++)

   {
   		cout << "Slice Check for " << employeeSlices[i].get_name() << endl;
   		employeeSlices[i].print_check( );
   		cout << endl;
   }
}
//Payday!
void paydayPtrs(const vector<Employee*>& employeePtrs)
{
   cout <<"***********************************************\n";
   cout <<"Payday Virtual! Print all checks in a batch!\n";
   for (int i=0;i<employeePtrs.size();i++)
   {
   		cout << "Virtual Check for " << employeePtrs[i]->get_name() << endl;
   		employeePtrs[i]->print_check( );
   		cout << endl;
   }
}
