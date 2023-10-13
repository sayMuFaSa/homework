#include <iostream>
#include <string.h>

#define buff_size 100

int cleanup(int* ptr, int n);

void show(int* ptr, int n);


int main(void){

	int arr[] = {1, 0, 2, 4, 5, 6, 2};

	int legit = cleanup(arr, 7);

	show(arr, 7);

	std::cout << legit << std::endl;

}

int cleanup(int* ptr, int n){
	int legit = 0;


	int buffer[buff_size] = {0};

	int full = 0;

	int place = 0;

	int i = 1;


	if (ptr[0] != 0) {
		buffer[0] = ptr[0];
		legit++;
		full++;
	}


	for (; i < n; i++){
		if (ptr[i] != 0){
			buffer[full] = ptr[i];
			full++;
			legit++;
		}

		if (full == buff_size){
			memcpy(ptr + place, buffer, buff_size * 4);
			full = 0;
			place += buff_size;
		}
	}
	
	if (full != 0){
		memcpy(ptr + place, buffer, full * 4);
	}
	

	return legit;
}

void show(int* ptr, int n){
	for (int i = 0; i < n; i++){
		std::cout << ptr[i] << "\t";
	}
	std::cout << std::endl;
}
