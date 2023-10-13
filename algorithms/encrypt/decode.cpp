#include <iostream>
#include <string.h>
#include <fstream>
#include <errno.h>
#include "functions.h"


int x = 0;

int main(){
	int values[100] = {0};

	char string[] = "I don't like these themes.";

	const int length = strlen(string);

	char buffer[100] = {0};
	std::ofstream file;
	int ctr = 0;

	file.open("Results.txt");

	if (!file.is_open()){
		std::cerr << "Can't open the file" << std::endl;

		std::cerr << strerror(errno);
	}

	encode(string, values, 90);


	for (int i = 0; i < 100000; i++){
		decode(values, length, buffer, i);
		if (check(buffer, length)){
			file.write(buffer, length);
			file << std::endl;
			ctr++;
			std::cout << buffer << std::endl;
		}
		memset(buffer, 0, 100);
	}

	if (!ctr){
		std::cout << "No English like statement occured" << std::endl;
	}else {
		std::cout << "There are " << ctr << " occurences." << std::endl ;
	}
}
