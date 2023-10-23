#include <vector>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include <chrono>

bool* find_primes(int64_t limit){
	bool *is_composite = (bool*)calloc(1, limit);

	const auto start = std::chrono::steady_clock::now();

	is_composite[0] = true;

	is_composite[1] = true;

	for (int64_t i = 4; i <= limit; i += 2){
		is_composite[i] = true;
	}

	int64_t next_p = 3;
	int64_t stop_a = sqrt(limit);

	while(next_p < stop_a){
		for (int64_t i = next_p * 2; i <= limit; i += next_p){
			is_composite[i] = true;
		}

		next_p += 2;

		while (next_p <= limit && is_composite[next_p]){
			next_p += 2;
		}
	}

	const auto end = std::chrono::steady_clock::now();
	const auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << diff << " milliseconds" << std::endl;
	return is_composite;

}


int main(void){
	int64_t number;

	std::cout << "Enter upper limit: ";

	std::cin >> number;

	bool* ptr = find_primes(number);


	for (int64_t i = 0; i < number; i++){

		if (ptr[i] == false) std::cout << i << ' ';
	}

	std::cout << std::endl;

	free(ptr);
}
