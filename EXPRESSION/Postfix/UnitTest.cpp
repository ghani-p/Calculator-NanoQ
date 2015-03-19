/* File		: UnitTest.cpp		*/
/* Author	: Natan (13513070)	*/
#include "Postfix.h"
#include "../../NUMBER/Romawi/Romawi.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main(){
	Postfix post("2 1 - 8 +", "ARAB"); //9
	post.printEkspresi();
	cout << " = "; post.printHasil(); cout << endl;
	assert(post.getHasil()->getNilai() == 9);

	Postfix post1("5 4 MOD 5 * -4 - 60 20 / 1 5 + / +", "ARAB");
	post1.printEkspresi(); cout << " = "; post1.printHasil(); cout << endl;
	assert(post1.getHasil()->getNilai() == 9);

	Postfix post2("TRUE FALSE AND FALSE TRUE OR OR", "LOGIKA"); //1
	post2.printEkspresi(); cout << " = "; post2.printHasil(); cout << endl;
	assert(post2.getHasil()->getNilai() == 1);

	Postfix post3("IX VII - VI + I / II I * -", "ROMAWI"); //6
	post3.printEkspresi(); cout << " = "; post3.printHasil();
	Romawi *R = (Romawi *) post3.getHasil(); cout << endl;
	assert(post3.getHasil()->getNilai() == 6 && R->getRomawi().compare("VI") == 0);

	Postfix post4("5 4 MOD 5 * 60 20 / - 5 +", "ARAB"); //7
	post4.printEkspresi(); cout << " = "; post4.printHasil(); cout << endl;
	assert(post4.getHasil()->getNilai() == 7);

	cout << endl << "TEST IS SUCCESSFUL!" << endl;

	return 0;
}