#include <iostream>
#include "list.h"

int main(void){
	list my_list {1, 2, 3, 4};

	my_list.insert(90);

	my_list.insert(100);

	my_list.insert_after(4, 20);

	my_list.traverse();
}
