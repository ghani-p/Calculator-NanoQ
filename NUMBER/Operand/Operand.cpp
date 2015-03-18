/* File		: Operand.cpp							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#include "Operand.h"
#include <iostream>
using namespace std;
//Akan di handel oleh fungsi anak
void Operand::operator+(const Operand& O){
    assert("invalid operator +!");
}
void Operand::operator/(const Operand& O){
    assert("invalid operator /!");
}
void Operand::operator-(const Operand& O){
    assert("invalid operator -!");
}
void Operand::operator*(const Operand& O){
    assert("invalid operator * !");
}
void Operand::operator%(const Operand& O){
    assert("invalid operator % !");
}
void Operand::operatorDiv(const Operand& O){
    assert("invalid operator Div !");
}
void Operand::operatornot(){
    assert("invalid operator not!");
}
void Operand::operatorand(const Operand& O){
    assert("invalid operator and!");
}
void Operand::operatoror(const Operand& O){
    assert("invalid operator or!");
}
void Operand::operatorxor(const Operand& O){
    assert("invalid operator xor!");
}
