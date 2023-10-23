#include <iostream>
#include <string.h>
#include "functions.h"

int x = 0;


int main(){

	int values[100] = {0}, a, b, c;

	char string[] = "I don't";

	const int length = strlen(string);


	std::cout << "A: ";
	std::cin >> a;

	std::cout << "B: ";
	std::cin >> b;

	std::cout << "C: ";
	std::cin >> c;

	const encoder enc(10, a, b, c);

	enc(string, values);

	for (int i = 0; i < length; i++){
		printf("%d %d ", values[i], (int)string[i]);
	}
	printf("\n");
}
