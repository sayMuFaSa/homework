#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "class.h"

int main(void){
	number first_number, second_number, our_sum;

	// Get the numbers
	std::cout << "Enter two natural numbers to calculate the sum" << std::endl;

	std::cout << "First: ";
	std::cin >> first_number;



	std::cout << "\nSecond one: ";
	std::cin >> second_number;


	our_sum = first_number + second_number;

	if(our_sum.error()){
		std::cout << "Out of range error";
		exit(1);
	}
	
	std::cout << "\nThe sum is equal to " << our_sum << std::endl;

}




