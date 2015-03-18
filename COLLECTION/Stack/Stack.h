/* File		: Stack.h								*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef STACK_H
#define STACK_H

#include "StackExp.h"
using namespace std;

template <class T>
class Stack{
public:
	//CTOR-CCTOR-DTOR
	Stack();				//ctor default
	Stack(int);				//ctor dengan parameter
	Stack(const Stack&);	//cctor
	virtual ~Stack();				//dtor
	
	//SERVICES
	void push(T x);
	void pop();
	T top();

	//PREDIKAT
	int isEmpty() const;
	int isFull() const;

private:
	static const int defaultStackSize = 500;
	const int size;
	int topStack;
	T* data;

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
	if(isFull()){
		throw (StackExp(STACK_FULL)); //raise exception if stack full
	} else{
		topStack++;
		data[topStack] = x;
	}
}

template <class T>
void Stack<T>::pop(){
	if(isEmpty()){
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
int Stack<T>::isFull() const{
	return topStack == size-1;
}

template <class T>
int Stack<T>::isEmpty() const{
	return topStack == -1;
}


#endif