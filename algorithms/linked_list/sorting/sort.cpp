#ifndef MYSORT_CPP
#define MYSORT_CPP

#include "sort.h"

void isort(const struct list& l, struct list& s){ // s means sorted
	struct node *old_s = l.start->next;

	while (old_s != nullptr){
		struct node *next = new node(old_s->val, nullptr);

		old_s = old_s->next;

		struct node *after_me = s.start;

		while (after_me->next != nullptr && after_me->next->val < next->val){
			after_me = after_me->next;
		}

		next->next = after_me->next;

		after_me->next = next;
	}
}

void ssort(struct list& l, struct list& s){ // s means sorted
	while(l.start->next != nullptr){
		struct node *best_after_me = l.start;

		int best_val = best_after_me->next->val;

		struct node *after_me = l.start->next;

		while(after_me->next != nullptr){
			if (after_me->next->val > best_val){
				best_after_me = after_me;
				best_val = after_me->next->val;
			}
			after_me = after_me->next;
		}

		// Remove the best cell from the unsorted list.
		struct node *best = new node (best_after_me->next->val, best_after_me->next->next);
		best_after_me->next = best->next;

		// Add the best cell at the beginning of the sorted list.
		best->next = s.start->next;
		s.start->next = best;
	}
}

#endif
