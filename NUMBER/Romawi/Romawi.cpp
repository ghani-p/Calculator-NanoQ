/* File		: Romawi.cpp						*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#include "Romawi.h"
#include <iostream>
using namespace std;
//ctor
Romawi::Romawi(){
    Nromawi="";
}
Romawi::Romawi(string A){
    Nromawi=A;
    ConvertToArab(A);
}
//dtor
Romawi::~Romawi(){

}
//cctor
Romawi::Romawi(const Romawi& R){
    Nromawi=R.Nromawi;
}
Romawi& Romawi::operator=(const Romawi& R){
    Nromawi=R.getRomawi();
    return *this;
}
//overide
void Romawi::operator+(const Operand& A){
    Arab::operator+(A);
    ConvertToRomawi(getNilai());
}
void Romawi::operator-(const Operand& A){
    Arab::operator-(A);
    //postcondition elemen romawi tidak boleh 0 maupun minus '-'
    assert(getNilai()>0);
    ConvertToRomawi(getNilai());
}
void Romawi::operator*(const Operand& A){
    Arab::operator*(A);
    ConvertToRomawi(getNilai());
}
void Romawi::operator/(const Operand& A){
    //Precondition pembagi tidak boleh 0
    assert(A.getNilai()!=0);
    Arab::operator/(A);
    ConvertToRomawi(getNilai());
}
void Romawi::operator%(const Operand& A){
    Arab::operator%(A);
    ConvertToRomawi(getNilai());
}

void Romawi::ConvertToArab(string R){
    int value[7]={1,5,10,50,100,500,1000};
    char CT;

    string Roman= "IVXLCDM";
    int Sum=0;
    CT=Roman[0];
    for(int i=R.size()-1;i>=0;i--){
        assert(Roman.find(R[i]) < Roman.size());
        if(Roman.find(CT)>Roman.find(R[i])){
            Sum-=value[Roman.find(R[i])];
        }
        else{
            Sum+=value[Roman.find(R[i])];
            CT=R[i];
        }

    }
    //postcondition
    assert((Sum<3999)&&(Sum>0));
    nilai=Sum;

}
void Romawi::ConvertToRomawi(int A){
    int value[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int CT=12;
    string Roman[13]= {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string Hasil= "";
    //precondition
    assert((A<3999)&&(A>0));
    while(A>0){
        if((A-value[CT])>=0){
            A-=value[CT];
            Hasil+=Roman[CT];
        }else CT--;
    }
    Nromawi=Hasil;
}
string Romawi::getRomawi()const{
    return Nromawi;
}
