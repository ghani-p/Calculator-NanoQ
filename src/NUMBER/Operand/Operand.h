/* File		: Operand.h							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef OPERAND_H_INCLUDED
#define OPERAND_H_INCLUDED
#include <cassert>
/*! Sebuah kelas abstrak Operand */
class Operand{
public:
    /**
    *fungsi prosedure penjumlahan operand
    * assert untuk operator penjumlahan pada bilangan logika
    * @param O untuk parameter pertama
    */
    virtual void operator+(const Operand& O);
    
    /**
    *fungsi prosedure pembagian operand
    * assert untuk operator pembagian pada bilangan logika
    * @param O untuk parameter pertama
    */
    virtual void operator/(const Operand& O);
    
    /**
    *fungsi prosedure pengurangan operand
    * assert untuk operator pengurangan pada bilangan logika
    * @param O untuk parameter pertama
    */
    virtual void operator-(const Operand& O);
    
    /**
    *fungsi prosedure perkalian operand
    * assert untuk operator perkalian pada bilangan logika
    * @param O untuk parameter pertama
    */
    virtual void operator*(const Operand& O);
    
    /**
    *fungsi prosedure modulo operand
    * assert untuk operator modulo pada bilangan logika
    * @param O untuk parameter pertama
    */
    virtual void operator%(const Operand& O);

    /**
    *fungsi prosedure not operand
    * assert untuk operator not pada bilangan arab
    */
    virtual void operatornot();
    
    /**
    *fungsi prosedure and operand
    * assert untuk operator and pada bilangan arab
    * @param O untuk parameter pertama
    */
    virtual void operatorand(const Operand& O);
    
    /**
    *fungsi prosedure or operand
    * assert untuk operator or pada bilangan arab
    * @param O untuk parameter pertama
    */
    virtual void operatoror(const Operand& O);
    
    /**
    *fungsi prosedure xor operand
    * assert untuk operator xor pada bilangan arab
    * @param O untuk parameter pertama
    */
    virtual void operatorxor(const Operand& O);
    
    /**
    *fungsi get nilai 
    * pure virtual
    */
    virtual int getNilai()const=0;
};

#endif // OPERAND_H_INCLUDED
