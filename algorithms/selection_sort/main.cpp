/*
 *
 *	Have to rewrite!
 *
 */

#include <iostream>

void selection_sort(int*, int);

void show(int*, int);

int main(void){
	int my_arr[100] = {0};

	int input = 0;

	int ctr = 0;

	std::cout << "Enter the numbers" << std::endl;

	for(; input > -1;){
		std::cin >> input;
		my_arr[ctr] = input;
		ctr++;
	}

	std::cout << "The array" << std::endl;

	show(my_arr, ctr);

	selection_sort(my_arr, ctr);

	show(my_arr, ctr);

}

void selection_sort(int* list, int n){
	int marker = n;

	while(marker > 0){
		int max = 0;

		for(int i = 0; i < marker; i++){
			if(list[max] < list[i]){
				max = i;
			}
		}

		int tmp = list[marker - 1];

		list[marker - 1] = list[max];

		list[max] = tmp;

		marker--;
	}
}

void show(int* list, int n){
	for (int i = 0; i < n; i++){
		std::cout << list[i] << "\t";
	}
	std::cout << std::endl;
}


