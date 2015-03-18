/* File		: UnitTest.cpp						*/
/* Author	: Fiqie Ulya Sidiastahta (13513602)	*/
#include "Arab.h"
#include <iostream>
using namespace std;
int main(){
    Arab A("3");
    Arab A2("4");
    Arab A3("5");
    Arab A4("6");
    Arab A5("7");
    A+A2;
    assert(A.getNilai()==7);
    cout<< "Operator + Berhasil" <<endl;
    A-A3;
    assert(A.getNilai()==2);
    cout<<"Operator - Berhasil"<<endl;
    A*A4;
    assert(A.getNilai()==12);
    cout<<"Operator * Berhasil"<<endl;
    A%A5;
    assert(A.getNilai()==5);
    cout<<"Operator % Berhasil"<<endl;
    A/A;
    assert(A.getNilai()==1);
    cout<<"Operator / Berhasil"<<endl;
	return 0;
}
