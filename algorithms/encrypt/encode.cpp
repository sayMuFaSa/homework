#include <iostream>
#include <fstream>
#include <string.h>
#include "functions.h"

int x = 0;


int main(){

	std::ofstream file;

	file.open("Encoded_Result.txt");

	int values[100] = {0}, a, b, c, seed;

	char string[] = "I don't like these themes";

	const int length = strlen(string);

	std::cout << "A: ";
	std::cin >> a;

	std::cout << "B: ";
	std::cin >> b;

	std::cout << "C: ";
	std::cin >> c;

	std::cout << "Seed: ";

	std::cin >> seed;

	const encoder enc(seed, a, b, c);

	enc(string, values);

	for (int i = 0; i < length; i++){
		printf("%d ", values[i]);
		file << values[i] << ' ';
	}
	printf("\n");

	file.close();
}
