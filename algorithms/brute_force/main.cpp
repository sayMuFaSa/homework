#include <iostream>

void brute_force(int *cells, const int cn, const int *things, const int tn);

void space(const int *cells, const int cn);

int main(void){
	const int cn = 5;
	const int tn = 10;
	int cells[cn] = {100, 100, 100, 100, 100}, things[tn] = {50, 60, 50, 30, 70, 40, 20, 90, 20, 30};

	brute_force(cells, cn, things, tn);
	space(cells, cn);
}


void brute_force(int *cells, const int cn, const int *things, const int tn){
	int ccell = 0;
	for (int i = 0; i < tn; i++){
		int flag = 1;
		for (int j = 0; j < cn; j++){
			if (cells[j] >= things[i]){
				cells[j] -= things[i];
				std::cout << "Case " << i << " is in the cell " << j << std::endl;
				flag = 0;
				break;
			}
		}
		if (flag){
			std::cout << "Case " << i << " is dropped " << std::endl;
		}

	}
}

void space(const int *cells, const int cn){
	std::cout << "Amount of empty space in cells" << std::endl;
	for (int i = 0; i < cn; i++){
		std::cout << "Cell " << i << ": " << cells[i] << std::endl;
	}
}

