#ifndef MY_CIRCULAR_LIST_CPP
#define MY_CIRCULAR_LIST_CPP


#include "list.h"
#include <iostream>

list::list(std::initializer_list<int> init){
	if (init.size() < 3){
		throw std::runtime_error("Circular list has to contain at least 3 items");
	}

	start = new node(0, nullptr);

	node *after_me = start;

	for (const int a : init){
		after_me->next = new node(a, nullptr);
		after_me = after_me->next;
	}

	after_me->next = start->next;
}

void list::insert(const int val){ // just after the element which is linked to by sentinel
	node *after_me = start->next;
	after_me->next = new node(val, after_me->next);
}

void list::insert_after(const int val, const int tar){
	node *after_me = start->next;

	const node *stop = start->next;

	while(after_me->next != stop){
		if (after_me->val == val){
			after_me->next = new node(tar, after_me->next);
			return;
		}
		after_me = after_me->next;
	}

	if (after_me->val != val) throw std::runtime_error("No such item");

	else after_me->next = new node(tar, after_me->next);

}

void list::traverse(){
	node *current = start->next;
	const node *first = start->next;

	std::cout << current->val;

	while (current->next != first){
		current = current->next;
		std::cout << " --> " << current->val;
	}

	std::cout << std::endl;
}

list::~list(){
	node *current = start->next->next;
	node *first = start->next;

	while(current != first){
		node *tmp = current;
		current = current->next;
		delete tmp;
	}
	delete first;
	delete start;
}

#endif
