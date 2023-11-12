#include <iostream>

int bsearch(const int val, const int *arr, const int n);

int main(void){
	int arr[] = {1, 20, 40, 50};

	const int item = 50;

	const int res = bsearch(item, arr, 4);

	if (res == -1) {
		std::cerr << "Item with value " << item << std::endl;
	}

	std::cout << "Item with value " << item << " is at index: " << res << std::endl;
}

int bsearch(const int val, const int *arr, const int n){
	int left = 0;
	int right = n - 1;

	while(left <= right){
		const int middle = (left + right) / 2;

		if (arr[middle] == val){
			return middle;
		} else if (arr[middle] > val){
			right = middle - 1;
		}else left = middle + 1;

	}

	return -1;
}

