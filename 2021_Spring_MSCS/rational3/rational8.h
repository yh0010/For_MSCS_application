/*  This rational class practice basics of defining and using class.
 */

#ifndef RATIONAL8_H
#define RATIONAL8_H

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

class rational
{
public:
   // TODO: Use default values to reduce 3 constructors to 1 but does the work of 3.
   // Set parameters to appropriate values for a rational equal to 0 when used as default
   // constructor.

   rational(int num=1, int den=1);

   // TODO: Declare an output function that can be used to write to cout or a ofstream.
   //       The format of the rational output is: numerator/denominator.
   //       @param an ostream reference, @returns void
   void outputFunc(ostream& out);

   //TODO: modify Sum method to be a friend function that returns the sum of op1 and op2
   //      @parap op1 is a const rational reference,
   //      @param op2 is a const rational reference, @returns a rational object
   friend rational sumFunc(const rational& op1, const rational& op2);


   //TODO: add Equals to be a friend function that returns comparison of op1 == op2.
   //      @parap op1 is a const rational reference,
   //      @param op2 is a const rational reference, @returns true if equal, false otherwise

   //boolean operator
   friend bool operator ==(const rational& op1, const rational& op2);
   friend bool operator !=(const rational& op1, const rational& op2);
   friend bool operator <(const rational& op1, const rational& op2);
   friend bool operator <=(const rational& op1, const rational& op2);
   friend bool operator >(const rational& op1, const rational& op2);
   friend bool operator >=(const rational& op1, const rational& op2);

   //Arithmetic operator
   friend rational operator +(const rational& op1, const rational& op2);
   friend rational operator -(const rational& op1, const rational& op2); //subtraction
   friend rational operator *(const rational& op1, const rational& op2);
   friend rational operator /(const rational& op1, const rational& op2);
   friend rational operator -(rational& op1); //negation

   //I/O operator
   friend ostream& operator <<(ostream& outs, rational& obj);
   friend void outPut(rational& op1, rational& op2, rational& op3, string symbol);
   friend void outPut2(rational& op1, rational& op2, bool tf, string symbol);
   friend istream& operator >>(istream& ins, rational& obj);

   //other friend function
   friend rational simplified(rational& obj);
private:
   int numerator;
   int denominator;

};

#endif
