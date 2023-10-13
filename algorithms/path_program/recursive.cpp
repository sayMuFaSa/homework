#include <iostream>
#include <vector>

// typedef enum {
// 	A, B, C, D
// } vertex;

const unsigned int N = 4;

int vector[N + 1];

unsigned int total;

bool flag = true;

void traverse(int position);

const bool graph[N][N] = 
	{
	/*	  A	B	C 	D	*/
	/* A */	 {0,	1,	0,	1},
	/* B */	 {1,	0,	1,	0},
	/* C */	 {0,	1,	0,	1},
	/* D */	 {1,	0,	1,	0}
};

int main(void){

	total = 0;

	traverse(0);

	

}


void traverse(int position){

	if (position < N + 1){
		for (int index = 0; index <= N; index++){
			traverse(position + 1);
		}
	}else {
		// bool flag = true;
		//
		// total++;
		//
		// for (int i = 0; i < N; i++){
		// 	if (!graph[vector[i]][vector[i + 1]]){
		// 		flag = false;
		// 		break;
		// 	}
		// }



		if (flag){
			
			if (vector[0] == 0 && vector[N] == 0){
				for (int j = 0; j < N - 1; i++){
					for (int j = i + 1; j < N; j++){
						if (vector[i] == vector[j]){
							flag = false;
						}	
					}
				}
			}
		}
	}
}







