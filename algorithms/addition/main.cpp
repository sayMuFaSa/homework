#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <utility>
#include "class.h"

int main(void){
	bignum first_number, second_number;

	// Get the numbers
	std::cout << "Enter the numbers" << std::endl;

	std::cout << "First: ";
	std::cin >> first_number;


	std::cout << "\nSecond one: ";
	std::cin >> second_number;

	bignum our_sum = std::move(first_number + second_number);


	std::cout << "\nThe sum is equal to " << our_sum << std::endl;
	
}
