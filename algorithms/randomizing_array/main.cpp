#include <iostream>
#include <stdlib.h>
#include <time.h>

void randomize_array(int *arr, const int size){
	srand(time(NULL));

	for (int i = 0; i < size; i++){
		const int random = rand() % size;
		const int tmp = arr[i];
		arr[i] = arr[random];
		arr[random] = tmp;
	}
}

int main(void){
	int sorted[] = {1, 2, 3, 4, 5, 6};

	const int size = sizeof(sorted) / sizeof(int);

	std::cout << "Before randomization:";

	for (int i = 0; i < size; i++){
		std::cout << ' ' << sorted[i];
	}

	randomize_array(sorted, size);

	std::cout << "\nAfter: ";



	for (int i = 0; i < size; i++){
		std::cout << ' ' << sorted[i];
	}

	std::cout << std::endl;
}
