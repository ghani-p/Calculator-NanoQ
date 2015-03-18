/* File		: VectorExp.h							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef VECTOREXP_H
#define VECTOREXP_H

#include <iostream>
using namespace std;

const int VECTOR_EMPTY = 0;
const int INDEX_OUT_OF_BOUNDS = 1;

class VectorExp{
public:
	//CTOR-CCTOR
	VectorExp(int);					//ctor
	VectorExp(const VectorExp&);	//cctor
	
	//SERVICES
	void displayMsg() const;
	static int numException();

private:
	static int num_ex;
	static string msg[];
	const int msg_id;
};


#endif