/* File		: VectorExp.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include <iostream>
#include "VectorExp.h"
using namespace std;

int VectorExp::num_ex = 0;
string VectorExp::msg[] = {"Vector is empty!", "Index out of bounds!"};


VectorExp::VectorExp(int x) : msg_id(x){
	num_ex++;
}

VectorExp::VectorExp(const VectorExp& s) : msg_id(s.msg_id){	
}

void VectorExp::displayMsg() const{
	cout << msg[msg_id] << endl;
}

int VectorExp::numException(){
	return num_ex;
}