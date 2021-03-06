/* File		: Prefix.cpp			*/
/* Author	: Natan (13513070)	*/
#include "Prefix.h"
#include <algorithm>
#include <string>

using namespace std;

Prefix::Prefix(string _ekspresi, string _operandType) : Postfix(_operandType) { //default ctor
	ekspresiP = _ekspresi;
	std::transform(ekspresiP.begin(), ekspresiP.end(), ekspresiP.begin(), ::toupper);
	this->convertToPost();
	this->Hitung();
}


Prefix::Prefix(const Prefix& P) : Postfix(P) { //cctor
	this->ekspresi = P.ekspresi;
	this->hasil = P.hasil;
}


Prefix& Prefix::operator=(const Prefix& P) { //assign
	this->ekspresiP = P.ekspresiP;
	this->ekspresi = P.ekspresi;
	this->hasil = P.hasil;
	return *this;
}


Prefix::~Prefix() { //dtor

}


void Prefix::convertToPost() { //melakukan konversi ekspresi prefix ke postfix dan mengupdate string ekspresi (Postfix)
	Stack<string> stk;
	Vector<string> post;

	this->ekspresi = "";

	int x = 0;
	for (int i=1; i<ekspresiP.length();i++) {
		if (ekspresiP[i] == ' ') {
			string s = ekspresiP.substr(x,i-x);
			post.push_back(s);
			x = i+1;
		}
	}
	if (ekspresiP.length() > 0)
		post.push_back(ekspresiP.substr(x,ekspresiP.length()-1));

	int j=0;
	for (int i = 0; i < post.size(); i++) {
		if (post[i].compare("+") == 0 || post[i].compare("-") == 0 || post[i].compare("*") == 0 || post[i].compare("/") == 0 || post[i].compare("DIV") == 0 || post[i].compare("MOD") == 0 || post[i].compare("AND") == 0 || post[i].compare("OR") == 0 || post[i].compare("XOR") == 0) { 
			stk.push(post[i]);
		} else {
			this->ekspresi = this->ekspresi + post[i] + " ";
			j++;
			while (!stk.empty() && stk.top().compare("#") == 0) {
				stk.pop();
				this->ekspresi = this->ekspresi + stk.top() + " ";
				j++;
				stk.pop();
			}
			stk.push("#");
		}
	}
	this->ekspresi = this->ekspresi.substr(0, this->ekspresi.length() - 1);
}

string Prefix::getEkspresi() { return this->ekspresiP; } //mengembalikan string ekspresi prefix

void Prefix::printEkspresi() { cout<<this->getEkspresi();} //mencetak string ekspresi prefix ke layar