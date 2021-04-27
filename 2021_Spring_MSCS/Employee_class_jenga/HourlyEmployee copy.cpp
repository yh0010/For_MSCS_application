//Implementation for the Derived Class HourlyEmployee
//This is the file: hourlyemployee.cpp
//This is the implementation for the class HourlyEmployee.
//The interface for the class HourlyEmployee is in
//the header file hourlyemployee.h.
#include <string>
#include <iostream>
#include "HourlyEmployee.h"
using namespace std;


HourlyEmployee::HourlyEmployee( ) : Employee( ), wage_rate(0), hours(0)
{
    //deliberately empty
}

HourlyEmployee::HourlyEmployee(string the_name, string the_number,
                               double the_wage_rate, double the_hours)
    : Employee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
{
    //deliberately empty
}

// set_rate() - set the rate
void HourlyEmployee::set_rate(double new_wage_rate)
{
    wage_rate = new_wage_rate;
}

// get_rate() - returns the rate
double HourlyEmployee::get_rate( ) const
{
    return wage_rate;
}

// get_hours() - set the hours
void HourlyEmployee::set_hours(double hours_worked)
{
    hours = hours_worked;
}

// get_hours() - returns the hours
double HourlyEmployee::get_hours( ) const
{
    return hours;
}

// get_net_pay() - return the net_pay calculation
double HourlyEmployee::get_net_pay() const
{
	return hours * wage_rate;
}

// print_check() - print the HourlyEmployee check
void HourlyEmployee::print_check( ) const
{
	Employee::print_check();
    cout << "Hourly Employee. \nHours worked: " << hours
         << " Rate: " << wage_rate << " Pay: " << get_net_pay( ) << endl;
    cout << "_________________________________________________\n";
}

istream & HourlyEmployee::promptInput(istream & in, ostream & out)
{
	Employee::promptInput(in, out);
	out << "Enter hours worked and wage rate: ";
	in >> hours >> wage_rate;
	return in;
}
