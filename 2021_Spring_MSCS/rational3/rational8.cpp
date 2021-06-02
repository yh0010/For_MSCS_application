#include "rational8.h"
using namespace std;

rational::rational(int num, int den){
  numerator = num;
  denominator = den;
};

void rational::outputFunc(ostream& out){
	if (numerator>0){
		out << '-'<<'('<<'-'<<numerator <<'/'<< denominator<<')' << '=' << numerator <<'/'<< denominator<<endl;
	}
	else{
		out << '-'<<'('<<-numerator <<'/'<< denominator<<')'<< '=' << numerator <<'/'<< denominator << endl;
	}
};

bool operator ==(const rational& op1, const rational& op2){
  return ((float)op1.numerator/(float)op1.denominator) == ((float)op2.numerator/(float)op2.denominator);
};

bool operator !=(const rational& op1, const rational& op2){
	return ((float)op1.numerator/(float)op1.denominator) != ((float)op2.numerator/(float)op2.denominator);
};
bool operator <(const rational& op1, const rational& op2){
	return ((float)op1.numerator/(float)op1.denominator) < ((float)op2.numerator/(float)op2.denominator);
};
bool operator <=(const rational& op1, const rational& op2){
	return ((float)op1.numerator/(float)op1.denominator) <= ((float)op2.numerator/(float)op2.denominator);
};
bool operator >(const rational& op1, const rational& op2){
	return ((float)op1.numerator/(float)op1.denominator) > ((float)op2.numerator/(float)op2.denominator);
};
bool operator >=(const rational& op1, const rational& op2){
	return ((float)op1.numerator/(float)op1.denominator) >= ((float)op2.numerator/(float)op2.denominator);
};

//Arithmetic operator
rational operator +(const rational& op1, const rational& op2){
	rational op3;
	op3.numerator = op1.numerator*op2.denominator+op1.denominator*op2.numerator;
	op3.denominator = op1.denominator*op2.denominator;
	return op3;
};
rational operator -(const rational& op1, const rational& op2){
	rational op3;
	op3.numerator = op1.numerator*op2.denominator-op1.denominator*op2.numerator;
	op3.denominator = op1.denominator*op2.denominator;
	if (op3.numerator < 0){ op3.numerator *= -1;};
	return op3;
}; //subtraction
rational operator *(const rational& op1, const rational& op2){
	rational op3;
	op3.numerator = op1.numerator*op2.numerator;
	op3.denominator = op1.denominator*op2.denominator;
	return op3;
};
rational operator /(const rational& op1, const rational& op2){
	rational op3;
	op3.numerator = op1.numerator*op2.denominator;
	op3.denominator = op2.numerator*op1.denominator;
	return op3;
};
rational operator -(rational& op1){
	op1.numerator *= -1;
	return op1;
}; //negation

//I/O operator
void outPut(rational& op1, rational& op2, rational& op3, string symbol){
	simplified(op1);
	simplified(op2);
	simplified(op3);
	cout << '('<<op1<<')' << symbol << '('<<op2<<')' << '=' << op3 <<endl;
};
void outPut2(rational& op1, rational& op2, bool tf, string symbol){
	string TF;
	if(tf==0){TF="False";}else{TF="True";}
	cout << '('<<op1<<')' << symbol << '('<<op2<<')' << '=' << TF <<endl;
};
ostream& operator <<(ostream& outs, rational& obj){
	outs << obj.numerator << '/'<< obj.denominator;
	return outs;
};
istream& operator >>(istream& ins, rational& obj){
	char slash;
	string input;
	ins >> input;
	int pos = input.find('.');
	if (pos!=-1){
		if (input.find('/')!=-1){ins.setstate(ios::failbit);}
		else{
		string dotRight = input.substr(pos+1,  (input.length() -1));
		string dotLeft = input.substr(0, pos);
		obj.numerator = stoi(dotRight);
		if (dotRight.length()==1){
			obj.denominator = 10;}
		if (dotRight.length()==2){
			obj.denominator = 100;
		}
		if (dotLeft.find('1')!=-1){
			obj.numerator += obj.denominator;
		}
		if (dotLeft.find('-')!=-1){
			obj.numerator *= -1;
		}
	}
}
	else{
		int pos2 = input.find('-');
		if (pos2!=-1){
			if(pos2!=0||isdigit(input[1])==0){
				ins.setstate(ios::failbit);}
			else{
			obj.numerator = stoi(input.substr(0,2));
			obj.denominator = stoi(input.substr(input.find('/')+1,input.length()-1));
			}
		}
		else{
			obj.numerator = stoi(input.substr(0,1));
			obj.denominator = stoi(input.substr(input.find('/')+1,(input.length()-1)));
		}
	}
		return ins;
};

//other friend function
rational simplified(rational& obj){
	rational obj4 = obj;
	while(obj4.numerator != obj4.denominator){
		if (obj4.numerator<0){obj4.numerator *= -1;}
		if (obj4.numerator > obj4.denominator){
		obj4.numerator -= obj4.denominator;
	}
		else {
		obj4.denominator -= obj4.numerator;
	}
}
	obj.numerator /= obj4.numerator;
	obj.denominator /= obj4.denominator;

	return obj;
}
