#include "doubly.h"

namespace d = doubly;

int main(void){
	d::list jack {1, 2, 3};
	jack.insert_before(jack.find(2), 20);

	jack.erase(jack.find(20));
	jack.traverse();
}
