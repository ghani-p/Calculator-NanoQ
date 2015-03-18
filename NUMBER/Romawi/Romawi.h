/* File		: Romawi.h							*/
/* Author	: Fiqie Ulya Sidiastahta (13514602)	*/
#ifndef ROMAWI_H_INCLUDED
#define ROMAWI_H_INCLUDED

#include "../Arab/Arab.h"
#include <string>
using namespace std;

/*! Sebuah kelas romawi turunan dari kelas arab */
class Romawi:public Arab{
public:

    /**
    *Konstruktor tanpa parameter
    */
    Romawi();
    
    /**
    *Konstruktor dengan parameter
    *I.S. string input berupa string simbol angka Romawi dengan nilai antara I hingga MMMCMXCIX
    *F.S. menyimpan kedalam variabel nilai angka integer dan variabel nromawi angka romawi
    *@param A untuk parameter pertama
    */
    Romawi(string A);
    
    /**
    *Destruktor
    */
    virtual ~Romawi();
    
    /**
    *Copy Konstruktor
    *@param R untuk parameter pertama
    */
    Romawi(const Romawi& R);
    
    /**
    *Operator=
    *@param R untuk parameter pertama
    */
    Romawi& operator=(const Romawi& R);
    
    /**
    *fungsi prosedur penjumlahan override dari Arab
    * I.S. angka Romawi antara I hingga MMMCMXCIX
    * F.S. angka Romawi hasil penjumlahan tidak melebihi MMMCMXCIX
    *@param A untuk parameter pertama
    */
    virtual void operator+(const Operand& A);
    
    /**
    *fungsi prosedur pengurangan override dari Arab
    * I.S. angka Romawi antara I hingga MMMCMXCIX
    * F.S. angka Romawi hasil pengurangan tidak kurang dari I
    *@param A untuk parameter pertama
    */
    virtual void operator-(const Operand& A);
    
    /**
    *fungsi prosedur perkalian override dari Arab
    * I.S. angka Romawi antara I hingga MMMCMXCIX
    * F.S. angka Romawi hasil perkalian tidak melebihi MMMCMXCIX
    *@param A untuk parameter pertama
    */
    virtual void operator*(const Operand& A);
    
    /**
    *fungsi prosedur pembagian override dari Arab
    * I.S. angka Romawi antara I hingga MMMCMXCIX
    *      angka Romawi pembagi tidak boleh 0
    * F.S. angka Romawi hasil pembagian tidak kurang dari I
    *@param A untuk parameter pertama
    */
    virtual void operator/(const Operand& A);
    
    /**
    *fungsi prosedur modulo override dari Arab
    * I.S. angka Romawi antara I hingga MMMCMXCIX
    * F.S. angka Romawi hasil modulo tidak kurang dari I
    *@param A untuk parameter pertama
    */
    virtual void operator%(const Operand& A);
    
    /**
    *fungsi prosedur konversi angka Romawi menjadi angka Arab
    * assert untuk fungsi prosedur kalkulasi
    * assert precondition
    * I.S. angka Romawi antara I hingga MMMCMXCIX
    * F.S. nilai di isi dengan nilai hasil konversi angka Romawi
    *@param R untuk parameter pertama
    */
    void ConvertToArab(string R);
    
    /**
    *fungsi prosedur konversi angka Arab ke angka Romawi
    * assert untuk fungsi prosedur kalkulasi
    * assert postcondition
    * I.S. angka Arab dari 1 hingga 3999
    * F.S. Nromawi di isi dengan nilai hasil konversi angka Arab
    *@param A untuk parameter pertama
    */
    void ConvertToRomawi(int A);
    
    /**
    *fgetter
    */
    string getRomawi()const;

private:
    string Nromawi;/*!< sebuah string Romawi */
};

#endif // ROMAWI_H_INCLUDED
