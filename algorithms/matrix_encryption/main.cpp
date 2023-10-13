#include <iostream>
#include <unistd.h>
#include <string.h>
#include <vector>

int main(void){
	const int imatrix[3][3] = {
		{2, 0, 1},
		{1, 1, 0},
		{3, 2, 1}
	};
	
	char msg[][3] = {{'H', 'e', 'l'}, {'l', 'o', ' '}, {'J', 'a', 'c'}, {'k', '.', 0}};

	int encoded[20][3];

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			int sum = 0;

			for (int k = 0; k < 3; k++){
				sum += msg[i][k] * imatrix[j][k];
			}

			encoded[i][j] = sum;
		}
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			std::cout << encoded[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
