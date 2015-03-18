/* File		: Memori.h								*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef MEMORI_H
#define MEMORI_H

#include "../../COLLECTION/Vector/Vector.h"
using namespace std;

class Memori{
public:
	//CTOR-CCTOR-DTOR
	Memori();				//ctor
	Memori(const Memori&);	//cctor
	virtual ~Memori();				//dtor
  
	//SERVICES
	void Undo(int n);
	void Redo(int n);
	void ShowMem(int n);
	void ShowAll();
	void Save(string filename);
	void Clear();
	
	//PREDIKAT
	int isPerintah(string s);

	//SETTER
	void Add(string s);

private:
	Vector<string> UndoArray;
	Vector<string> RedoArray;
};


#endif