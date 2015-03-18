/* File		: StackExp.h							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef STACKEXP_H
#define STACKEXP_H

#include <iostream>
using namespace std;

const int STACK_EMPTY = 0;
const int STACK_FULL = 1;

class StackExp{
public:
	//CTOR-CCTOR
	StackExp(int); 				//ctor
	StackExp(const StackExp&);	//cctor
	
	//SERVICES
	void displayMsg() const;
	static int numException();

private:
	static int num_ex;
	static string msg[];
	const int msg_id;
};


#endif