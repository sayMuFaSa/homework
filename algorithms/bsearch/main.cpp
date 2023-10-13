#include <iostream>

int bsearch(const int val, const int *arr, const int n);

int main(void){
	int arr[] = {1};

	for (int i = 0; i < 1; i++){
		std::cout << "Number " << arr[i] << " is in the place " << bsearch(arr[i], arr, 1) << std::endl;
	}
}

int bsearch(const int val, const int *arr, const int n){
	int left = 0;
	int right = n;
	int middle;
	while(left != right){
		middle = (left + right) / 2;


		if (arr[middle] < val){
			left = middle;
		} else if (arr[middle] > val){
			right = middle;
		}else return middle;

	}

	return -1;
}

