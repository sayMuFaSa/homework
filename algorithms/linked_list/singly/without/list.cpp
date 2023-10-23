#ifndef MYLIST_CPP
#define MYLIST_CPP

#include "list.h"
#include <iostream>

err_code err = no_error;

void list::insert_after(const int val, const int tar){
	if (start == nullptr){
		err = EMMPTY;
		return;
	}
	

	struct node *head = start;

	while(head->next != nullptr){
		if (head->val == val){
			head->next = new node(tar, head->next);
			return;
		}
		head = head->next;
	}

	err = NOMATCH;
}

void list::backinsert(const int val){

	if (start == nullptr){
		start = new node(val, nullptr);
		return;
	}
	node *head = start;

	while(head->next != nullptr){
		head = head->next;
	}

	head->next = new node(val, nullptr);
}


struct node* list::find(const int val){
	if (start == nullptr){
		err = EMMPTY;
		return nullptr;
	}
	struct node *head = start;

	while (head != nullptr && head->val != val){
		head = head->next;
	}

	return head;
}

struct node* list::find_after(const int val){

	if (start == nullptr){
		err = EMMPTY;
		return nullptr;
	}

	if (start->val == val && start->next == nullptr){
		err = OOR;
		return nullptr;
	}

	struct node *head = start;

	while (head->next != nullptr){
		if (head->val) return head->next;
		head = head->next;
	}

	if (head->val == val) {
		err = OOR;
		return nullptr;
	}
	
	err = NOMATCH;
	return nullptr;
}

void list::frontinsert(const int val){
	start = new node(val, start);
}

void list::insert_before(const int val, const int tar){
	if (start == nullptr){
		err = EMMPTY;
		return;
	}

	struct node *head = start;

	do{
		if (head->next->val == val){
			head->next = new node(tar, head->next);
			return;
		}

		head = head->next;
	}while(head->next != nullptr);

	err = NOMATCH;
}

struct node* list::find_before(const int val){
	if (!start){
		err = EMMPTY;
		return nullptr;
	}

	if (start->val == val){
		err = OOR;
		return nullptr;
	}

	if (start->next == nullptr){
		err = NOMATCH;
		return nullptr;
	}

	struct node *head = start;

	while (head->next != nullptr){
		if (head->next->val == val){
			return head;
		}
		head = head->next;
	}

	err = NOMATCH;

	return nullptr;
}

list::~list(){
	struct node *head = nullptr;

	if (start == nullptr) return;

	head = start;

	while(head->next != nullptr){
		struct node *tmp = head;
		head = tmp->next;
		delete tmp;
	}

	delete head;
}

void list::erase(const int val){
	struct node *head = start;
	if (head == nullptr) {
		err = EMMPTY;
		return;
	}

	while (head != nullptr) {
		if (head->next->val == val){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
			return;
		}
		head = head->next;
	}

	err = NOMATCH;
}

void list::erase_before(const int val){
	struct node *head = start;
	if (head == nullptr){
		err = EMMPTY;
		return;
	}

	if (head->next == nullptr){
		if (head->val == val){
			err = LONE;
			return;
		}
		err = OOR;
		return;
	}

	if (head->next->val == val){
		struct node *tmp = start;
		start = start->next;
		delete start;
	}

	while (head->next != nullptr){
		if (head->next->next->val == val){
			struct node *tmp = head->next;
			head->next = head->next->next;
			delete tmp;
		}
		head = head->next;
	}
	
}




void list::traverse(){
	if (start == nullptr){
		err = EMMPTY;
	}

	struct node *head = start;

	std::cout << head->val;

	while (head->next != nullptr){
		head = head->next;
		std::cout << " -> " << head->val;
	}
	std::cout << std::endl;
};

#endif
