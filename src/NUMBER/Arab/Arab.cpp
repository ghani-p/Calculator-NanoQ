/* File		: Arab.cpp							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#include "Arab.h"
#include <cassert>
using namespace std;
//ctor
Arab::Arab(){
    nilai=0;
}
Arab::Arab(string a){
    nilai=atoi(a.c_str());
}
//dtor
Arab::~Arab(){

}
//cctor
Arab::Arab(const Arab& A){
    nilai=A.nilai;
}
//operator=
Arab& Arab::operator=(const Arab& A){
    nilai=A.nilai;
    return *this;
}
//Setter & Getter
void Arab::setNilai(int n){
    nilai=n;
}
int Arab::getNilai()const{
    return nilai;
}

void Arab::operator+(const Operand& A){
    nilai+=A.getNilai();
}
void Arab::operator-(const Operand& A){
    nilai-=A.getNilai();
}
void Arab::operator*(const Operand& A){
    nilai*=A.getNilai();
}
void Arab::operator/(const Operand& A){
    assert(A.getNilai()!=0);
    nilai/=A.getNilai();
}
void Arab::operator%(const Operand& A){
    nilai%=A.getNilai();
}
