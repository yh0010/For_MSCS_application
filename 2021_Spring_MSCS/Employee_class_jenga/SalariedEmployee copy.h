//DISPLAY 15.4 Interface for the Derived Class SalariedEmployee
//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"

using namespace std;


    class SalariedEmployee : public Employee
    {
    public:
		// Constructors
        SalariedEmployee( );
        SalariedEmployee (string the_name, string the_ssn,
                                  double the_weekly_salary);

		// Access/Mutator
        double get_salary( ) const;
        void set_salary(double new_salary);

		// Virtual functions
		    virtual double get_net_pay() const;
        virtual void print_check( ) const;
		    virtual istream& promptInput(istream& in, ostream& out);

    private:
        double salary;//weekly
    };


#endif
