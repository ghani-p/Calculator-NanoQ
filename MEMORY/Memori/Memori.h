/* File		: Memori.h								*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef MEMORI_H
#define MEMORI_H

#include "../../COLLECTION/Vector/Vector.h"
using namespace std;

class Memori{
public:
	/**
    	*Konstruktor tanpa parameter
    	*/
	Memori();		
	/**
    	*Copy Konstruktor 
    	*/
	Memori(const Memori&);
	/**
    	*Destruktor
    	*/
	virtual ~Memori();			
  
	/**
    	*mengembalikan perintah yang tersimpan dalam memory sebanyak n
    	* @param n untuk parameter pertama
    	*/
	void Undo(int n);
	
	/**
    	*mengembalikan perintah undo sebanyak n
    	*  @param n untuk parameter pertama
    	*/
	void Redo(int n);
	
	/**
	*menampilkan memori sebanyak n terakhir
	* @param n untuk parameter pertama
	*/
	void ShowMem(int n);
	
	/**
	*menampilkan seluruh memori yang ada
	*/
	void ShowAll();
	
	/**
	*menyimpan kedalam memory
	* @param filename untuk parameter pertama
	*/
	void Save(string filename);
	void Clear();
	
	/**
	*mengembalikan true bila string termasuk perintah
	* @param s untuk parameter pertama
	*/
	int isPerintah(string s);

	/**
	*setter
	* menambahkan elemen memori
	*/
	void Add(string s);

private:
	Vector<string> UndoArray; /*! vektor string penyimpan perintah undo */
	Vector<string> RedoArray; /*! vektor string penyimpan perintah redo */
};


#endif
