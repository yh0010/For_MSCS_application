// Add appropriate headers
#include <iostream>
using namespace std;
/*  KEEP THIS COMMENT
* class Rational
*    represents a Rational number. Remember rational means ratio-nal
*    which means there is a numerator and denominator having
*    integer values. Using good ADT techniques, we have made member
*    variable private (also known as instance variables) and made member
*    functions public.
*/
class rational
{
private:
	int numerator;
	int denominator;

public:
	rational();
	rational(int numerator, int denominator);
	rational(int numerator);
	void output();
	void inputFunc();
	int getNumerator();
	int getDenominator();
	void sumFunc(rational obj1, rational obj2);
	// ToDo: Constructor that takes int numerator and int denominator

	// ToDo: Constructor that takes int numerator

	// ToDo: Default Constructor

	// ToDo: Member function to read a rational in the form: n/d

	// ToDo: Member function to write a rational as n/d

	// ToDo: declare an accessor function to get the numerator

	// ToDo: declare an accessor function to get the denominator

	// ToDo: delcare a function called Sum that takes two rational objects
	// sets the current object to the sum of the given objects using the
	// formula: a/b + c/d = ( a*d + b*c)/(b*d)


};


int main()
{
	rational obj, obj2, obj3;
	char answer;
	// obj.output();
	// // ToDo: declare three rational objects using the default constructor
	//
	// obj.inputFunc();
	// obj.output();


	// Main loop to read in rationals and compute the sum

	do {
		cout << "\nEnter op1 (in the format of p/q):";
		obj.inputFunc();
		// ToDo: use your input member function to read the first rational

		cout << "\nEnter op2 (in the format of p/q):";
		obj2.inputFunc();
		// ToDo: use your input member function to read the second rational


		// ToDo: use the third rational to call Sum with first and second as parameters


		cout << "\nThe sum of op1 and op2 is:";
		obj3.sumFunc(obj,obj2);
		obj3.output();
		// ToDo: ouptput the third rational

		cout << endl;

		cout << "\nTry again (Y/N)?";
		cin >> answer;

	} while (answer == 'y' || answer == 'Y');

	// ToDo: test getters
	cout << "\nC's numerator is: " ;
	cout << obj3.getNumerator() <<endl;
	cout << "\nC's denominator is: ";
	cout << obj3.getDenominator() <<endl;

	return 0;
}

rational::rational():numerator(0),denominator(1){
	//left empty//
};

rational::rational(int numerator, int denominator){
	this->numerator = numerator;
	this->denominator = denominator;
};

rational::rational(int numerator):denominator(1){
	this->numerator = numerator;
};

void rational::output(){
	cout << numerator << '/' << denominator;
}

void rational::inputFunc(){
	char slash;
	cin >> numerator >> slash >> denominator;

	if(denominator <= 0){
		cout << "wrong input.\n";
		cout << "Enter a rational (p/q):";
		inputFunc();
	}
};

int rational::getNumerator(){
	return numerator;
};

int rational::getDenominator(){
	return denominator;
}

void rational::sumFunc(rational obj1, rational obj2){
	//a/b + c/d = ( a*d + b*c)/(b*d)
	this->numerator = obj1.numerator*obj2.denominator+obj1.denominator*obj2.numerator;
	this->denominator = obj1.denominator*obj2.denominator;
};
