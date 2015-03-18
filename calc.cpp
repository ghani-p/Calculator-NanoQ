#include <iostream>
#include <algorithm>
#include <string>
#include "./COLLECTION/Stack/Stack.h"
#include "./COLLECTION/Vector/Vector.h"
#include "./MEMORY/Memori/Memori.h"
#include "./COMMAND/Perintah/Perintah.h"
/*#include "./EXPRESSION/Postfix/Postfix.h"
#include "./EXPRESSION/Prefix/Prefix.h"
#include "./EXPRESSION/Infix/Infix.h"
#include "./NUMBER/Arab/Arab.h"
#include "./NUMBER/Logika/Logika.h"
#include "./NUMBER/Operand/Operand.h"
#include "./NUMBER/Romawi/Romawi.h"*/
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
		strings.push_back(in.substr(x, in.length()-1));
}

int main()
{
	cout << "WELCOME TO NanoQ Qalqulator" << endl;
	Perintah cmd;
	string s = "";
	Vector<string> sp;
	while (!s.compare("EXIT")) {
		cin >> s;
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		strSplit(s,' ',sp);
		if (!sp[0].compare("undo")) {
			cmd.UNDO(atoi(sp[1].c_str()));
		} else if (!sp[0].compare("redo")) {
			cmd.REDO(atoi(sp[1].c_str()));
		} else if (!sp[0].compare("showmem")) {
			cmd.SHOWMEM(atoi(sp[1].c_str()));
		} else if (!sp[0].compare("showall")) {
			cmd.SHOWALL();
		} else if (!sp[0].compare("setting")) {
			cmd.SETTING();
		} else if (!sp[0].compare("save")) {
			string nf;
			cout << "Masukkan nama file: "; cin >> nf;
			cmd.SAVE(nf);
		} else if (!sp[0].compare("exit")) {
			cmd.EXIT();
		}
	}

	return 0;
}