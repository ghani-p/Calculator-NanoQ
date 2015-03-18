/* File		: Infix.h			*/
/* Author	: Natan (13513070)	*/
#pragma once
#ifndef INFIX_H
#define INFIX_H

#include "../Postfix/Postfix.h"
#include<string>

using namespace std;

class Infix : public Postfix {
private:
	string ekspresiP; //ekspresi dalam bentuk infix
	void convertToPost(); //melakukan konversi ekspresi infix ke postfix dan mengupdate string ekspresi (Postfix)

public:
	Infix(string _ekspresi, string _operandType); //default ctor
	Infix(const Infix&); //cctor
	Infix& operator=(const Infix&); //assign
	virtual ~Infix(); //dtor

	//GETTER
	virtual string getEkspresi(); //mengembalikan string ekspresi infix

	//OUTPUT
	virtual void printEkspresi(); //mencetak string ekspresi infix ke layar
};

#endif