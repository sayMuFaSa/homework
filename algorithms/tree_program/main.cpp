#include <iostream>


int main(void){
	char matrix[4][18] = {0};
	
	for (int i = 0; i < 8; i ++){
		matrix[0][i] = ' ';
	}

	matrix[0][8] = '4';

	for (int i = 0; i < 4; i++){
		matrix[0][i] = '2';
	}

	printf("%s", matrix[0]);

	return 0;
}

