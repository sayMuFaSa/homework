#include <iostream>
#include <stdint.h>
#include <vector>

std::vector<int64_t> factors;


void find_factors(int64_t n){
	int64_t i = 2;

	while (i < n){
		while (n % i == 0){
			factors.push_back(i);
			n /= i;
		}
		i++;
	}

	if (n > 1) factors.push_back(n);

}

int main(void){

	int64_t number;


	std::cout << "Enter a number: ";
	std::cin >> number;

	if (number < 2) {
		std::cout << "Input is less than any possible prime factor" << std::endl;
		return 1;
	}

	find_factors(number);

	const  int64_t size = factors.size() - 1;

	std::cout << number << " = ";

	for (int64_t i = 0; i < size; i++){
		std::cout << factors[i] << " * ";
	}

	std::cout << factors[size] << std::endl;

}
