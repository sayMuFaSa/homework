#ifndef MY_CIRCULAR_LIST_H
#define MY_CIRCULAR_LIST_H

#include <initializer_list>

class node{
public:
	node *next;
	int val;
	node(const int v, node *p) : val(v), next(p) {}
};

class list{
public:
	node *start;
	list(std::initializer_list<int> init);
	void insert_before(const int val);
	void insert_after(const int val, const int tar);
	void insert(const int val); // just after the element which is linked to by sentinel
	void erase(const int val);
	void traverse();
	~list();
};

#endif
