#pragma once
using namespace std;

const int MAX_SIZE = 20;

template<typename T>
class stack {
private:
	T data[MAX_SIZE];
	int size;
public:
	stack();
	void push(T val);
	void pop();
	void pop_two();
	T top();
	int empty();
};

template<typename T>
stack<T>::stack() {
	size = 0;
}

template<typename T>
void stack<T>::push(T val) {
	if (size == MAX_SIZE) {
		throw overflow_error("Called push on full stack.");
	}
	else {
		data[size] = val;
		size++;
	}
}

template<typename T>
void stack<T>::pop() {
	if (empty()) {
		throw out_of_range("Called pop on empty stack.");
	}
	else {
		//delete data[size];
		size--;
	}
}

template<typename T>
void stack<T>::pop_two() {
	if (empty()) {
		throw out_of_range("Called pop_two on empty stack.");
	}
	else if (size == 1) {
		throw out_of_range("Called pop_two on a stack of size 1.");
	}
	else {
		//delete data[size];
		size--;
		//delete data[size];
		size--;
	}
}

template<typename T>
T stack<T>::top() {
	if (empty()) {
		throw underflow_error("Called top on empty stack.");
	}
	else {
		return data[size-1]; //minus 1 because index doesn't match how humans count from 1
	}
}

template<typename T>
int stack<T>::empty() {
	if (size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}