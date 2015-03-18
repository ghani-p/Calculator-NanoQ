/* File		: Romawi.h							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef ROMAWI_H_INCLUDED
#define ROMAWI_H_INCLUDED

#include "../Arab/Arab.h"
#include <string>
using namespace std;
class Romawi:public Arab{
public:
    //ctor
    Romawi();
    Romawi(string A);
    //dtor
    virtual ~Romawi();
    //cctor
    Romawi(const Romawi& R);
    Romawi& operator=(const Romawi& R);
    //overide
    virtual void operator+(const Operand& A);
    virtual void operator-(const Operand& A);
    virtual void operator*(const Operand& A);
    virtual void operator/(const Operand& A);
    virtual void operator%(const Operand& A);
    void ConvertToArab(string R);
    void ConvertToRomawi(int A);
    string getRomawi()const;

private:
    string Nromawi;
};

#endif // ROMAWI_H_INCLUDED
