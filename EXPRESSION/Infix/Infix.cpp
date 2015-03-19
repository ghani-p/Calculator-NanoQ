/* File		: Infix.cpp			*/
/* Author	: Natan (13513070)	*/
#include "Infix.h"
#include <algorithm>
#include <string>

using namespace std;

Infix::Infix(string _ekspresi, string _operandType) : Postfix(_operandType) { //default ctor
	ekspresiP = _ekspresi;
	std::transform(ekspresiP.begin(), ekspresiP.end(), ekspresiP.begin(), ::toupper);
	this->convertToPost();
	this->Hitung();
}


Infix::Infix(const Infix& P) : Postfix(P) { //cctor
	this->ekspresi = P.ekspresi;
	this->hasil = P.hasil;
}


Infix& Infix::operator=(const Infix& P) { //assign
	this->ekspresiP = P.ekspresiP;
	this->ekspresi = P.ekspresi;
	this->hasil = P.hasil;
	return *this;
}

Infix::~Infix() { //dtor

}

void Infix::convertToPost() {
//melakukan konversi ekspresi infix ke postfix dan mengupdate string ekspresi (Postfix)
	Stack<string> stk;

	this->ekspresi = "";

	Vector<string> post;
	int x = 0;
	for (int i=1; i<ekspresiP.length();i++) {
		if (ekspresiP[i] == ' ') {
			string s = ekspresiP.substr(x,i-x);
			post.push_back(s);
			x = i+1;
		}
	}
	if (ekspresiP.length() > 0)
		post.push_back(ekspresiP.substr(x,ekspresiP.length()));

	int j=0;
	for (int i = 0; i < post.size(); i++) {
		if (!(post[i].compare("+") == 0 || post[i].compare("-") == 0 || post[i].compare("*") == 0 || post[i].compare("/") == 0 || post[i].compare("DIV") == 0 || post[i].compare("MOD") == 0 || post[i].compare("AND") == 0 || post[i].compare("OR") == 0 || post[i].compare("XOR") == 0)  && post[i].compare("(") != 0 && post[i].compare(")") != 0) { 
		//implement other operators here
			this->ekspresi += post[i] + " ";
			j++;
		} else if (post[i].compare("+") == 0 || post[i].compare("-") == 0 || post[i].compare("*") == 0 || post[i].compare("/") == 0 || post[i].compare("DIV") == 0 || post[i].compare("MOD") == 0 ||  post[i].compare("OR") == 0 || post[i].compare("XOR") == 0) {
			//is operator
			while (!stk.empty() && stk.top().compare("(") != 0 && (((stk.top().compare("*") == 0 || stk.top().compare("/") == 0 || stk.top().compare("DIV") == 0 || stk.top().compare("MOD") == 0 || stk.top().compare("AND") == 0) && (post[i].compare("+") == 0 || post[i].compare("-") == 0  || post[i].compare("OR") == 0 || post[i].compare("XOR") == 0))
				|| !((stk.top().compare("+") == 0 || stk.top().compare("-") == 0 || stk.top().compare("OR") == 0 || stk.top().compare("XOR") == 0) && (post[i].compare("*") == 0 || post[i].compare("/") == 0 || post[i].compare("DIV") == 0 || post[i].compare("MOD") == 0 || post[i].compare("AND") == 0)))) {
				this->ekspresi += stk.top() + " ";
				j++;
				stk.pop();
			}
			stk.push(post[i]);
		} else if (post[i].compare("(") == 0) {
			stk.push(post[i]);
		} else if (post[i].compare(")") == 0) {
			while (!stk.empty()) {
				if (stk.top().compare("(") == 0) {
					stk.pop();
					break;
				}
				this->ekspresi += stk.top() + " ";
				j++;
				stk.pop();
			}
		}
	}

	while (!stk.empty()) {
    	this->ekspresi += stk.top() + " ";
    	j++;
        stk.pop();
    }
	this->ekspresi = this->ekspresi.substr(0, this->ekspresi.length() - 1);
}

string Infix::getEkspresi() { return this->ekspresiP; }  //mengembalikan string ekspresi infix

void Infix::printEkspresi() { cout<<this->getEkspresi();} //mencetak string ekspresi infix ke layar
