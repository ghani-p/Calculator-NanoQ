/* File		: Prefix.h			*/
/* Author	: Natan (13513070)	*/
#pragma once
#ifndef PREFIX_H
#define PREFIX_H

#include "../Postfix/Postfix.h"
#include <string>

using namespace std;
/*! Sebuah kelas Prefix turunan kelas Postfix */
class Prefix : public Postfix {
private:
	string ekspresiP; /*!ekspresi dalam bentuk prefix*/
	void convertToPost(); /*!melakukan konversi ekspresi prefix ke postfix dan mengupdate string ekspresi (Postfix)*/

public:
	/**
    	*Konstruktor default
    	*/
	Prefix(string _ekspresi, string operandType); 
	/**
    	*Copy Konstruktor
    	*/
	Prefix(const Prefix&); 
	/**
	* operator=
    	*/
	Prefix& operator=(const Prefix&); 
	/**
	* Destruktor
    	*/
	virtual ~Prefix();

	/**
	* getter
    	*mengembalikan string ekspresi prefix
    	*/
	virtual string getEkspresi(); 

	/**
	*output
    	*mencetak string ekspresi prefix ke layar
    	*/
	virtual void printEkspresi(); 
};

#endif
