#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

bool is_prime(int64_t p, int64_t limit){
	srand(time(NULL));
	for (int64_t test = 0; test < limit; test++){
		int64_t n = rand() % p;
		const int64_t power = pow(n, p - 1);

		if (power % p != 1) return false;
	}
	return true;
}

int main(void){
	int number;
	std::cout << "Enter a natural number: ";
	std::cin >> number;

	const char *ptr = (is_prime(number, 5)) ? "It's a prime number" : "It's not a prime number";

	std::cout << ptr << std::endl;

	return 0;
}
