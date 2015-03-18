/* File		: Postfix.h			*/
/* Author	: Natan (13513070)	*/
#pragma once
#ifndef POSTFIX_H
#define POSTFIX_H
#include "../../NUMBER/Operand/Operand.h"
#include<string>

using namespace std;
/*! Sebuah Kelas Postfix */
class Postfix {
protected:
	string ekspresi; /*!ekspresi dalam bentuk postfix*/
	string operandType; /*!tipe operand yang sedang dikenainya*/
	Operand *hasil; /*!hasil '=' perhitungan*/
	void Hitung(); /*!melakukan perhitungan berdasarkan ekspresi yang menghasilkan Operand hasil*/

public:
	/**
    	*Konstruktor default dengan operandType="Arab""
    	*/
	Postfix(); 
	/**
    	*Copy Konstruktor
    	*/
	Postfix(string operandType); 
	/**
	* Konstruktor dengan parameter
    	*@param _ekspresi untuk parameter pertama, operandType untuk parameter kedua
    	*/
	Postfix(std::string _ekspresi, string operandType);
	/**
	* Copy Konstruktor dengan parameter
    	*/
	Postfix(const Postfix&); 
	/**
	* operator=
    	*/
	Postfix& operator=(const Postfix&); 
	/**
	* Destruktor
    	*/
	virtual ~Postfix();

	/**
	* getter
    	*mengembalikan string ekspresi
    	*/
	virtual string getEkspresi(); 
	
	/**
	*getter
    	*mengembalikan hasil operand
    	*/
	virtual Operand* getHasil();

	/**
	*output
    	*mencetak string ekspresi ke layar
    	*/
	virtual void printEkspresi(); 
	/**
	*output
    	*mencetak nilai Operand hasil ke layar
    	*/
	virtual void printHasil(); 
};

#endif
