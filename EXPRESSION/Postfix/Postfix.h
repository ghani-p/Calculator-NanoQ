/* File		: Postfix.h			*/
/* Author	: Natan (13513070)	*/
#pragma once
#ifndef POSTFIX_H
#define POSTFIX_H
#include "../../NUMBER/Operand/Operand.h"
#include<string>

using namespace std;

class Postfix {
protected:
	string ekspresi; // ekspresi dalam bentuk postfix
	string operandType; //tipe operand yang sedang dikenainya
	Operand *hasil; //hasil '=' perhitungan
	void Hitung(); //melakukan perhitungan berdasarkan ekspresi yang menghasilkan Operand hasil

public:
	Postfix(); //default ctor using operandType="Arab"
	Postfix(string operandType); //ctor
	Postfix(std::string _ekspresi, string operandType); //ctor
	Postfix(const Postfix&); //cctor
	Postfix& operator=(const Postfix&); //assign
	virtual ~Postfix(); //dtor

	//GETTER
	virtual string getEkspresi(); //mengembalikan string ekspresi

	//OUTPUT
	virtual void printEkspresi(); //mencetak string ekspresi ke layar
	virtual void printHasil(); //mencetak nilai Operand hasil ke layar
};

#endif