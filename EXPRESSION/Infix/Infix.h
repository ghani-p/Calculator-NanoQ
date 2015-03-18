/* File		: Infix.h			*/
/* Author	: Natan (13513070)	*/
#pragma once
#ifndef INFIX_H
#define INFIX_H

#include "../Postfix/Postfix.h"
#include<string>

using namespace std;
/*! Sebuah kelas abstrak Operand */
class Infix : public Postfix {
private:

	string ekspresiP; /*!< ekspresi dalam bentuk infix */
	void convertToPost(); /*!<melakukan konversi ekspresi infix ke postfix dan mengupdate string ekspresi (Postfix) */

public:
	/**
    	*Konstruktor default
    	*/
	Infix(string _ekspresi, string _operandType); 
	/**
    	*Copy Konstruktor 
    	*/
	Infix(const Infix&);
	/**
    	*Operator=
    	*/
	Infix& operator=(const Infix&); 
	/**
    	*Destruktor
    	*/
	virtual ~Infix();

	/**
	 *getter
	 * mengembalikan string ekspresi infix
    	*/
	virtual string getEkspresi(); 

	/**
	* mencetak string ekspresi infix ke layar
    	*/
	virtual void printEkspresi(); 
};

#endif
