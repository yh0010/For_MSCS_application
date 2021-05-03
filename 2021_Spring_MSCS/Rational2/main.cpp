#include <iostream>
#include "rational7.h"
using namespace std;

int main(){
  //pointer:
  // rational * obj1 = new rational();
  // rational * obj2 = new rational();
  //cooresponding function format:
  // rational sumFunc(rational* op1, rational* op2){
  //   cout << op1->numerator*op2->denominator + op2->numerator*op1->denominator << '/'
  //   << op1->denominator*op2->denominator
  //   << endl;
  //   return *op1;
  // };

//class object:
  rational obj1, obj2;
  char ans;
  do {cout << "Enter op1 (in the format of p/q):\n";
  //obj1->inputFunc(cin);
  obj1.inputFunc(cin);
  cout << "Enter op2 (in the format of p/q):\n";
  //obj2->inputFunc(cin);
  obj2.inputFunc(cin);
  cout << "The sum of op1 and op2 is: ";
  sumFunc(obj1, obj2);
  cout <<endl;
//
  cout << "Test if op1 equals op2: ";
  if(operator ==(obj1, obj2)){
    cout << "op1 equals op2.\n";
  }
  else{
    cout << "op1 does not equal op2.\n";
  }
  cout <<endl;
//
  cout << "Test set member function: ";
  outputFunc2(obj1, obj2);
  cout <<endl;

  cout << "Try again (Y/N)?\n";

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  ans = cin.get();

}
  while (ans == 'Y' || ans == 'y');

  cout << "C's numerator is: ";
  get_num(obj1);
  cout <<endl;

  cout << "C's denominator is: ";
  get_den(obj2);

  rational obj3(3), obj4(4,5);
  obj3.outputFunc(cout);
  obj4.outputFunc(cout);
  return 0;
}
