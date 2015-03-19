/* File		: UnitTest.cpp						*/
/* Author	: Fiqie Ulya Sidiastahta (13513602)	*/
#include "Logika.h"
#include <iostream>
using namespace std;
int main(){
    Logika L1("TRUE");
    Logika L2("FALSE");
    Logika L3("0");
    Logika L4("1");
    Logika L5("NOTTRUE");
    Logika L6("NOTFALSE");

    L1.operatorand(L2);
    assert(L1.getNilai()==0);
    cout<< "OPERATOR AND BERHASIL!"<<endl;
    L3.operatoror(L4);
    assert(L3.getNilai()==1);
    cout<< "OPERATOR OR BERHASIL!"<<endl;
    L5.operatorxor(L6);
    assert(L5.getNilai()==1);
    cout<< "OPERATOR XOR BERHASIL!"<<endl;
	return 0;
}
