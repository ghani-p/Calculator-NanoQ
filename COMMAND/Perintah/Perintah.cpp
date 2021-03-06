/* File		: Perintah.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Perintah.h"
using namespace std;

Perintah::Perintah(){
	ekspresi = "INFIX";
	bilangan = "ARAB";
}

void Perintah::UNDO(int n){
	memory.Undo(n);
	cout << "|| MEMORY || "; memory.ShowMem(1); cout << endl;
}

void Perintah::REDO(int n){
	memory.Redo(n);
	cout << "|| MEMORY || "; memory.ShowMem(1); cout << endl;
}

void Perintah::SHOWMEM(int n){
	memory.ShowMem(n);
}

void Perintah::SHOWALL(){
	memory.ShowAll();
}


void Perintah::SAVE(string file){
	ofstream outputFile;
	outputFile.open (file.c_str());
	outputFile << "Time    : ";
	time_t timev = time(NULL);
	outputFile << asctime(localtime(&timev));
	outputFile << "Setting : " << bilangan << " " << ekspresi << endl << endl;
	memory.Save(file);
}

void Perintah::SETTING(){
	string input = "";
	//cout << "===========================" << endl;
	cout << "List of Available Settings:" << endl;
	cout << "    -Infix  │  Prefix  │  Postfix" << endl;
	cout << "    -Arab   │  Logika  │  Romawi" << endl;
	cout << "    -APPLY" << endl;
	cout << "---------------------------" << endl;
	
	do {
		if(input=="PREFIX" || input=="INFIX" || input=="POSTFIX"){
			ekspresi = input;
			cout << "  Ekspresi telah berhasil diset!" << endl;
		} else if(input=="ARAB" || input=="ROMAWI" || input=="LOGIKA"){
			bilangan = input;
			cout << "  Bilangan telah berhasil diset!" << endl;
		}
		cout << "  >>> ";
		getline(cin,input);
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
	} while (input != "APPLY");
}

void Perintah::EXIT(){
	exit(EXIT_SUCCESS);
}

string Perintah::getEkspresi(){
	return ekspresi;
}

string Perintah::getBilangan(){
	return bilangan;
}

Memori& Perintah::getMemori() {
	return this->memory;
}
