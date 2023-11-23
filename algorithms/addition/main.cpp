// rewrite with std::vector
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <utility>
#include "class.h"

int main(void){
	bignum first_number = "100", second_number = "200";

	std::cout << first_number + second_number << std::endl;
}
