#include <iostream>
#include <stdarg.h>
#include <initializer_list>
#include <vector>
#include <string.h>
#include <stdexcept>

class array {
public:
	int *arr, *dsize, d, nmem; // d represents number of dimensions
	array(std::initializer_list<int> list) : d(list.size()){
		int size = 1;
		if (d <= 0){
			throw 1;
		}

		// initialize some variables
		dsize = new int [d];
		int ctr = 0;

		for (int i : list){
			size *= i; 
			dsize[ctr] = i;
			ctr++;
		}

		arr = new int [size];
		memset(arr, 0, size * sizeof(int)); // just set everyting to 0

		nmem = size;

	}

	int& operator() (const std::vector<int>& list){
		int index = 0;

		for (int i = 0; i < d - 1; i++){
			int tmp = list[i];
			if (tmp < 0 || tmp >= dsize[i]) throw 1;
			for (int j = i + 1; j < d; j++) tmp *= dsize[j];
			index += tmp;
		}
		int tmp = list.back();
		if (tmp < 0 || tmp >= dsize[d - 1]) throw 1;
		index += tmp;
		return arr[index];
	}

	void show(){
		for (int i = 0; i < nmem; i++){
			std::cout << arr[i] << '\t'; // print the internal array items sequentially
		}

		std::cout << std::endl; // flush std::cout
	}

	~array(){
		delete[] arr;
		delete[] dsize;
	}
};


int main(void){
	array arr = {1, 1, 2, 2};


	arr({0, 0, 0, 0}) = 10;



	arr.show();
}
