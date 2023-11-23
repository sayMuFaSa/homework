#include <iostream>
#include <string.h>
#include <fstream>
#include <errno.h>
#include <string>
#include "functions.h"

int x = 0;

int main(){
	int values[100] = {0};

	std::string string;

	int length = 0;

	int a, b, c;

	char buffer[100] = {0};
	std::ifstream ifile;
	std::ofstream ofile;
	int ctr = 0;

	std::cout << "Enter coefficents\n";

	std::cout << "A: ";
	std::cin >> a;

	std::cout << "B: ";
	std::cin >> b;

	std::cout << "C: ";
	std::cin >> c;

	decoder dec(a, b, c);

	ifile.open("Encoded_Result.txt");
	
	while(true){
		int a;
		ifile >> a;
		std::cout << a;
		if (ifile.fail()) break;
		values[length] = a;
		length++;
	}

	ifile.close();


	ofile.open("Decoded_Results.txt");


	for (int i = 0; i < 100000; i++){
		dec(values, length, buffer, i);
		if (check(buffer, length)){
			ofile.write(buffer, length);
			ofile << std::endl;
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
