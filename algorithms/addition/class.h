// rewrite with std::vector
#ifndef MY_BIGINT_H
#define MY_BIGINT_H

#include <iostream>
#include <string.h>
#include <stdint.h>

class bignum {
public:
	char *nums = nullptr;
	uint32_t length = 0;
	uint32_t max_length = 0;

	bignum() : nums(nullptr), length(0), max_length(0) {}

	bignum operator+(const bignum&);
	bignum& operator=(const char*);
	bignum& operator=(const bignum&);
	bignum& operator=(bignum&&);
	bignum& operator=(const std::string&);
	bignum(const std::string&);
	bignum (const char* as_string);
	bignum(const bignum&);
	bignum(bignum&&);

	~bignum(){
		if(nums != nullptr){
			free(nums);
		}
	}

};

extern std::istream& operator >> (std::istream&, bignum&);

extern std::ostream& operator << (std::ostream&, const bignum&);

extern std::ostream& operator << (std::ostream&, bignum&&);

#endif

