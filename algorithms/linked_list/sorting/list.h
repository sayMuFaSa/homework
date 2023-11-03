#ifndef MYLIST_H
#define MYLIST_H

enum err_code{
no_error, EMMPTY, NOMATCH, OOR, // out of range
LONE // only one element
};

extern err_code err;

struct node {
	int val;
	struct node *next;
	node (const int v, node* p) : val(v), next(p) { }
};

struct list {
	struct node* start;
	list() : start(new node(0, nullptr)){}
	list(const struct list& cp);
	struct list operator = (const struct list& cp);
	void front_insert(const int val);
	bool insert_before(const int val, const int tar);
	bool insert_after(const int val, const int tar);
	void back_insert(const int val);
	bool erase(const int val);
	bool traverse();
	bool erase_front();
	bool erase_before(int val);
	bool erase_after(const int val);
	bool erase_back();
	void copy(const struct list& copied);
	struct node *find(const int val);
	struct node *find_before(const int val);
	struct node *find_after(const int val);
	~list();
};




#endif
