/* File		: Perintah.h							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef PERINTAH_H
#define PERINTAH_H

#include "../../MEMORY/Memori/Memori.h"
using namespace std;
/*! Sebuah kelas perintah */
class Perintah{
public:
	/**
    	*Konstruktor default
	 */
	Perintah();

	/**
    	*mengembalikan perintah yang tersimpan dalam memory sebanyak n
    	* @param n untuk parameter pertama
    	*/
	void UNDO(int n);
	
	/**
    	*mengembalikan perintah undo sebanyak n
    	*  @param n untuk parameter pertama
    	*/
	void REDO(int n);
	
	/**
	*menampilkan memori sebanyak n terakhir
	* @param n untuk parameter pertama
	*/
	void SHOWMEM(int n);
	
	/**
	*menampilkan seluruh memori yang ada
	*/
	void SHOWALL();
	
	/**
	*mengatur setting mode kalkulator
	*/
	void SETTING();
	/**
	*menyimpan kedalam memory
	* @param file untuk parameter pertama
	*/
	void SAVE(string file);
	/**
	*keluar dari program
	*/
	void EXIT();
	
	/**
	*getter
	* mengembalikan string ekspresi
	*/
	string getEkspresi();
	
	/**
	*getter
	* mengembalikan string bilangan
	*/
	string getBilangan();
	
	/**
	*getter memori
	*/
	Memori& getMemori();

private:
	Memori memory; /*! variabel memori */
	string ekspresi; /*! variabel ekspresi*/
	string bilangan; /*! variabel bilangan */
};


#endif
