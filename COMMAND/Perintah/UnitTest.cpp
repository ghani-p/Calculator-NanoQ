/* File		: UnitTest.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include "Perintah.h"

int main(){
	Perintah cmd;
	string input;
	int n;

	while(input != "EXIT"){
		cout << "Input Anda : ";
		cin >> input;
		if(input != "EXIT"){
			if(input == "UNDO"){
				cout << "Undo Berapa kali?";
				cin >> n;
				cmd.UNDO(n);
			} else if(input == "REDO"){
				cout << "Redo Berapa kali?";
				cin >> n;
				cmd.REDO(n);
			} else if(input == "SHOWMEM"){
				cout << "ShowMem Berapa kali?";
				cin >> n;
				cmd.SHOWMEM(n);
			} else if(input == "SHOWALL"){
				cout << "ShowAll:" << endl;
				cmd.SHOWALL();
			} else if(input == "SAVE"){
				cout << "Disimpan dimana?";
				cin >> input;
				cmd.SAVE(input);
			} else if(input == "SETTING"){
				cmd.SETTING();
			} else if(input == "EXIT"){
				cmd.EXIT();
			} else{
				cmd.getMemori().Add(input);
			}
		}		
	}
	return 0;
}
