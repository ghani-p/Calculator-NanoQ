/* File		: Vector.h								*/
/* Author	: Nitho Alif Ibadurrahman (13513072)	*/
#ifndef VECTOR_H
#define VECTOR_H

#include "VectorExp.h"
using namespace std;

template <class T>
class Vector{
public:
	//CTOR-CCTOR-DTOR
	Vector();				//ctor
	Vector(const Vector&);	//cctor
	virtual ~Vector();		//dtor

	//SERVICES
	int size();
	void push_back(T x);
	void pop_back();
	void clear();

	//OPERATOR & MEMORY MANAGEMENT
	Vector<T>& operator=(const Vector&);
	T& operator[](const int idx) const;
	void reserve(int newCapacity);
	
private:
	int _size;
	int capacity;
	T* data;
};

template <class T>
Vector<T>::Vector(){
	_size = 0;
	capacity = 0;
	data = 0;
}

template <class T>
Vector<T>::Vector(const Vector& v){
	_size = v._size;
	capacity = v.capacity;
	data = new T[_size];
	for(int i=0; i<_size; i++){
		data[i] = v.data[i];
	}
}

template <class T>
Vector<T>::~Vector(){
	delete [] data;
}

template <class T>
int Vector<T>::size(){
	return _size;
}

template <class T>
void Vector<T>::push_back(T x){
	if (_size >= capacity){
		reserve(capacity+5);
	}
	data[_size++] = x;
}

template <class T>
void Vector<T>::pop_back(){
	if(_size == 0){
		throw (VectorExp(VECTOR_EMPTY)); //raise exception if vector empty
	} else{
		_size--;
	}
}

template <class T>
void Vector<T>::clear(){
	_size = 0;
	capacity = 0;
	data = 0;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& v){
	delete [] data;
	_size = v._size;
	capacity = v.capacity;
	data = new T[_size];
	for (int i=0; i<_size; i++){
		data[i] = v.data[i];
	}
	return *this;
}

template <class T>
T& Vector<T>::operator[](const int idx) const{
	if(idx<0 || idx>_size){
		throw (VectorExp(INDEX_OUT_OF_BOUNDS)); //raise exception if index invalid
	} else{
		return data[idx];
	}
}

template <class T>
void Vector<T>::reserve(int newCapacity){
	if (data == 0){
		_size = 0;
		capacity = 0;
	}
	T* newData = new T[newCapacity];
	int new_size = newCapacity < _size ? newCapacity : _size;
	for(int i=0; i<new_size; i++){
		newData[i] = data[i];
	}
	capacity = newCapacity;
	delete [] data;
	data = newData;
}


#endif
