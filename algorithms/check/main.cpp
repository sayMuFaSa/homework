#include <iostream>


int check(int*,unsigned int);

typedef enum{
	unsorted, ascending, descending
}state;


int main(void){
	int my_arr[] = {1, 2, 3, 4};

	int result = check(my_arr, 4);

	switch(result){
		case ascending:
			std::cout << "List is sorted in ascending order";
			break;
		case descending:
			std::cout << "List is in descending order";
			break;
		default:
			std::cout << "List is not sorted";
			break;
	} std::cout << std::endl;
	
	return 0;
}


int check(int* arr, unsigned int number){
	state flag = ascending;

	// Check if in ascending order, if true don't change the flag
	for(int i = 0; i < number - 1; i++){
		if(arr[i] > arr[i + 1]){
			flag = descending;
			break;
		}
	}

	if (flag == ascending) return flag; // if flag wasn't changed return
	

	// Check if in descending order, if true don't change the flag
	for(int i = 0; i < number - 1; i++){

		if(arr[i] < arr[i + 1]){
			return unsorted;
		}

	}

	return flag;
}
