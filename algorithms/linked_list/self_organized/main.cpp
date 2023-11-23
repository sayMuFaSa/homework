#include <iostream>
#include "list.h" // singly linked list
#include <stdexcept>

class swapping : public list { // swap method
public:
	struct node *find(const int val);
};

class move_to_front : public list { // MTF method
public:
	struct node *find(const int val);
};

int main(void){
	swapping first;

	first.front_insert(10);

	first.front_insert(20);

	first.front_insert(30);

	first.find(10);

	first.find(20);
	
	first.find(20);

	first.find(10);

	first.traverse();
}

struct node* move_to_front::find(const int val){
	if (start->next == nullptr){
		throw std::runtime_error("Empty");
	}

	struct node *head = start->next;

	if (head->val == val){
		return head;
	}

	while (head->next != nullptr){
		if (head->next->val == val){
			struct node* moving_item = head->next;
			head->next = moving_item->next;
			moving_item->next = start->next;
			start->next = moving_item;
			return start->next;
		}
		head = head->next;
	}
	
	return nullptr; // No such item in the list

}

struct node* swapping::find(const int val){
	if (start->next == nullptr){
		throw std::runtime_error("Empty");
	}

	struct node *head = start;

	if (head->next->val == val){
		return head->next;
	}

	if (head->next->next == nullptr) return nullptr;

	while(head->next->next != nullptr){
		if (head->next->next->val == val){
			struct node *to_front = head->next->next;
			struct node *to_back = head->next;
			head->next = to_front;
			to_back->next = to_front->next;
			to_front->next = to_back;
		}
		head = head->next;
	}

	return nullptr;
}
