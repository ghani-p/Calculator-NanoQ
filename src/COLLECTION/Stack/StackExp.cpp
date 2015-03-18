/* File		: StackExp.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include <iostream>
#include "StackExp.h"
using namespace std;

int StackExp::num_ex = 0;
string StackExp::msg[] = {"Stack is empty!", "Stack is full!"};

StackExp::StackExp(int x) : msg_id(x){
	num_ex++;
}

StackExp::StackExp(const StackExp& s) : msg_id(s.msg_id){	
}

void StackExp::displayMsg() const{
	cout << msg[msg_id] << endl;
}

int StackExp::numException(){
	return num_ex;
}