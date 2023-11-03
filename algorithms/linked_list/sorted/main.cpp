#include <iostream>
#include "list.h"


int main(void){
	list my_list, empty;

	my_list.insert(90);

	my_list.insert(20);

	my_list.insert(100);

	my_list.insert(95);

	my_list.insert(10);

	my_list.insert(100);

	my_list.insert(10);
	
	my_list.insert(20);

	my_list.erase(90);
	
	my_list.traverse();

	// empty.traverse();
}
