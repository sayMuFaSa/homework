#include <iostream>
#include <string.h>
#include <vector>

int main(void){
	const int imatrix[3][3] = {
		{2, 0, 1},
		{1, 1, 0},
		{3, 2, 1}
	};

	std::string msg = "Hello how are you ?";

	char matrix_form[100][3];

	int ctr = 0;

	if (msg.length() %3 != 0){
		for (int i = 0; i < 3 - (msg.length() % 3); i++){
			msg += ' ';
		}
	}

	for (int i = 0; i < msg.length() / 3; i++){
		for (int j = 0; j < 3; j++)
			matrix_form[i][j] = msg[ctr++];
	}
	

	int encoded[100][3];

	const int times = msg.length() / 3;

	for (int i = 0; i < times; i++){
		for (int j = 0; j < 3; j++){
			int sum = 0;

			for (int k = 0; k < 3; k++){
				sum += matrix_form[i][k] * imatrix[j][k];
			}

			encoded[i][j] = sum;
		}
	}
}
