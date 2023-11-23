#include <iostream> 
#include <utility>
#include <vector>


#define INTERMIDATE_RESULTS 0 // set to nonzero value if you want to see intermidate results

int bin_size;

int calculate_bins(const int arr[], const int size)
{
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

std::vector<int> best_case;
int temp;
int min_bin_number;

void permute(std::vector<int>& a, int l, int r)  // solve by generating all permutations recursively
{ 
	// Base case 
	if (l == r)
	{
		temp = calculate_bins(a.data(), r + 1);


	#if		INTERMIDATE_RESULTS

		for (const int i : a){
			std::cout << i << ' ';
		}
		std::cout << temp << std::endl;

	#endif

		if (temp < min_bin_number) {
			min_bin_number = temp;
			best_case = a;
		}
	}
	else { 
		// Permutations made 
		for (int i = l; i <= r; i++) { 

			// Swapping done 
			std::swap(a[l], a[i]); 

			// Recursion called 
			permute(a, l + 1, r); 

			// backtracking
			std::swap(a[l], a[i]); 
		} 
	} 
}

  
int main() {

	int pkg_num;

	std::cout << "Enter the size for the bins: ";
	std::cin >> bin_size;

	std::cout << "Enter the number of packages: ";
	std::cin >> pkg_num;

	std::vector<int> packages(pkg_num);

	for (int i = 0; i < pkg_num; i++){
		std::cout << "Package " << i << ": ";
		std::cin >> packages[i];
	}

	std::cout << "Initial order of packages: ";

	for (const int i : packages){
		std::cout << i << ' ';
	}

	std::cout << '\n' << std::endl;

	min_bin_number = packages.size();
  
    // Function call 
    permute(packages, 0, packages.size() - 1);

	std::cout << "Minimal number of bins: " << min_bin_number << std::endl;

	std::cout << "Distribution of packages: ";

	for (const int i : best_case){
		std::cout << i << ' ';
	}

	std::cout << std::endl;

    return 0;

} 
  
