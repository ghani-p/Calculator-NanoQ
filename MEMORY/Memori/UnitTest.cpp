/* File		: UnitTest.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include "Memori.h"

int main(){
	Memori memory;
	string input;
	int n;

	do{
		cout << "Input Anda : ";
		cin >> input;
		if(input != "EXIT"){
			if(input == "UNDO"){
				cout << "Undo Berapa kali?";
				cin >> n;
				memory.Undo(n);
			} else if(input == "REDO"){
				cout << "Redo Berapa kali?";
				cin >> n;
				memory.Redo(n);
			} else if(input == "SHOWMEM"){
				cout << "ShowMem Berapa kali?";
				cin >> n;
				memory.ShowMem(n);
			} else if(input == "SHOWALL"){
				cout << "ShowAll:" << endl;
				memory.ShowAll();
			} else if(input == "SAVE"){
				cout << "Disimpan dimana?";
				cin >> input;
				memory.Save(input);
			} else if(input == "CLEAR"){
				cout << "Memory cleared!" << endl;
				memory.Clear();
			} else{
				cout << "Added to memory!" << endl;
				memory.Add(input);
			}
		}
			
	} while(input != "EXIT");
	return 0;
}
