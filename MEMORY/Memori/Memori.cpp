/* File		: Memori.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include <iostream>
#include <fstream>
#include "Memori.h"
using namespace std;

Memori::Memori(){
}

Memori::Memori(const Memori& m){
	int i;
	for(i=0; i<UndoArray.size(); i++){
		UndoArray.push_back(m.UndoArray[i]);
		cout << UndoArray[i];
		UndoArray[i] = m.UndoArray[i];
	}
	for(i=0; i<RedoArray.size(); i++){
		RedoArray.push_back(m.RedoArray[i]);
	}
}

Memori::~Memori(){

}

void Memori::Undo(int n){
	string val;
	int x = n;
	int y = UndoArray.size()-x+1;
	for(int i=UndoArray.size()-1; i>=y; i--){
		if (isPerintah(UndoArray[i])){
			x++;
		}
		val = UndoArray[i];
		UndoArray.pop_back();
		RedoArray.push_back(val);
	}
}

void Memori::Redo(int n){
	string val;
	int x = n;
	int y = RedoArray.size()-x+1;
	for(int i=RedoArray.size()-1; i>=y; i--){
		if (isPerintah(RedoArray[i])){
			x++;
		}
		val = RedoArray[i];
		RedoArray.pop_back();
		UndoArray.push_back(val);
	}
}

void Memori::ShowMem(int n){
	for (int i=UndoArray.size()-n; i<UndoArray.size()+1; i++){
		cout << UndoArray[i];
	}
}

void Memori::ShowAll(){
	for (int i=0; i<UndoArray.size(); i++){
		cout << UndoArray[i] << endl;
	}
}

void Memori::Save(string filename){	
	ofstream outputFile;
	outputFile.open (filename.c_str(), fstream::app);
	outputFile << "Memori:" << endl;
	for(int i=0; i<UndoArray.size(); i++){
		if(!isPerintah(UndoArray[i])){
			outputFile << UndoArray[i] << endl;	
		}
	}
}

void Memori::Clear(){
	UndoArray.clear();
	RedoArray.clear();
}

int Memori::isPerintah(string s){
	return (s=="REDO" || s=="SHOWMEM" || s=="SHOWALL" || s=="SETTING" || s=="SAVE");
}

void Memori::Add(string s){
	UndoArray.push_back(s);
}
