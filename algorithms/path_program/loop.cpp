#include <iostream>
#include <vector>
#include <jack/net.h>

// typedef enum {
// 	A, B, C, D
// } vertex;

const unsigned int N = 4;

int vector[N + 1];

unsigned int total;


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

void traverse(){
	for (int i = 0; i < N + 1; i++){
		for (int )
	}
}

