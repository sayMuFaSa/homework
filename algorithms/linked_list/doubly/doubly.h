#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include <initializer_list>
#include <iostream>

namespace doubly{

struct node {
	int val;
	struct node* prev;
	struct node *next;
	node(const int v, node* p = 0, node* n = 0) // set prev and next to nullptr by default
		: val(v), prev(p), next(n)  { }
};

struct list{
	struct node *first;
	struct node *last;

	// constructors
	list() : first(new node(0)), last(new node(0)) 
	{
		first->next = last;
		last->prev = first;
	}

	list(const std::initializer_list<int>& src) :  first(new node(0)), last(new node(0))
	{
		first->next = last;
		last->prev = first;
		for (const int i : src){
			back_insert(i);
		}
	}

	list(const list& src)
	{
		struct node* head = src.first->next;

		while(head != src.last){
			struct node* after_me = last->prev;
			after_me->next = new node(head->val, last->prev, last);
			last->prev = after_me->next;
			head = first->next;
		}
	}
	
	// insertion
	void front_insert(const int v){
		insert_after(first, v);	
	}

	void insert_before(struct node* before_me, const int v)
	{
		before_me->prev->next = new node(v, before_me->prev, before_me);
		before_me->next->prev = before_me;
	}

	void insert_after(struct node* after_me, const int v)
	{
		after_me->next = new node(v, after_me, after_me->next);
		after_me->next->next->prev = after_me->next;
	}

	void back_insert(const int val)
	{
		struct node *tmp = last->prev;
		last->prev = new node(val, tmp, last);
		tmp->next = last->prev;
	}

	// searching
	struct node* find(const int tar)
	{
		struct node* head = first->next;
		if (head == nullptr) throw std::runtime_error("Searching in an empty list");
	
		while(head != nullptr && head->val != tar){
			head = head->next;
		}
	
		return head;
	}

	// deletion
	void erase(const struct node* tar)
	{
		struct node* before_me = tar->prev;
		struct node* after_me = tar->next;

		before_me->next = after_me;
		after_me->prev = before_me;

		delete tar;
	}

	

	void traverse()
	{
		struct node *head = first->next;

		if (head) {
			std::cout << head->val;
			head = head->next;
		} else {
			std::cout << "Empty list" << '\n';
			return;
		}

		while (head != last){
			std::cout << " <-> " << head->val;
			head = head->next;
		}

		std::cout << std::endl;
	}

	void clear()
	{
		struct node* head = first->next;
		while(head != last){
			struct node* tmp = head;
			head = head->next;
			delete tmp;
		}
		first->next = last;
		last->prev = first;
	}

	~list()
	{
		clear();
		delete first;
		delete last;
	}

	// iterator implementation
	struct iterator {
		struct node* item;

		iterator();
		struct iterator& operator++(int);
		struct iterator& operator--(int);
		struct iterator& operator++();
		struct iterator& operator--();
	};

	
	// iterator related methods
	struct iterator begin();
	struct iterator end();
	struct iterator rbegin();
	struct iterator rend();

};

};


#endif
