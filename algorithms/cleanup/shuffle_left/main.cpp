#include <iostream>
#include <string.h>

int shuffle(int*, int);

void show(int *ptr, int n);

int main(void){

	int a[] = {1, 0, 2, 0, 0, 0};

	int legit = shuffle(a, sizeof(a) / sizeof(int));

	show(a, sizeof(a) / sizeof(int));

	std::cout << legit << std::endl;
}


int shuffle(int* ptr, int legit){
	legit--;

	int left = 0;

	while(left <= legit){
		if (ptr[left] == 0){

			// Copying
			for (int i = left; i < legit; i++){
				ptr[i] = ptr[i + 1];
			}
			
			// memcpy(ptr + left, ptr + left + 1, legit * 4); // another way to copy

			legit--;


		} else left++;
	}

	return legit + 1;
}

void show(int* ptr, int n){
	for (int i = 0; i < n; i++){
		std::cout << ptr[i] << "\t";
	}

	std::cout << std::endl;

}





