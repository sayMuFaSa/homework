#include <iostream>
#include "list.h"


int main(void){
	list my_list;

	my_list.backinsert(10);

	my_list.backinsert(20);

	my_list.backinsert(30);

	my_list.insert_after(20, 50);

	my_list.frontinsert(40);

	my_list.insert_before(10, 70);

	struct node *ptr = my_list.find(50);

	std::cout << "The value at that point: " << ptr->val << std::endl;

	my_list.traverse();

	ptr = my_list.find_after(40);


	std::cout << ptr->val << " is after the entry " << 40 << std::endl;
}
