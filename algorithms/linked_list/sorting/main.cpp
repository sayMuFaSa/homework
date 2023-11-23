#include <iostream>
#include "list.h"
#include "sort.h"

int main(void){
	list my_list, empty;


	my_list.back_insert(90);

	my_list.back_insert(40);

	my_list.back_insert(20);

	my_list.back_insert(100);

	my_list.back_insert(100);

	my_list.traverse();

	ssort(my_list, empty);

	empty.traverse();
}
