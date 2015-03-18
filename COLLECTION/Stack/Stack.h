/* File		: Stack.h								*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef STACK_H
#define STACK_H

#include "StackExp.h"
using namespace std;

template <class T>
class Stack{
public:
	/**
    	*Konstruktor default tanpa parameter
    	*/
	Stack();
	/**
    	*Konstruktor default dengan parameter
    	*/
	Stack(int);	
	/**
    	*Copy Konstruktor
    	*/
	Stack(const Stack&);
	/**
    	*Destruktor
    	*/
	~Stack();			
	
	/**
    	*I.S. Stack tidak penuh
    	* F.S Stack ditambahkan elemen x, Top bertambah 1
    	* @param x untuk parameter pertama
    	*/
	void push(T x);
	
	/**
    	*I.S. Stack tidak kosong
    	* F.S Stack berkurang 1 elemen. Top berkurang 1
    	*/
	void pop();
	
	/**
    	*mengembalikan nilai Top
    	*/
	T top();

	/**
    	*mengembalikan true jika stack kosong
    	* mengembalikan false jika stack tidak kosong
    	*/
	int empty() const;
	/**
    	*mengembalikan true jika stack penuh
    	* mengembalikan false jika stack tidak penuh
    	*/
	int full() const;

private:
	static const int defaultStackSize = 500; /*!< nilai default ukuran stack*/
	const int size; /*!< ukuran stack */
	int topStack; /*!< alamat top dari stack*/
	T* data; /*!< elemen stack */

};

template <class T>
Stack<T>::Stack() : size(defaultStackSize){
	topStack = -1;
	data = new T[size];
}

template <class T>
Stack<T>::Stack(int _size) : size(_size){
	topStack = -1;
	data = new T[size];
}

template <class T>
Stack<T>::Stack(const Stack& s) : size(s.size){
	topStack = s.topStack;
	data = new T[size];
	for(int i=0; i<size; i++){
		data[i] = s.data[i];
	}
}

template <class T>
Stack<T>::~Stack(){
	delete [] data;
}

template <class T>
void Stack<T>::push(T x){
	if(full()){
		throw (StackExp(STACK_FULL)); //raise exception if stack full
	} else{
		topStack++;
		data[topStack] = x;
	}
}

template <class T>
void Stack<T>::pop(){
	if(empty()){
		throw (StackExp(STACK_EMPTY)); //raise exception if stack empty
	} else{
		topStack--;
	}
}

template <class T>
T Stack<T>::top(){
	return data[topStack];
}

template <class T>
int Stack<T>::full() const{
	return topStack == size-1;
}

template <class T>
int Stack<T>::empty() const{
	return topStack == -1;
}


#endif
