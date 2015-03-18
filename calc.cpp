#include <iostream>
#include <algorithm>
#include <sstream>
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
	cout << "\033c=============================" << endl;
	cout << " Welcome to NanoQ Calculator" << endl;
	cout << "=============================" << endl;
	cout << "List of Available Commands:" << endl;
	cout << "    -Undo <n>" << endl;
	cout << "    -Redo <n>" << endl;
	cout << "    -ShowMem <n>" << endl;
	cout << "    -ShowAll" << endl;
	cout << "    -Setting" << endl;
	cout << "    -Save <file>" << endl;
	cout << "    -Exit" << endl;
	cout << "---------------------------" << endl;
	Perintah cmd;
	string s = "";
	Vector<string> sp;
	while (1) {
		cout << "> ";
		getline(cin,s);
		if (s != "") {
			try{
				std::transform(s.begin(), s.end(), s.begin(), ::toupper);
				strSplit(s,' ',sp);
				if (sp[0].compare("UNDO") == 0) {
					cmd.UNDO(atoi(sp[1].c_str()));
				} else if (sp[0].compare("REDO") == 0) {
					cmd.REDO(atoi(sp[1].c_str()));
				} else if (sp[0] == "SHOWMEM" || sp[0] == "SHOWALL" || sp[0] == "SETTING" || sp[0] == "SAVE" || sp[0] == "EXIT") {
					if (sp[0].compare("SHOWMEM") == 0) {
						cmd.SHOWMEM(atoi(sp[1].c_str()));
					} else if (sp[0].compare("SHOWALL") == 0) {
						cmd.SHOWALL();
					} else if (sp[0].compare("SETTING") == 0) {
						cmd.SETTING();
					} else if (sp[0].compare("SAVE") == 0) {
						cmd.SAVE(sp[1]);
					} else { //if (sp[0].compare("EXIT") == 0) {
						cmd.EXIT();
					}
					cmd.getMemori().Add(sp[0]);
				} else {

					if (cmd.getEkspresi() == "POSTFIX") {
						Postfix E(s, cmd.getBilangan());
						cout << "Hasil = "; E.printHasil(); cout << endl;
						stringstream mem;
						mem << E.getEkspresi() << " = " << E.getHasil()->getNilai();
						cmd.getMemori().Add(mem.str());
					} else if (cmd.getEkspresi() == "PREFIX") {
						Prefix E(s, cmd.getBilangan());
						cout << "Hasil = "; E.printHasil(); cout << endl;
						stringstream mem;
						mem << E.getEkspresi() << " = " << E.getHasil()->getNilai();
						cmd.getMemori().Add(mem.str());
					} else if (cmd.getEkspresi() == "INFIX") {
						Infix E(s, cmd.getBilangan());
						cout << "Hasil = "; E.printHasil(); cout << endl;
						stringstream mem;
						mem << E.getEkspresi() << " = " << E.getHasil()->getNilai();
						cmd.getMemori().Add(mem.str());
					}
				}
			} catch(const VectorExp&){
					cout << "Memori tidak dapat diakses" << endl;			
			}
		}
	}

	return 0;
}