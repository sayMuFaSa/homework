#include <iostream>
#include <string.h>
#include <vector>

void encode(std::string& msg, std::vector<int>& encoded){
	const int size = 3;

	const int imatrix[size][size] = { // an invertable matrix
		{2, 0, 1},
		{1, 1, 0},
		{3, 2, 1}
	};

	const int length = msg.length();

	if (length % 3 != 0){
		const int times = 3 - (length % 3);
		for (int i = 0; i < times; i++){
			msg += '\0';
		}
	}

	const int times = msg.length();

	const char *data = msg.data(); // access directly

	for (int i = 0; i < times; i += size){

		for (int j = 0; j < size; j++){
			int sum = 0;

			for (int k = 0; k < size; k++) sum += data[i + k] * imatrix[k][j];

			encoded.push_back(sum);
		}

	}

}

void decode(std::vector<int>& encoded, std::vector<int>& decoded){
	const int size = 3;

	const int inverse[size][size] = { // its inverse
		{1, 2, -1},
		{-1, -1, 1},
		{-1, -4, 2}
	};

	const int times = encoded.size();

	const int *data = encoded.data(); // access directly

	for (int i = 0; i < times; i += 3){

		for (int j = 0; j < size; j++){
			int sum = 0;

			for (int k = 0; k < size; k++) sum += data[i + k] * inverse[k][j];

			decoded.push_back(sum);
		}

	}
}

int main(void){
	
	std::string msg;

	std::vector<int> encoded;

	std::vector<int> decoded;

	

	std::cout << "Enter the message to be encoded: ";

	std::getline(std::cin, msg);

	encode(msg, encoded);

	std::cout << "Encoded message: ";

	for (int i : encoded){
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	decode(encoded, decoded);

	std::cout << "After decoding: ";

	for (int i : decoded){
		std::cout << static_cast<char>(i); // \0 character also passed to cout
	}

	std::cout << std::endl;
}
