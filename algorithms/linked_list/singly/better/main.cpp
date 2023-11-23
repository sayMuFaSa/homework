#include <iostream>
#include "list.h"
#include <stdlib.h>

namespace s = singly;

int main(void){
	s::list my_list {1, 2, 3};

	s::list::iterator it = my_list.end();

	// Let's iterate over each element
	
	for (const int a : my_list){
		std::cout << a * 2 << ' ';
	}
	
}
