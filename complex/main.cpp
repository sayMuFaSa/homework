#include <iostream>
#include "complex.h"

int main(void){
	complex number = { 3.0, 4.0 };
	complex first = {10.0, 1.0};

	const complex sum = first + number;

	std::cout << sum;

	sum.plot();

	return 0;
}
