/* File		: Logika.h						*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef LOGIKA_H_INCLUDED
#define LOGIKA_H_INCLUDED

#include "../Operand/Operand.h"
#include <string>
using namespace std;

class Logika:public Operand{
public:
    //ctor
    Logika();
    Logika(string L);
    //dtor
    virtual ~Logika();
    //cctor
    Logika(const Logika& L);
    Logika& operator=(const Logika& L);

    //overide
    void operatornot();
    void operatorand(const Logika& O);
    void operatoror(const Logika& O);
    void operatorxor(const Logika& O);
    //getter
    int getNilai()const;
private:
    int nilai;
};

#endif // LOGIKA_H_INCLUDED
