/* File		: Logika.cpp						*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#include "Logika.h"
#include <iostream>

Logika::Logika(){
    nilai=0;
}
Logika::Logika(string L){
    //precondition
    assert(L.compare("TRUE")==0 || L.compare("FALSE")==0 || L.compare("0")==0 || L.compare("1")==0 || L.compare("NOTFALSE")==0||L.compare("NOTTRUE")==0||L.compare("NOT0")==0||L.compare("NOT1")==0);
    if((L.compare("TRUE")==0)||(L.compare("1")==0)||(L.compare("NOTFALSE")==0)){
        nilai=1;
    }else nilai=0;

}
Logika::~Logika(){

}
Logika::Logika(const Logika& L){
    nilai=L.getNilai();
}
Logika& Logika::operator=(const Logika& L){
    nilai=L.getNilai();
    return *this;
}
void Logika::operatornot(){
    if(nilai==1)
        nilai=0;
    else nilai=1;
}
void Logika::operatorand(const Operand& O){
    nilai*=O.getNilai();
}
void Logika::operatoror(const Operand& O){
    nilai+=O.getNilai();
    if(nilai==2) nilai=1;
}
void Logika::operatorxor(const Operand& O){
    if(nilai==O.getNilai())
        nilai=0;
    else nilai=1;
}
int Logika::getNilai()const{
    return nilai;
}
