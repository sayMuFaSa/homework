#include <iostream>
#include <cmath>

int main(int argc, char **argv){
	double epst;
	double epsa = 100.0;
	double epss;
	double trueValue;
	double x;
	int n;
	int m;
	double apprValue;
	double term {1.0};
	double prevValue;


	std::cout << "Enter x: ";
	std::cin >> x;

	std::cout << "Enter siginificant numbers: ";
	std::cin >> m;

	trueValue = std::exp(x);
	apprValue = 1.0;
	n = 1;
	epss = 0.5 * pow(10.0, 2-m);
	epsa = 100.0;

	std::cout << "N	Exp(x)	Epst	Epsa" << std::endl;

	while(epsa > epss){
		// calculate quantities of the iteration.

		epst = std::abs((trueValue - apprValue) / trueValue) * 100;

		if (n != 1){
			epsa = std::abs((apprValue - prevValue) / apprValue) * 100;

		}

		std::cout << n << "\t"
			<< apprValue << "\t"
			<< epst << "\t"
			<< epsa << "\t"
			<< std::endl;

		getchar();

		// calculate the next term
		term *= - x / static_cast<double>(n);
		prevValue = apprValue;
		apprValue += term;
		n++;

	}

	return 0;
}
