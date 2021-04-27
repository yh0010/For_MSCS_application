/* Implement Administrator class */
#include <iostream>
#include "Administrator.h"

using namespace std;

// ToDo: implement the default constructor, remember to call base class constructor
Administrator::Administrator():SalariedEmployee(){}

// ToDo: implement the constructor, remember to call base class constructor
Administrator::Administrator(string name, string ssn, double salary, string title):SalariedEmployee(name, ssn, salary), title("no title yet")

{
	// deliberately empty
	// cout << "Administrator(" << name << "," << SSN << "," << salary << "," << title << ")\n";
}

// ToDo: implement accessor/mutators
string Administrator::get_title() const{
  return title;
}

void Administrator::set_title(string new_title){
  title = new_title;
}

double Administrator::get_bonus() const{
    return bonus;
};
void Administrator::set_bonus(double new_bonus){
    bonus = new_bonus;
};
// ToDo: implement virtual functions
// ToDo: implement virtual get_net_pay function
// Hint: compensation is salary + bonus
double Administrator::get_net_pay() const{
  double pay = SalariedEmployee::get_salary()+bonus;
  return pay;
};

// ToDo: implement the print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void Administrator::print_check() const
{
	//????cout << "Administrator::print_check() not implemented" << endl;????
  //Employee::print_check();
  SalariedEmployee::print_check();
  // Administrator Title: Sr. Executive V.P.
  // Bonus: 25000 Pay: 54765

  cout << "Administrator Title: " << get_title() << endl;
  cout << "Bonus: " << get_bonus() << ' ' << "Pay: " << get_net_pay() << endl;
  cout << "_________________________________________________\n";
}

// ToDo: implement the promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream & Administrator::promptInput(istream & in, ostream & out)
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
  //Employee::promptInput(in, out);
  SalariedEmployee::promptInput(in, out);
	// ToDo: read the bonus. Use ignorespace() to skip newline.
  out << "Enter bonus and title: ";
  //std::getline(in, bonus);
  in >> bonus;
  ignorespace(in);
  getline(in, title);//???really work
  return in;

	// ToDo: read the rest of the line for the title


}
//const?
//"" > ' '?
