/* File		: Postfix.cpp			*/
/* Author	: Natan (13513070)	*/

#include "../../NUMBER/Arab/Arab.h"
#include "../../NUMBER/Logika/Logika.h"
#include "../../NUMBER/Operand/Operand.h"
#include "../../NUMBER/Romawi/Romawi.h"
#include "../../COLLECTION/Stack/Stack.h"
#include "../../COLLECTION/Vector/Vector.h"
#include "Postfix.h"
#include <iostream>
#include <string>
using namespace std;

Postfix::Postfix() { //default ctor
	ekspresi = "";
	hasil = 0;
	operandType = "ARAB";
}

Postfix::Postfix(string _operandType) { //ctor
	ekspresi = "";
	hasil = 0;
	operandType = _operandType;
}


Postfix::Postfix(string _ekspresi, string _operandType) { //ctor
	ekspresi = _ekspresi;
	operandType = _operandType;
	this->Hitung();
}


Postfix::Postfix(const Postfix& P) { //cctor
	this->ekspresi = P.ekspresi;
	this->hasil = P.hasil;
}


Postfix& Postfix::operator=(const Postfix& P) { //assign
	this->ekspresi = P.ekspresi;
	this->hasil = P.hasil;
	return *this;
}


Postfix::~Postfix() { //dtor
	delete hasil;
	hasil = NULL;
}


void Postfix::Hitung() {
//melakukan perhitungan berdasarkan ekspresi yang menghasilkan Operand hasil
	Stack<Operand*> tabEkspresi;
	Operand* temp;

	Vector<string> strings;
	int x=0;
	for (int i=1; i<ekspresi.length(); i++) {
		if (ekspresi[i] == ' ') {
			string s = ekspresi.substr(x,i-x);
			strings.push_back(s);
			x = i+1;
		}
	}
	if (ekspresi.length() > 0)
		strings.push_back(ekspresi.substr(x, ekspresi.length()-1));

	for (int i=0;i<strings.size();i++) {
		if (strings[i].compare("+") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			tabEkspresi.top()->operator+(*temp);
		} else if (strings[i].compare("-") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()) - (*temp);
		} else if (strings[i].compare("*") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()) * (*temp);
		} else if (strings[i].compare("/") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()) / (*temp);

		} else if (strings[i].compare("div") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()) / (*temp);
		} else if (strings[i].compare("mod") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()) % (*temp);
		} else if (strings[i].compare("and") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()).operatorand((*temp));
		} else if (strings[i].compare("or") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()).operatoror((*temp));
		} else if (strings[i].compare("xor") == 0) {
			temp = tabEkspresi.top();
			tabEkspresi.pop();
			(*tabEkspresi.top()).operatorxor((*temp));
		} else {
			//Memasukkan operand ke dalam stack
			if (operandType == "ARAB") {
				tabEkspresi.push(new Arab(strings[i]));
			} else if (operandType == "ROMAWI") {
				tabEkspresi.push(new Romawi(strings[i]));
			} else if (operandType == "LOGIKA") {
				tabEkspresi.push(new Logika(strings[i]));
			}
			
		}
	}
	hasil = tabEkspresi.top();
}

Operand* Postfix::getHasil() {
	return hasil;
}

string Postfix::getEkspresi() { return ekspresi; } //mengembalikan string ekspresi postfix


void Postfix::printEkspresi() { cout<<getEkspresi();} //mencetak string ekspresi ke layar


void Postfix::printHasil() {
//mencetak nilai Operand hasil ke layar
	if (operandType == "ROMAWI") {
		Romawi *R = (Romawi *) hasil;
		cout << R->getRomawi();
	} else {
		cout << hasil->getNilai();
	}
}