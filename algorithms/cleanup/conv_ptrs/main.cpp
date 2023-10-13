#include <iostream>

int convergent(int* ptr, int n);

void show(int*, int);

int main(void){
	int a[] = {1, 3, 0, 20, 30, 60, 0, 1};

	int legit = convergent(a, sizeof(a) / 4);

	show(a, sizeof(a) / 4);

	std::cout << "Legit: " << legit << std::endl;
}

int convergent(int* ptr, int n){
	int left = 0;
	int right = n - 1;
	int legit = n;

	while (left < right){
		if(ptr[left] == 0){
			legit--;
			ptr[left] = ptr[right];
			right--;
		}
		else left++;
	}

	if (ptr[left] == 0) legit--;

	return legit;
	
}


void show(int* ptr, int n){
	for (int i = 0; i < n; i++){
		std::cout << ptr[i] << "\t";
	}
	std::cout << std::endl;
}
