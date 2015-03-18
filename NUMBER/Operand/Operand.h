/* File		: Operand.h							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef OPERAND_H_INCLUDED
#define OPERAND_H_INCLUDED
#include <cassert>
//Abstract class
class Operand{
public:
    //arabic operators
    virtual void operator+(const Operand& O);
    virtual void operator/(const Operand& O);
    virtual void operator-(const Operand& O);
    virtual void operator*(const Operand& O);
    virtual void operator%(const Operand& O);

    //logical operators
    virtual void operatornot();
    virtual void operatorand(const Operand& O);
    virtual void operatoror(const Operand& O);
    virtual void operatorxor(const Operand& O);
    //pure virtual
    virtual int getNilai()const=0;
};

#endif // OPERAND_H_INCLUDED
