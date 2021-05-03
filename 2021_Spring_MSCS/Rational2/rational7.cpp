#include "rational7.h"
using namespace std;

rational::rational(int num, int den){
  numerator = num;
  denominator = den;
  //left empty on purpose
};

void rational::inputFunc(istream& in){
  int num, den;
  char symbol='.';
  string o;

  in >> num >> symbol >> den;
  while((symbol!='/')||(den==0)){
    cout << "Error: bad rational\n";
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    in >> num >> symbol >> den;
  }
  setBoth(num, den);
};

void rational::outputFunc(ostream& out){
  out << numerator <<'/'<< denominator<<endl;
};

int rational::getNum(rational& obj) const{
  return obj.numerator;
};

int rational::getDen(rational& obj) const{
  return obj.denominator;
};

void rational::setBoth(int num, int den){
  numerator = num;
  denominator = den;
};

rational sumFunc(const rational& op1, const rational& op2){
  // op3.numerator = op1.numerator*op2.denominator + op2.numerator*op1.denominator;
  // op3.denominator = op1.denominator*op2.denominator;
  // cout << op3.numerator << '/' << op3.denominator << endl;
  cout << op1.numerator*op2.denominator + op2.numerator*op1.denominator << '/'
  << op1.denominator*op2.denominator
  << endl;
  return op1;
};

bool operator ==(const rational& op1, const rational& op2){
  return ((float)op1.numerator/(float)op1.denominator) == ((float)op2.numerator/(float)op2.denominator);
};

void outputFunc2(rational op1, rational op2){
  cout << op1.numerator << '/' << op2.denominator <<endl;
};

void get_num(rational op1){
  cout << op1.numerator << endl;
};
void get_den(rational op2){
  cout << op2.denominator << endl;
};
