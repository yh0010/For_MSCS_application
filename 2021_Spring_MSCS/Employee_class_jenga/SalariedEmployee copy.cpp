//Implementation for the Derived Class SalariedEmployee
//This is the file salariedemployee.cpp.
//This is the implementation for the class SalariedEmployee.
//The interface for the class SalariedEmployee is in
//the header file salariedemployee.h.
#include <iostream>
#include <string>
#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee( ) : Employee( ), salary(0)
{
    //deliberately empty
    //cout <<"SalariedEmployee() called\n";
}

SalariedEmployee::SalariedEmployee(string the_name, string the_number,
                                  double the_weekly_salary)
                     : Employee(the_name, the_number), salary(the_weekly_salary)
{
	//cout <<"SalariedEmployee ("<<the_name <<","<<the_number<<","<<the_weekly_salary<<") called\n";
}

// get_salary() - get the salary
double SalariedEmployee::get_salary( ) const
{
    return salary;
}

// set_salary() - set the salary
void SalariedEmployee::set_salary(double new_salary)
{
    salary = new_salary;
}

// get_net_pay() - return the net_pay calculation
double SalariedEmployee::get_net_pay() const
{
	return salary;
}

// print_check() - print the SalariedEmployee check
void SalariedEmployee::print_check( ) const
{
	Employee::print_check();
    cout << "Salaried Employee. Regular Pay: " << salary << endl;
    cout << "_________________________________________________\n";
}

istream & SalariedEmployee::promptInput(istream & in, ostream & out)
{
	Employee::promptInput(in, out);
	out << "Enter weekly salary: ";
	in >> salary;
	return in;
}
