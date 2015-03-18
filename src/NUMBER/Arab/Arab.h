/* File		: Arab.h							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef ARAB_H_INCLUDED
#define ARAB_H_INCLUDED
#include <string>
#include "../Operand/Operand.h"
#include <stdlib.h>
using namespace std;

class Arab: public Operand{
public:
    //CTOR
    Arab();
    Arab(string a);
    //DTOR
    virtual ~Arab();
    //CCTOR
    Arab(const Arab& A);
    Arab& operator=(const Arab& A);
    //implements parent function
    virtual void operator+(const Operand& A);
    virtual void operator-(const Operand& A);
    virtual void operator*(const Operand& A);
    virtual void operator/(const Operand& A);
    virtual void operator%(const Operand& A);
    //Setter & getter
    virtual void setNilai(int n);
    virtual int getNilai()const;
protected:
    int nilai;
};

#endif // ARAB_H_INCLUDED
