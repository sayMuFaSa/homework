#ifndef MY_BIGINT_CPP
#define MY_BIGINT_CPP

#include "class.h"
#include <string.h>
#include <stdint.h>
#include <unistd.h>


bignum::bignum(const bignum& target){
	length = 0;
	nums = nullptr;
	max_length = 0;

	if(this == &target){
		return;
	}
	
	length = target.length;

	nums = (char*) calloc(length, 1);


	memcpy(nums, target.nums, target.length);

}

bignum::bignum(bignum&& target){
	length = 0;
	nums = nullptr;
	max_length = 0;

	if(this == &target) return;
	
	length = target.length;

	nums = target.nums;

	target.nums = nullptr;
	target.length = 0;

}


bignum bignum::operator+(const bignum& my_num){
	bignum sum;
	uint8_t carry = 0;
	const bignum& bigger = (my_num.length > length) ? my_num : *this;
	const bignum& smaller = (my_num.length > length) ? *this : my_num;
	const int more = bigger.length;
	const int less = smaller.length;


	sum.nums = (char*) calloc(more, 1);
	max_length = more;
	length = more;



	for (int i = 0; i < less; i++){
		sum.nums[i] = carry + smaller.nums[i] + bigger.nums[i];
		carry = sum.nums[i] / 10;
		sum.nums[i] %= 10;
	}


	for(int i = less; i < more; i++){
		sum.nums[i] = carry + bigger.nums[i];
		carry = sum.nums[i] / 10;
		sum.nums[i] %= 10;
	}



	if(carry == 1){
		
		sum.nums = (char*) realloc(sum.nums, max_length * 2);
		sum.nums[more] = 1;

		sum.length = more + 1;
		sum.max_length = more * 2;
		return sum;
	}

	sum.length = more;


	return sum;
}






bignum bignum::operator=(const char* as_string){
	length = strlen(as_string);

	if(nums == nullptr) {
		nums = (char*) calloc(length, 1);
		max_length = length;
	}
	else if(max_length < length){
		free(nums);
		nums = (char*) calloc(length, 1);
		max_length = length;
	}


	for(unsigned int i = 0; i < length; i++){
		nums[length - 1 - i] = as_string[i] - '0';
	}


	return *this;
}

bignum::bignum(const char* as_string){
	*this = as_string;
}



bignum bignum::operator=(const bignum& target){
	if(this == &target){
		return *this;
	}
	
	length = target.length;

	nums = (char*) calloc(length, 1);


	memcpy(nums, target.nums, target.length);


	return *this;
}




bignum bignum::operator=(const std::string& string){
	if (nums == nullptr) nums = (char*) calloc(string.length(), 1);
	
	else if(string.length() >= length){
		free(nums);
		nums = (char*) calloc(string.length(), 1);
	}
	length = string.length();
	max_length = length;




	for(unsigned int i = 0; i < length; i++){
		nums[length - 1 - i] = string[i] - '0';
	}


	return *this;
}

bignum::bignum(const std::string& string){
	*this = string;
}

std::istream& operator >> (std::istream& my_stream, bignum& my_num) {
		std::string buffer;


		std::cin >> buffer;
		my_num = buffer;

		return my_stream;
}



std::ostream& operator << (std::ostream& my_stream, const bignum& my_num){
		std::string buffer;

		for(int i = my_num.length - 1; i >= 0; i--){
			buffer += my_num.nums[i] + '0';
		}

		std::cout << buffer;
		
		return my_stream;
}

std::ostream& operator << (std::ostream& stream, bignum&& my_num){
	std::string buffer;

	for(int i = my_num.length - 1; i >= 0; i--){
		buffer += my_num.nums[i] + '0';
	}

	std::cout << buffer;

	return stream;
}


#endif
