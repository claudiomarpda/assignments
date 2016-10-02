/*
	This c++ program calls assembly functions from "asm.asm" file
	in order to do some bitwise operations.

	@see README.txt for more info.
*/
#include <iostream>

using namespace std;

extern "C" int AndOperation(int a, int b);
extern "C" int OrOperation(int a, int b);
extern "C" int NotOperation(int a);
extern "C" int NegativeNumber(int a); // Negates 'a' and increments 1 to its value

void PrintBits(int x){
	for(int i=31; i>=0; i--){ // 32 bits
		cout <<((x>>i)&1); // shift bits
	}
	cout<<endl;
}

int main(){
	int a = 0;
	int b = 255;
	int c = 0;


	cout<<"--------------------------------" << endl;

	cout<<"a "<< a <<endl;
	PrintBits(a);
	
	cout<<"--------------------------------" << endl;

	cout<<"b "<< b <<endl;
	PrintBits(b);

	cout<<"--------------------------------" << endl;

	cout<<"a AND b"<< endl;
	PrintBits(AndOperation(a,b));

	cout<<"--------------------------------" << endl;

	cout<<"a OR b"<< endl;
	PrintBits(OrOperation(a,b));

	cout<<"--------------------------------" << endl;

	cout<<"NEG INC b" << endl;
	cout<<NegativeNumber(b) << endl;

	cout<<"--------------------------------" << endl;

	cout<<"c "<< c <<endl;
	PrintBits(c);

	cout<<"--------------------------------" << endl;

	cout<<"NOT c"<<endl;
	PrintBits(NotOperation(c));

	cout<<"--------------------------------" << endl;
}