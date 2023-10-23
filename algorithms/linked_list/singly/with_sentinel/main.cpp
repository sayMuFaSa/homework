#include <iostream>
#include "list.h"


int main(void){
	list my_list, empty;

	for (int i = 10; i < 40; i += 10)
	my_list.back_insert(i);

	my_list.erase_back();

	empty.erase_back();

	my_list.traverse();

	// empty.traverse();
}
