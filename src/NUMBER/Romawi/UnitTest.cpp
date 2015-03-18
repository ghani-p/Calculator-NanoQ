/* File		: UnitTest.cpp						*/
/* Author	: Fiqie Ulya Sidiastahta (13513602)	*/
#include "Romawi.h"
#include <iostream>
using namespace std;
int main(){
    Romawi R("II");
    Romawi R2("XX");
    Romawi R3("IX");
    Romawi R4("II");
    Romawi R5("XIII");
    Romawi R6("III");
    R+R2;
    assert(R.getNilai()==22);
    cout<<"BERHASIL operator +"<<endl;
    R-R3;
    assert(R.getNilai()==13);
    cout<<"BERHASIL operator -"<<endl;
    R*R4;
    assert(R.getNilai()==26);
    cout<<"BERHASIL operator *"<<endl;
    R/R5;
    assert(R.getNilai()==2);
    cout<<"BERHASIL operator /"<<endl;
    R%R6;
    assert(R.getNilai()==2);
    cout<<"BERHASIL operator %"<<endl;
	return 0;
}
