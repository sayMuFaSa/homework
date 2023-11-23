#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>

int calculate_bins(int arr[], const int size, const int bin_size){
	int bin_ctr = 0;
	int index = 0;
	while (index < size){
		int current_bin = bin_size;
		while(current_bin >= arr[index] && index < size){
			current_bin -= arr[index];
			index++;
		}
		bin_ctr++;
	}
	return bin_ctr;
}

void bin_packing(int array[], const int size, const int bin_size) { // solve by generating all permutations
	int* indices = new int[size];
	std::vector<int> best_case;

	for (int i = 0; i < size; ++i) {
		indices[i] = 0;
	}

	// Initial permutation
	int min_number = calculate_bins(array, size, bin_size);
	best_case.assign(array, array + size);

	int i = 0;
	while (i < size) {
		if (indices[i] < i) {
			if (i % 2 == 0) {
				std::swap(array[0], array[i]);
			} else {
				std::swap(array[indices[i]], array[i]);
			}

			const int test = calculate_bins(array, size, bin_size);
			if (test < min_number){
				min_number = test;
				best_case.assign(array, array + size);
			}
			++indices[i];
			i = 0;
		} else {
			indices[i] = 0;
			++i;
		}
	}

	// Print the best case

	std::cout << "Bins used: " << min_number << std::endl;

	std::cout << "Order of packages: "; // order of packages


	for (int a : best_case){
		std::cout << a << ' ';
	}

	std::cout << std::endl;

	delete[] indices;
}

int main() {
	int package_num;
	int bin_size;
	int* packages;

	std::cout << "Enter the size of a bin: ";
	std::cin >> bin_size;


	std::cout << "Enter the number of packages: ";
	std::cin >> package_num;

	packages = new int[package_num];

	std::cout << "Sizes of packages: " << std::endl;

	for (int i = 0; i < package_num; i++){
		std::cout << "Package " << i + 1 << ": ";
		std::cin >> packages[i];

		if (packages[i] > bin_size){
			std::cout << "The package size is too big to fit to a bin" << std::endl;
			delete[] packages;
			exit(1);
		}
	}


	bin_packing(packages, package_num, bin_size);

	delete[] packages;

	return 0;
}

