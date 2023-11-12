#include <iostream>
#include <chrono>

double exp(const double a, int n){
	double result = 1;
	double factor = a;
	while(n != 0){
		if (n % 2 == 1) result *= factor;
		factor *= factor;
		n /= 2;
	}
	return result;
}


int main(void){
	double result, power;

	std::cout << "Enter a number to calculate it's exponent: ";

	std::cin >> result;

	std::cout << "Power: ";

	std::cin >> power;

	std::cout << "\nExponent is equal to " << exp(result, power) << std::endl;
	
	return 0;
}
