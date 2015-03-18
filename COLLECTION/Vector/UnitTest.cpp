/* File		: UnitTest.cpp							*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#include "Vector.h"
#include "VectorExp.h"

int main(){
	string input;
	Vector<string> v;
	int i;
	cout << "Test Vector" << endl;
	do{
		cout << "Input Anda : ";
		cin >> input;
		if(input != "EXIT"){
			v.push_back(input);
		}
	}while(input != "EXIT");
	cout << "Isi Vector Anda: " << endl;
	for(i=0; i<v.size(); i++){
		input = v[i];
		v.pop_back();
		cout << input << endl;
	}
	v.clear();
	cout << "Vector Anda sekarang: " << endl;
	for(int i=0; i<v.size(); i++){
		input = v[i];
		v.pop_back();
		cout << input << endl;
	}
	try{
		cout << "Masukkan index yang ingin di akses : ";
		cin >> i;
		cout << v[i];
	} catch(const VectorExp&){
		cout << "Index out of bounds!" << endl;
	}
	return 0;
}
