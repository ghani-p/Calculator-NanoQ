/* File		: Logika.h				*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef LOGIKA_H_INCLUDED
#define LOGIKA_H_INCLUDED

#include "../Operand/Operand.h"
#include <string>
using namespace std;

/*! Sebuah kelas logika turunan dari kelas operand */
class Logika:public Operand{
public:
    
    /**
    *Konstruktor tanpa parameter
    */
    Logika();
    
    /**
    *Konstruktor dengan parameter
    *I.S. string input berupa string 0, 1, true, false, nottrue, notfalse
    *F.S. menyimpan kedalam variabel nilai angka integer 0 dan 1
    *     true=1, false=0, nottrue=0, notfalse=1
    *@param L untuk parameter pertama
    */
    Logika(string L);
    
    /**
    *Destruktor
    */
    virtual ~Logika();
    
    /**
    *Copy Konstruktor
    *@param L untuk parameter pertama
    */
    Logika(const Logika& L);

    /**
    *Operator=
    *@param L untuk parameter pertama
    */
    Logika& operator=(const Logika& L);

    /**
    *Fungsi override terhadap kelas bilangan
    *operator not
    *operator dengan operand unary
    */
    void operatornot();

    /**
    *Fungsi override terhadap kelas bilangan
    *operator and
    *operator dengan operand unary
    *@param O untuk parameter pertama
    */
    void operatorand(const Operand& O);

    /**
    *Fungsi override terhadap kelas bilangan
    *operator or
    *@param O untuk parameter pertama
    */
    void operatoror(const Operand& O);

    /**
    *Fungsi override terhadap kelas bilangan
    *operator and
    *operator dengan operand unary
    *@param O untuk parameter pertama
    */
    void operatorxor(const Operand& O);
    
    /**
    *fungsi getter
    *mengembalikan nilai logika
    */
    int getNilai()const;
private:
    
    int nilai;/*!< sebuah integer nilai */
};

#endif // LOGIKA_H_INCLUDED
