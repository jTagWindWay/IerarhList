#pragma once
#include <iostream>
#include <string>

using namespace std;


template <class T>
class TStack {

private:

	int Size;
	int MaxSize;
	T *mas;

public:

	TStack(int _MaxSize = 15) {
		MaxSize = _MaxSize;
		Size = 0;
		mas = new T[MaxSize];
	}

	TStack(const TStack & ts) {
		MaxSize = ts.MaxSize;
		Size = ts.Size;
		mas = new T[ts.MaxSize];
		for (int i = 0; i < Size; i++) {
			mas[i] = ts.mas[i];
		}
	}

	~TStack() {
		delete[] mas;
	}

	bool isEmpty() {
		if (Size == 0)
			return true;
		else
			return false;
	}

	bool isFull() {
		if (Size == MaxSize)
			return true;
		else
			return false;
	}

	void Push(T a) {
		if (isFull())   throw 1;
		mas[Size] = a;
		Size++;
	}

	T Pop() {
		if (isEmpty())  throw  2;
		Size--;
		return mas[Size];

	}

	T Top() {
		if (isEmpty())  throw 3;
		return mas[Size - 1];
	}

	void clearTStack() {
		Size = 0;
	}

	void Clear() {
		Size = 0;
	}
};