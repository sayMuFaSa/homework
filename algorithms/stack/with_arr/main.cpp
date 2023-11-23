#include <iostream>
#include <stdexcept>
#include <string.h>

#define MAX_SIZE 1000

class stack{
	int size;
	int *arr;
	int limit;
public:
	stack(const int init) : size(0), arr(new int[init]), limit(init) {}
	void push(const int n);
	int pop();
	int& top();
	bool empty();
	int get_size() { return size; }
	~stack(){
		delete[] arr;
	}
};

int main(void){

	stack numbers(2);

	numbers.push(100);

	numbers.push(10);

	std::cout << numbers.top() << std::endl;

}

void stack::push(const int n){

	if (size > limit * 3 / 4) { // if more than 75%
		int *tmp = new int[limit * 2];
		memcpy(tmp, arr, size * sizeof(int));	// if elements are objects, more complex copying logic might be needed.
		delete arr;
		arr = tmp;
		limit *= 2;
	}

	arr[size++] = n;
}

int stack::pop(){
	if (size == 0) throw std::runtime_error("POPPING FROM EMPTY STACK");

	if (limit > size / 4 && limit > 1) {	// if less than 25%
		int *tmp = new int[limit / 2];
		memcpy(tmp, arr, size * sizeof(int));
		delete arr;
		arr = tmp;
		limit /= 2;
	}

	return arr[--size];
}

int& stack::top(){
	return arr[size - 1];
}

bool stack::empty(){
	return (size == 0) ? true : false;
}

