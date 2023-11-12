#include <iostream>
#include <stdexcept>

#define MAX_SIZE 1000

class stack{
public:
	stack() : on_top(0) {}
	int on_top;
	int arr[MAX_SIZE];
	void push(const int n);
	int pop();
	int& top();
};

int main(void){
	stack numbers;

	numbers.push(100);

	std::cout << numbers.top();
}

void stack::push(const int n){
	if (on_top >= MAX_SIZE) throw std::runtime_error("STACK'S FULL");

	arr[on_top++] = n;
}

int stack::pop(){
	if (on_top <= 0) throw std::runtime_error("POPPING FROM EMPTY STACK");

	return arr[--on_top];
}

int& stack::top(){
	return arr[on_top - 1];
}

