#include <iostream>

void brute_force(int *cells, const int cn, const int *things, const int tn);

void space(const int *cells, const int cn);


int main(void){
	const int cn = 5;
	const int tn = 10;
	int things[tn] = {50, 60, 50, 30, 70, 40, 20, 90, 20, 30};

	brute_force(cells, cn, things, tn);
	space(cells, cn);
}



void brute_force(const int cell_size, const int *things, const int tn){

}
