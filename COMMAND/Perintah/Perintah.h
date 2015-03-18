/* File		: Perintah.h							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef PERINTAH_H
#define PERINTAH_H

#include "../../MEMORY/Memori/Memori.h"
using namespace std;

class Perintah{
public:
	//CTOR
	Perintah();

	//COMMANDS
	void UNDO(int n);
	void REDO(int n);
	void SHOWMEM(int n);
	void SHOWALL();
	void SETTING();
	void SAVE(string file);
	void EXIT();
	
	//GETTER
	string getEkspresi();
	string getBilangan();

private:
	Memori memory;
	string ekspresi;
	string bilangan;
};


#endif