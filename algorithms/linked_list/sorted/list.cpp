#ifndef MYLIST_CPP
#define MYLIST_CPP

#include "list.h"
#include <iostream>

err_code err = no_error;

void list::insert(const int val){ // Done
	struct node *head = start;

	while (head->next != nullptr){
		if (head->next->val > val){
			head->next = new node(val, head->next);
			return;
		}
		head = head->next;
	}

	if (start->next == nullptr){
		start->next = new node(val, nullptr);
	}else head->next = new node(val, nullptr);
}

struct node* list::find_before(const int val){ // Done

	if (start->next == nullptr){
		err = EMMPTY;
		return nullptr;
	}
	struct node *head = start->next;

	if (head->val == val){
		err = OOR;
		return nullptr;
	}

	while (head->next != nullptr){
		if (head->next->val == val){
			return head;
		}
		head = head->next;
	}

	err = NOMATCH;

	return nullptr;
}

struct node* list::find(const int val){ // Done
	struct node *head = start;

	while (head != nullptr){
		if (head->val == val) return head;
		head = head->next;
	}

	err = (head == start) ? EMMPTY : NOMATCH;

	return nullptr;
}

struct node* list::find_after(const int val){ // Done
	struct node *head = start;

	while (head->next != nullptr){
		if (head->val == val && head != start) return head->next;
		head = head->next;
	}

	err = (head == start) ? EMMPTY : NOMATCH;
	
	return nullptr;
}

bool list::erase_front(){
	if (start == nullptr){
		err = EMMPTY;
		return false;
	}

	struct node *tmp = start->next;

	start->next = start->next->next;

	delete tmp;

	return true;
}

bool list::erase_before(const int val){ // Done
	if (start->next == nullptr){
		err = EMMPTY;
		return false;
	}
	
	struct node *head = start;

	while (head->next->next != nullptr){
		if (head->next->next->val == val){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
			return true;
		}
		head = head->next;
	}

	err = (head == start) ? LONE : NOMATCH;

	return false;
}

bool list::erase(const int val){ // Done
	struct node *head = start;

	while (head->next != nullptr) {
		if (head->next->val == val){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
			return true;
		}
		head = head->next;
	}

	err = (start->next == nullptr) ? EMMPTY : NOMATCH;

	return false;
}

bool list::erase_after(const int val){
	struct node *head = start;

	while (head->next != nullptr){
		if (head->val == val && head != start){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
		}
		head = head->next;
	}
	err = (start->next == nullptr) ? EMMPTY : NOMATCH;
	return false;
}

bool list::erase_back(){ // Done
	if (start->next == nullptr){
		err = EMMPTY;
		return false;
	}

	struct node *head = start;

	while (head->next->next != nullptr){
		head = head->next;
	}

	struct node *tmp = head->next;

	head->next = nullptr;

	delete tmp;

	return true;

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


bool list::traverse(){ // Done
	struct node *head = start;

	if (head->next == nullptr) {
		err = EMMPTY;
		return false;
	}else head = head->next;

	std::cout << head->val;

	while (head->next != nullptr){
		head = head->next;
		std::cout << " --> " << head->val;
	}
	std::cout << std::endl;
	return true;
};

#endif
