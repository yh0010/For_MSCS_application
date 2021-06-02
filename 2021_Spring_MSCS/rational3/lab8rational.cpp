
#include <cstdlib>
//#include <vector>
#include <fstream>
#include "rational8.h"

using namespace std;


//main program
int main ()
{
	cout << "Welcome to Rational World!" <<endl;
	cout << endl;

  rational obj1, obj2, obj3;
  char rerun;
  string symbol;
  bool tf;
	do{
    cout << "Enter operator (+,-,*,/,==,>=,<=,!=,<,>,-1 for negation): ";
    cin >> symbol;
    if(symbol.length()<=2){
      if (symbol=="-1"){
        cout << "Enter the operand (ex. 1/2 or -3/4): ";
        cin >> obj3;
        if(cin.good()){
          obj3 = -obj3;
          obj3.outputFunc(cout);
        }
      }else {
        cout << "Enter the two operands (ex. 1/2 or -3/4): ";
        cin >> obj1 >> obj2;
        if (symbol=="+"){
          obj3 = obj1+obj2; //overloading begin
          outPut(obj1, obj2, obj3, symbol);
        }
        if (symbol=="-"){
          obj3 = obj1-obj2;
          outPut(obj1, obj2, obj3, symbol);
        }
        if (symbol=="*"){
          obj3 = obj1*obj2;
          outPut(obj1, obj2, obj3, symbol);
        }
        if (symbol=="/"){
          obj3 = obj1/obj2;
          outPut(obj1, obj2, obj3, symbol);
        }
        if (symbol==">="){
          tf = obj1>=obj2;
          outPut2(obj1, obj2, tf, symbol);
        }
        if (symbol=="<="){
          tf = obj1<=obj2;
          outPut2(obj1, obj2, tf, symbol);
        }
        if (symbol=="!="){
          tf = obj1!=obj2;
          outPut2(obj1, obj2, tf, symbol);
        }
        if (symbol=="<"){
          tf = obj1<obj2;
          outPut2(obj1, obj2, tf, symbol);
        }
        if (symbol==">"){
          tf = obj1>obj2;
          outPut2(obj1, obj2, tf, symbol);
        }
        if (symbol=="=="){
        tf = obj1==obj2;
        outPut2(obj1, obj2, tf, symbol);
      }
    }
  		if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid rational format!\n";
        cout << "-(0/1)=0/1\n";
		}}
    else{
    cout << "Invalid operator!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');}

		// ToDo: Prompt the user to rerun the simulation
		cout << "Continue(y/n): \n";
		cin >> rerun;

	} while (rerun == 'y'|| rerun == 'Y');

	cout << "Have a nice day!" <<endl;

	return 0;
}
