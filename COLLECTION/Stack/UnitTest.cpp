/* File		: UnitTest.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include "Stack.h"
#include "StackExp.h"

int main(){
	string input;
	Stack<string> s;
	int i;
	
	cout << "Test Stack" << endl;
	do{
		cout << "Input Anda : ";
		cin >> input;
		if(input != "EXIT"){
			s.push(input);
		}
	}while(input != "EXIT");
	cout << "Stack Anda sekarang: " << endl;
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
