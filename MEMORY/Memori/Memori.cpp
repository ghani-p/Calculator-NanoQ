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
	int count = 0;
	while (count != n-1){
		if(!isPerintah(UndoArray[UndoArray.size()-1])){
			count++;
		}
		val = UndoArray[UndoArray.size()-1];
		UndoArray.pop_back();
		RedoArray.push_back(val);
	}

}

void Memori::Redo(int n){
	string val;
	int count = 0;
	while (count != n-1){
		if(!isPerintah(RedoArray[RedoArray.size()-1])){
			count++;
		}
		val = RedoArray[RedoArray.size()-1];
		RedoArray.pop_back();
		UndoArray.push_back(val);
	}
}

void Memori::ShowMem(int n){
	for (int i=UndoArray.size()-n; i<UndoArray.size(); i++){
		cout << UndoArray[i] << endl;
	}
}

void Memori::ShowAll(){
	for (int i=0; i<UndoArray.size(); i++){
		cout << UndoArray[i] << endl;
	}
}

void Memori::Save(string filename){
	ofstream outputFile;
	outputFile.open (filename.c_str());
	for(int i=0; i<UndoArray.size(); i++){
		if(!isPerintah(UndoArray[i])){
			outputFile << UndoArray[i] << endl;	
		}
	}
	outputFile.close();		
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
