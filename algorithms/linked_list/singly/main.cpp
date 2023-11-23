#include <iostream>
#include "list.h"


int main(void){
	list my_list, empty;

	empty.back_insert(90);

	for (int i = 10; i < 40; i += 10)
	my_list.back_insert(i);

	empty = my_list;

	empty.traverse();

	// empty.traverse();
}
