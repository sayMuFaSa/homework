#ifndef	MY_LIST_CPP
#define	MY_LIST_CPP

#include <iostream>
#include "list.h"

namespace singly{

list::list(std::initializer_list<int> init) {
	start = new node(0, nullptr);

	struct node *head = start;

	for (int a : init){
		head->next = new node(a, nullptr);
		head = head->next;
	}
}

void list::front_insert	(const int val){
	start->next = new node(val, start->next);
}

void list::insert_after(struct node* after_me, const int val){
	after_me->next = new node(val, after_me->next);
}

void list::insert_after(const int tar, const int val){
	this->insert_after(this->find(tar), val);
}

struct node* list::find_before(const int tar){
	struct node* head = start->next;
	if (head == nullptr) throw std::runtime_error("Searching in empty list");

	while(head->next != nullptr && head->next->val != tar){
		head = head->next;
	}

	return head;
}

struct node* list::find(const int tar){
	struct node* head = start->next;
	if (head == nullptr) throw std::runtime_error("Searching in empty list");
	
	while(head != nullptr && head->val != tar){
		head = head->next;
	}

	return head; // returns nullptr if not found
}

void list::erase_after(struct node* after_me){
	if (after_me == start) throw std::runtime_error("Erasing sentinel is not allowed");

	if (start->next == nullptr) throw std::runtime_error("EMPTY LIST NOTHING TO ERASE");

	struct node *tmp = after_me->next;

	after_me->next = tmp->next;

	delete tmp;
}

void list::traverse(){
	struct node *head = start->next;

	if (head == nullptr){
		std::cout << "Empty list" << std::endl; return;
	}else{
		std::cout << head->val;
		head = head->next;
	}

	while(head != nullptr){
		std::cout << " -> " << head->val;
		head = head->next;
	}
	std::cout << std::endl;
}

void list::clear(){
	struct node *head = start->next;

	if (head == nullptr) return;

	while(head != nullptr){
		struct node *tmp = head;
		head = head->next;
		delete tmp;
	}

	start->next = nullptr;
}

list::~list(){
	this->clear();
	delete start;
	start = nullptr;
}

};

#endif
