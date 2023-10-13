#include <iostream>
#include <string.h>
#include "functions.h"

int x = 0;


int main(){

	int values[100] = {0};

	char string[] = "I don't";

	const int length = strlen(string);

	encode(string, values, 10);

	for (int i = 0; i < length; i++){
		printf("%d ", values[i]);
	}
	printf("\n");
}
