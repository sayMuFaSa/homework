#include <iostream>

struct prime_cell{
	int val;
	prime_cell *next;
	prime_cell (const int v) : val(v), next(nullptr) {}
};


int main(void){
	prime_cell *sentinel = new prime_cell(0);

	int number;

	std::cout << "Enter some number: ";

	int prime = 2;



	std::cin >> number;

	while(number > 1){

		while (number % prime == 0){
			prime_cell *cell = new prime_cell(prime);

			// add to the beginning
			// cell->next = sentinel->next;
			// sentinel->next = cell;
			
			// add to the end
			prime_cell * head = sentinel;
			while (head->next != nullptr){
				head = head->next;
			}
			head->next = cell;
			number /= prime;
		}
		prime++;
	}

	prime_cell *head = sentinel->next;

	while (head != nullptr){
		std::cout << head->val << " * ";

		head = head->next;
	}

	return 0;
}
