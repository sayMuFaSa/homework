#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP
#include "functions.h"
#include <string.h>


void encode(char *string, int *const ptr, const int a, const int b, const int c)
{
	const int len = strlen(string);
	term = seed;



	for (int i = 0; i < len; i++){
		ptr[i] = string[i] + rand(string[i], a, b, c);
	}

}


int rand(const int ch, const int a, const int b, const int c)
{
	term = (a * term + b) % c;

	return term;
}

// void decode(const int *in, const int len, char* const out, const int seed)
// {
// 	for (int i = 0; i < len; i++){
// 		out[i] = in[i] - rand(in[i], seed);
// 	}
//
// }

void encoder::operator()(char *string, int * ptr) const{
	const int len = strlen(string);
	term = seed;



	for (int i = 0; i < len; i++){
		ptr[i] = string[i] + rand(string[i], a, b, c);
	}
}

void decoder::operator()(const int* in, const int len, char* const out, const int seed)const{
	term = seed;
	for (int i = 0; i < len; i++){
		out[i] = in[i] - rand(in[i], a, b, c);
	}
}

bool check(const char *seq, const int length)
{
	const int ascii = 256;
	int frequency[ascii] = {0};

	for (int i = 0; i < length; i++){
		if (seq[i] < 0) return false;
		frequency[seq[i]]++;
	}

	int max1 = 't';
	int max2 = 'e';

	for (int i = 0; i < ascii; i++){
		if (frequency[i] > frequency[max1] && i != ' '){
			max2 = max1;
			max1 = i;
		}
	}

	if ((max1 == 't' || max1 == 'e') && (max2 == 'e' || max2 == 't')){
		return true;
	}

	return false;
}

void sseed(const int a){
	seed = a;
}

int term = 0;

int seed = 0;

#endif
