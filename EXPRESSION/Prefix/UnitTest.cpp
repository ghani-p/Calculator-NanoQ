/* File		: UnitTest.cpp		*/
/* Author	: Natan (13513070)	*/
#include "Prefix.h"
#include "../../NUMBER/Romawi/Romawi.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main(){
	Prefix pre("+ - 2 1 8", "ARAB"); //9
	pre.printEkspresi();
	cout << " = "; pre.printHasil(); cout << endl;
	assert(pre.getHasil()->getNilai() == 9);

	Prefix pre1("+ / - * MOD 5 4 5 -4 / 60 20 + 1 5", "ARAB");
	pre1.printEkspresi(); cout << " = "; pre1.printHasil(); cout << endl;
	assert(pre1.getHasil()->getNilai() == 9);

	Prefix pre2("OR AND TRUE FALSE OR FALSE TRUE", "LOGIKA"); //1
	pre2.printEkspresi(); cout << " = "; pre2.printHasil(); cout << endl;
	assert(pre2.getHasil()->getNilai() == 1);

	Prefix pre3("- / + - IX VII VI I * II I", "ROMAWI"); //6
	pre3.printEkspresi(); cout << " = "; pre3.printHasil();
	Romawi *R = (Romawi *) pre3.getHasil(); cout << endl;
	assert(pre3.getHasil()->getNilai() == 6 && R->getRomawi().compare("VI") == 0);
 
	Prefix pre4("+ - * MOD 5 4 5 / 60 20 5", "ARAB"); //7
	pre4.printEkspresi(); cout << " = "; pre4.printHasil(); cout << endl;
	assert(pre4.getHasil()->getNilai() == 7);

	cout << endl << "TEST IS SUCCESSFUL!" << endl;

	return 0;
}