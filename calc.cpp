#include <iostream>
#include <algorithm>
#include <string>
#include "./COLLECTION/Stack/Stack.h"
#include "./COLLECTION/Vector/Vector.h"
#include "./MEMORY/Memori/Memori.h"
#include "./COMMAND/Perintah/Perintah.h"
#include "./EXPRESSION/Postfix/Postfix.h"
#include "./EXPRESSION/Prefix/Prefix.h"
#include "./EXPRESSION/Infix/Infix.h"
#include "./NUMBER/Arab/Arab.h"
#include "./NUMBER/Logika/Logika.h"
#include "./NUMBER/Operand/Operand.h"
#include "./NUMBER/Romawi/Romawi.h"
using namespace std;

void strSplit(string in, char delimiter, Vector<string>& strings) {
	strings.clear();
	int x=0;
	for (int i=1; i<in.length(); i++) {
		if (in[i] == delimiter) {
			string s = in.substr(x,i-x);
			strings.push_back(s);
			x = i+1;
		}
	}
	if (in.length() > 0)
		strings.push_back(in.substr(x, in.length()));
}

int main()
{
	cout << "WELCOME TO NanoQ Qalqulator" << endl;
	Perintah cmd;
	string s = "";
	Vector<string> sp;
	while (1) {
		cout << "> ";
		getline(cin,s);
		if (s != "") {
			std::transform(s.begin(), s.end(), s.begin(), ::toupper);
			strSplit(s,' ',sp);
			if (sp[0].compare("UNDO") == 0) {
				cmd.UNDO(atoi(sp[1].c_str()));
			} else if (sp[0].compare("REDO") == 0) {
				cmd.REDO(atoi(sp[1].c_str()));
			} else if (sp[0].compare("SHOWMEM") == 0) {
				cmd.SHOWMEM(atoi(sp[1].c_str()));
			} else if (sp[0].compare("SHOWALL") == 0) {
				cmd.SHOWALL();
			} else if (sp[0].compare("SETTING") == 0) {
				cmd.SETTING();
			} else if (sp[0].compare("SAVE") == 0) {
				string nf;
				cout << "Masukkan nama file: "; cin >> nf;
				cmd.SAVE(nf);
			} else if (sp[0].compare("EXIT") == 0) {
				cmd.EXIT();
			} else {
				if (cmd.getEkspresi() == "POSTFIX") {
					Postfix E(s, cmd.getBilangan());
					cout << "Hasil = "; E.printHasil(); cout << endl;
					string mem = E.getEkspresi();
					cmd.getMemori().Add(mem);
				} else if (cmd.getEkspresi() == "PREFIX") {
					Prefix E(s, cmd.getBilangan());
					cout << "Hasil = "; E.printHasil(); cout << endl;
					string mem = E.getEkspresi();
					cmd.getMemori().Add(mem);
				} else if (cmd.getEkspresi() == "INFIX") {
					Infix E(s, cmd.getBilangan());
					cout << "Hasil = "; E.printHasil(); cout << endl;
					string mem = E.getEkspresi();
					cmd.getMemori().Add(mem);
				}
			}
		}
	}

	return 0;
}