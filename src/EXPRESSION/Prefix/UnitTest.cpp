/* File		: UnitTest.cpp		*/
/* Author	: Natan (13513070)	*/
#include "Prefix.h"
#include <assert.h>

int main(){
	Prefix pre("+ - 2 1 8", "ARAB"); //9
	pre.printEkspresi();
	cout << " = "; pre.printHasil();
	assert(pre.getNilai() == 9);

	Prefix pre1("+ / - * mod 5 4 5 -4 / 60 20 + 1 5", "ARAB");
	pre1.printEkspresi();
	cout << " = "; pre1.printHasil();
	assert(pre1.getNilai() == 9);

	Prefix pre2("or and true false or false true", "LOGIKA"); //1
	pre2.printEkspresi();
	cout << " = "; pre2.printHasil();
	assert(pre2.getNilai() == 1);

	Prefix pre3("- / + - IX VII VI I * II I", "ROMAWI"); //6
	pre3.printEkspresi();
	cout << " = "; pre3.printHasil();
	assert(pre3.getNilai() == 6 && (Romawi)pre3.getRomawi().compare("VI") == 0);
 
	Prefix pre4("+ - * mod 5 4 5 / 60 20 5", "ARAB"); //7
	pre4.printEkspresi();
	cout << " = "; in.printHasil();
	assert(pre4.getNilai() == 7);

	return 0;
}