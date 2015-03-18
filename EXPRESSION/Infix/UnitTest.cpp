/* File		: UnitTest.cpp		*/
/* Author	: Natan (13513070)	*/
#include "Infix.h"
#include "../../NUMBER/Romawi/Romawi.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main(){
	Infix inf("2 - 1 + 8", "ARAB"); //9
	inf.printEkspresi();
	cout << " = "; inf.printHasil(); cout << endl;
	assert(inf.getHasil()->getNilai() == 9);

	Infix inf1("(5 mod 4) * 5 - -4 + (60 / 20) / 1 + 5", "ARAB");
	inf1.printEkspresi(); cout << " = "; inf1.printHasil(); cout << endl;
	assert(inf1.getHasil()->getNilai() == 9);

	Infix inf2("(true and false) or (false or true)", "LOGIKA"); //1
	inf2.printEkspresi(); cout << " = "; inf2.printHasil(); cout << endl;
	assert(inf2.getHasil()->getNilai() == 1);

	Infix inf3("IX VII - VI + I / II I * -", "ROMAWI"); //6
	inf3.printEkspresi(); cout << " = "; inf3.printHasil();
	Romawi *R = (Romawi *) inf3.getHasil(); cout << endl;
	assert(inf3.getHasil()->getNilai() == 6 && R->getRomawi().compare("VI") == 0);

	Infix inf4("5 4 mod 5 * 60 20 / - 5 +", "ARAB"); //7
	inf4.printEkspresi(); cout << " = "; inf4.printHasil(); cout << endl;
	assert(inf4.getHasil()->getNilai() == 7);

	cout << endl << "TEST IS SUCCESSFUL!" << endl;

	return 0;
}