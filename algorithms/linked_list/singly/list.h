#ifndef MYLIST_H
#define MYLIST_H

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
	void insert_before(const int val, const int tar);
	void insert_after(const int val, const int tar);
	void back_insert(const int val);
	void erase(const int val);
	void traverse();
	void erase_front();
	void erase_before(int val);
	void erase_after(const int val);
	void erase_back();
	void copy(const struct list& copied);
	struct node *find(const int val);
	struct node *find_before(const int val);
	struct node *find_after(const int val);
	~list();
};




#endif
