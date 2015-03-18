/* File		: Arab.h							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef ARAB_H_INCLUDED
#define ARAB_H_INCLUDED
#include <string>
#include "../Operand/Operand.h"
#include <stdlib.h>
using namespace std;

/*! Sebuah kelas Arab turunan dari kelas operand */
class Arab: public Operand{
public:
    /**
    *Konstruktor tanpa parameter
    */
    Arab();
    
    /**
    *Konstruktor dengan parameter
    *string input berupa string representasi integer
    *menyimpan kedalam variabel nilai nilai integer dari string yang di input
    *@param a untuk parameter pertama
    */
    Arab(string a);
    
    /**
    *Destruktor
    */
    virtual ~Arab();
    
    /**
    *Copy Konstruktor
    *@param A untuk parameter pertama
    */
    Arab(const Arab& A);
    
    /**
    *Operator=
    *@param A untuk parameter pertama
    */
    Arab& operator=(const Arab& A);
    
    /**
    *fungsi prosedur penjumlahan override dari fungsi Operand
    *@param A untuk parameter pertama
    */
    virtual void operator+(const Operand& A);
    
    /**
    *fungsi prosedur pengurangan override dari fungsi Operand
    *@param A untuk parameter pertama
    */
    virtual void operator-(const Operand& A);
    
    /**
    *fungsi prosedur perkalian override dari fungsi Operand
    *@param A untuk parameter pertama
    */
    virtual void operator*(const Operand& A);
    
    /**
    *fungsi prosedur pembagian override dari fungsi Operand
    *@param A untuk parameter pertama
    */
    virtual void operator/(const Operand& A);
    
    /**
    *fungsi prosedur modulo override dari fungsi Operand
    *@param A untuk parameter pertama
    */
    virtual void operator%(const Operand& A);
    
    /**
    *fungsi prosedur div override dari fungsi Operand
    *@param A untuk parameter pertama
    */
    virtual void operatorDiv(const Operand& A);
    
    /**
    *fungsi prosedur setter nilai
    *@param n untuk parameter pertama
    */
    virtual void setNilai(int n);
    
    /**
    *fungsi prosedur setter nilai
    */
    virtual int getNilai()const;
protected:
    int nilai; /*!< sebuah integer nilai */
};

#endif // ARAB_H_INCLUDED
