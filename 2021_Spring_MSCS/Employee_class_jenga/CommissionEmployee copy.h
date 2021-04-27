//#pragma once
#include <iostream>
#include "Employee.h"

#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

class CommissionEmployee : public Employee
{
public:
	// ToDo: declare default constructor for CommissionEmployee
  CommissionEmployee();

	// ToDo: declare constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
  CommissionEmployee(string name, string ssn, double sales, double commission);

	// ToDo: declare Accessor/Mutator functions
  double get_sales() const;
  void set_sales(double new_sales);
  double get_commission ()const;
  void set_commission(double new_commission);

	// ToDo: declare vitual functions to override
  double get_net_pay() const;
  void print_check( ) const;
  istream& promptInput(istream& in, ostream& out);

private:
	// ToDo: declare a sales, commission percent member
  double sales;
  double commission;
};
#endif // _COMMISSION_H
