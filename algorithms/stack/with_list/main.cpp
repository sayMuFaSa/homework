#include "list.h" // singly linked list
#include <stdexcept>
#include <iostream>

class stack : private list{
public:
	void push(const int n);
	int pop();
	int& top();
};

int main(void){
	stack numbers;

	numbers.push(2);

	std::cout << numbers.top();

}

void stack::push(const int a){
	this->front_insert(a);
}

int stack::pop(){
	if (start->next == nullptr) throw std::runtime_error("POPPING EMPTY STACK");
	const int val = start->next->val;
	this->erase_front();
	return val;
}

int& stack::top(){
	if (start->next == nullptr) throw std::runtime_error("STACK'S EMPTY");

	return start->next->val;
}
