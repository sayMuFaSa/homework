#include <iostream>
#include <cmath>
#include <format>

int main(int argc, char **argv){
	double epst;
	double epsa = 100.0;
	double epss;
	double trueValue;
	double x;
	unsigned int n;
	double apprValue;
	double term {1.0};
	double prevValue;


	std::cout << "Enter x: ";
	std::cin >> x;

	std::cout << "Enter eps: ";
	std::cin >> epss;

	trueValue = exp(x);
	apprValue = 1.0;
	n = 1;

	std::cout << "N	Exp(x)	Epst	Epsa" << std::endl;

	while(epsa > epss){
		// calculate quantities of the iteration.

		epst = std::abs((trueValue - apprValue) / trueValue) * 100;

		if (n != 1){
			epsa = std::abs((apprValue - prevValue) / apprValue) * 100;

		}

		std::cout << n << "	"
			<< apprValue << "	"
			<< epst << "	"
			<< epsa << "	"
			<< std::endl;

		getchar();

		// calculate the next term
		term *= x / static_cast<double>(n);
		prevValue = apprValue;
		apprValue += term;
		n++;

	}

	return 0;
}
