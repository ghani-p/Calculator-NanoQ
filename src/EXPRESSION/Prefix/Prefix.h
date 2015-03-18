/* File		: Prefix.h			*/
/* Author	: Natan (13513070)	*/
#pragma once
#ifndef PREFIX_H
#define PREFIX_H

#include "../Postfix/Postfix.h"
#include <string>

using namespace std;

class Prefix : public Postfix {
private:
	string ekspresiP; //ekspresi dalam bentuk prefix
	void convertToPost(); //melakukan konversi ekspresi prefix ke postfix dan mengupdate string ekspresi (Postfix)

public:
	Prefix(string _ekspresi, string operandType); //default ctor
	Prefix(const Prefix&); //cctor
	Prefix& operator=(const Prefix&); //assignment
	virtual ~Prefix(); //dtor

	//GETTER
	virtual string getEkspresi(); //mengembalikan string ekspresi prefix

	//OUTPUT
	virtual void printEkspresi(); //mencetak string ekspresi prefix ke layar
};

#endif