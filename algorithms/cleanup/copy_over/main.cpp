#include <iostream>
#include <string.h>

int* copy_over(int*, int);

void show(int* ptr, int n);

int main(void){

	int a[] = {0, 1, 2, 0, 3, 19, 15, 0, 8 , 0, 2, 10, 20, 30, 40};
	

	int *copied = copy_over(a, sizeof(a) / sizeof(int));

	show(copied, sizeof(a) / sizeof(int));
	
	free(copied);

	return 0;
}

int* copy_over(int* src, int n){
	int legit = 0;

	int *dest = (int*)calloc(n, sizeof(int));

	memset(dest, 0, n * sizeof(int));

	for (int i = 0; i < n; i++){
		if (src[i] != 0) {
			dest[legit] = src[i];
			legit++;
		}
	}

	return dest;
}


void show(int* ptr, int n){
	for (int i = 0; i < n; i++){
		std::cout << ptr[i] << "\t";
	}

}
