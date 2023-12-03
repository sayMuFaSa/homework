#ifndef MY_LIST_H
#define MY_LIST_H

#include <initializer_list>
#include <stdexcept>

namespace singly{

struct node {
	int val;
	class node* next;
	node(const int v, struct node* p) : val(v), next(p) {}
};

struct list{
	struct node* start; // sentinel
	
	// constructors
	list() : start(new node(0, nullptr)) {}
	list(const std::initializer_list<int>& init);
	list(const list& src);

	// copying
	list& operator= (const list& src);

	// insertion
	void front_insert(const int val);
	void insert_after(struct node* after_me, const int val);
	void insert_after(const int after_me, const int val); // insert after the first occurence of after_me
	
	// searching
	struct node *find(const int tar); // find the first occurence of tar
	struct node* find_before(const int tar); // find the element before the first occurence of tar
	
	// deletion
	void erase_after(struct node* after_me);
	int remove(const int val);

	void traverse();
	void clear(); // delete all the nodes except sentinel
	~list();


	// iterator implementation
	struct iterator {
		struct node *item;
		iterator() : item(nullptr) { }
		iterator(const struct iterator& source) : item(source.item) {}
		struct iterator& operator= (const struct iterator& source){
			item = source.item;
			return *this;
		}

		int operator* (){ // dereference operator
			if (item == nullptr) throw std::runtime_error("Iterating over empty list or the last item was already reached.");
			return item->val;
		}

		struct iterator operator++(){ // prefix increment
			item = item->next;
			return *this;
		}

		struct iterator operator++(int){ // postfix increment
			const struct iterator tmp = *this;
			item = item->next;
			return tmp; 
		}
		
		bool operator!= (const struct iterator& cmp){
			return item != cmp.item;
		}

		bool operator== (const struct iterator& cmp){
			return item == cmp.item;
		}

	};

	struct iterator begin(){
		iterator tmp;
		tmp.item = start->next;
		return tmp;
	}

	struct iterator end(){
		iterator tmp;
		tmp.item = nullptr;
		return tmp;
	}

};

};

#endif
