#include <iostream>
#include <string.h>
#include <vector>

int main(void){
	const int imatrix[3][3] = {
		{2, 0, 1},
		{1, 1, 0},
		{3, 2, 1}
	};

	char msg[] = "Hello how are you ?";

	char matrix_form[100][3];

	int length = strlen(msg);
	int ctr = 0;

	for (int i = 0; i < length / 3; i++){
		for (int j = 0; j < 3; j++)
			matrix_form[i][j] = msg[ctr++];
	}

	if (length % 3 != 0){
		const int times = 3 - (length % 3);
		for (int i = 0; i < times; i++){
			matrix_form[length / 3][i] = 0;
		}
		length += 3 - (length % 3);
	}

	int encoded[100][3];

	const int times = length / 3;

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
