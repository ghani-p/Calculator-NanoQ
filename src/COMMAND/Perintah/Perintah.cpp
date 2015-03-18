/* File		: Perintah.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include <iostream>
#include <cstdlib>
#include "Perintah.h"
using namespace std;

Perintah::Perintah(){
	ekspresi = "POSTFIX";
	bilangan = "ARAB";
}

void Perintah::UNDO(int n){
	memory.Undo(n);
}

void Perintah::REDO(int n){
	memory.Redo(n);
}

void Perintah::SHOWMEM(int n){
	memory.ShowMem(n);
}

void Perintah::SHOWALL(){
	memory.ShowAll();
}


void Perintah::SAVE(string file){
	memory.Save(file);
}

void Perintah::SETTING(){
	string input;
	cin >> input;
	while(input != "APPLY"){
		if(input=="PREFIX" || input=="INFIX" || input=="POSTFIX"){
			ekspresi = input;
			cout << "Expresi telah berhasil diset!" << endl;
		} else if(input=="ARAB" || input=="ROMAWI" || input=="LOGIKA"){
			bilangan = input;
			cout << "Bilangan telah berhasil diset!" << endl;
		}
		cin >> input;
	}
}

void Perintah::EXIT(){
	exit(EXIT_SUCCESS);
}

string Perintah::getExpresi(){
	return ekspresi;
}

string Perintah::getBilangan(){
	return bilangan;
}
