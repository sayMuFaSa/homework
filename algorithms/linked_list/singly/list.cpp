#ifndef MYLIST_CPP
#define MYLIST_CPP

#include "list.h"
#include <iostream>
#include <stdexcept>


list::list(const struct list& cp) : start(new node(0, nullptr))
{
	this->copy(cp);
}

struct list list::operator = (const struct list& cp){
	this->copy(cp);
	return *this;
}

void list::copy(const struct list& copied){

	if (start->next != nullptr){
		struct node *head = start->next;
		while(head != nullptr){
			struct node *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	struct node *head = start; // head here is actually the last added in algorithm
	
	struct node *cp = copied.start->next;

	while(cp != nullptr){
		head->next = new node(cp->val, nullptr);
		head = head->next;
		cp = cp->next;
	}
	head->next = nullptr;
}

void list::front_insert(const int val){ // Done
	start->next = new node(val, start->next);
}

void list::insert_before(const int val, const int tar){ // Done
	struct node *head = start;
	while(head->next != nullptr){
		if (head->next->val == val){
			head->next = new node(tar, head->next);
			return;
		}
		head = head->next;
	}

	(start->next == nullptr) 
		? throw std::runtime_error("Empty")
		: throw std::runtime_error("No such item");

}

void list::insert_after(const int val, const int tar){ // Done
	struct node *head = start->next;

	while(head != nullptr){
		if (head->val == val){
			head->next = new node(tar, head->next);
			return;
		}
		head = head->next;
	}

	(start->next == nullptr) 
		? throw std::runtime_error("Empty")
		: throw std::runtime_error("No such item");

}

void list::back_insert(const int val){ // Done
	struct node *head = start;

	while(head->next != nullptr){
		head = head->next;
	}

	head->next = new node(val, nullptr);
}

struct node* list::find_before(const int val){ // Done

	if (start->next == nullptr){
		throw std::runtime_error("Empty");
	}

	struct node *head = start->next;

	if (head->val == val){
		throw std::runtime_error("Accessing sentinel's not allowed");
	}

	while (head->next != nullptr){
		if (head->next->val == val){
			return head;
		}
		head = head->next;
	}
	


	return nullptr; // No such item in the list
}

struct node* list::find(const int val){ // Done
	struct node *head = start->next;

	if (head == nullptr) throw std::runtime_error("Empty");

	while (head != nullptr && head->val != val){
		head = head->next;
	}

	return head;
}

struct node* list::find_after(const int val){ // Done
	struct node *head = start;

	while (head->next != nullptr){
		if (head->val == val && head != start) return head->next;
		head = head->next;
	}

	return (head == start) 
		? throw std::runtime_error("Empty")
		: nullptr;
}

void list::erase_front(){
	if (start == nullptr){
		throw std::runtime_error("Empty");
	}

	struct node *tmp = start->next;

	start->next = start->next->next;

	delete tmp;

}

void list::erase_before(const int val){ // Done
	if (start->next == nullptr){
		throw std::runtime_error("Empty");
	}
	
	struct node *head = start;

	while (head->next->next != nullptr){
		if (head->next->next->val == val){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
		}
		head = head->next;
	}

	(head == start) 
		? throw std::runtime_error("Nothing before the item exists")
		: throw std::runtime_error("No such item");
}

void list::erase(const int val){ // Done
	struct node *head = start;

	while (head->next != nullptr) {
		if (head->next->val == val){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
		}
		head = head->next;
	}

	(start->next == nullptr) 
		? throw std::runtime_error("Empty")
		: throw std::runtime_error("No such element");

}

void list::erase_after(const int val){
	struct node *head = start;

	while (head->next != nullptr){
		if (head->val == val && head != start){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
		}
		head = head->next;
	}

	(start->next == nullptr) 
		? throw std::runtime_error("Empty")
		: throw std::runtime_error("No such element");
}

void list::erase_back(){ // Done
	if (start->next == nullptr){
		std::runtime_error("Empty");
	}

	struct node *head = start;

	while (head->next->next != nullptr){
		head = head->next;
	}

	struct node *tmp = head->next;

	head->next = nullptr;

	delete tmp;

}

list::~list(){ // Done
	 struct node *head = start;

	while(head->next != nullptr){
		struct node *tmp = head;
		head = head->next;
		delete tmp;
	}

	delete head;
}


void list::traverse(){ // Done
	struct node *head = start;

	if (head->next == nullptr) {
		throw std::runtime_error("Empty");
	}else head = head->next;

	std::cout << head->val;

	while (head->next != nullptr){
		head = head->next;
		std::cout << " --> " << head->val;
	}
	std::cout << std::endl;
};

#endif
