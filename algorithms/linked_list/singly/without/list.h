#ifndef MYLIST_H
#define MYLIST_H

enum err_code{
no_error, EMMPTY, NOMATCH, OOR, // out of range
LONE // only one element
};

extern err_code err;

struct list {
	struct node* start = nullptr;
	void insert_after(const int val, const int tar);
	void insert_before(const int val, const int tar);
	void frontinsert(const int val);
	void backinsert(const int val);
	void erase(const int val);
	void traverse();
	void erase_before(int val);
	// void erase_after(const int val);
	// void erase_front(const int val);
	// void erase_end(const int val);
	struct node *find(const int val);
	struct node *find_before(const int val);
	struct node *find_after(const int val);
	~list();
};


struct node {
	int val;
	struct node *next;
	node (const int v, node* p) : val(v), next(p) { }
};

#endif
