/*  This rational class practice basics of defining and using class.
 */

#ifndef RATIONAL7_H
#define RATIONAL7_H

//include <sstream> //to read buffer

#include <iostream>
#include <string>
using namespace std;

class rational
{
public:
   // TODO: Use default values to reduce 3 constructors to 1 but does the work of 3.
   // Set parameters to appropriate values for a rational equal to 0 when used as default
   // constructor.

   rational(int num=0, int den=1);

   // TODO: Declare an input function that can be used to read from cin or a ifstream.
   //       The format of the rational input is: numerator/denominator.
   //       @param an istream reference, @returns void
   void inputFunc(istream& in);

   // TODO: Declare an output function that can be used to write to cout or a ofstream.
   //       The format of the rational output is: numerator/denominator.
   //       @param an ostream reference, @returns void
   void outputFunc(ostream& out);

   //TODO: implement the const function that returns the invoking object's numerator
   int getNum(rational& obj) const;


   //TODO: implement the const function that returns the invoking object's denominator
   int getDen(rational& obj) const;


   //TODO: implement a set function that sets both the numerator and denominator. Pay
   // careful attention to error conditions.
   void setBoth(int num, int den);


   //TODO: modify Sum method to be a friend function that returns the sum of op1 and op2
   //      @parap op1 is a const rational reference,
   //      @param op2 is a const rational reference, @returns a rational object
   friend rational sumFunc(const rational& op1, const rational& op2);


   //TODO: add Equals to be a friend function that returns comparison of op1 == op2.
   //      @parap op1 is a const rational reference,
   //      @param op2 is a const rational reference, @returns true if equal, false otherwise
   friend bool operator ==(const rational& op1, const rational& op2);

   friend void outputFunc2(rational op1, rational op2);

   friend void get_num(rational op1);
   friend void get_den(rational op2);




private:
   int numerator;
   int denominator;

};

#endif
