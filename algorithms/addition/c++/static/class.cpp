#include "class.h"
#include <string.h>
#include <stdint.h>

number::number(){
	memset(digits, 0, MAX_LENGTH);
	length = 0;
}


number number::operator+(const number& my_num){
	number sum;

	uint8_t carry = 0;
	int most = (my_num.length > length) ? my_num.length : length;


	for (int i = 0; i < most; i++){
		sum.digits[i] = carry + (digits[i] + my_num.digits[i]);
		carry = sum.digits[i] / 10;
		sum.digits[i] %= 10;
	}

	if(carry == 1){
		if (most + 1 > MAX_LENGTH){
			sum.length = -1;
			return sum;
		}
		sum.digits[most] = 1;
		sum.length = most + 1;
		return sum;
	}

	sum.length = most;
	
	
	return sum;
}







number number::operator=(const char* as_string){
	length = strlen(as_string);
	
	
	memset(digits, 0, MAX_LENGTH);

	for(int i = 0; i < length; i++){
		digits[length - 1 - i] = as_string[i] - '0';
	}

	return *this;
}

number::number(const char* as_string){
	*this = as_string;
}

void number::stringify(char* buffer){
	memset(buffer, 0, MAX_LENGTH);
	for (int i = 0; i < length; i++){
		buffer[i] = digits[length - i - 1] + '0';
	}
}

number number::operator=(const number& target){
	if(this == &target){
		return *this;
	}
	memset(digits, 0, MAX_LENGTH);
	
	length = target.length;
	memcpy(digits, target.digits, target.length);

	
	return *this;
}


bool number::error(){
	if(length < 0) return true;

	else return false;
}


// std::istream& operator >> (std::istream& stream, number my_num){
// 	char buffer[MAX_LENGTH];
// 	fgets(buffer, MAX_LENGTH, stdin);
// 	my_num = buffer;
// 	return stream;
// }

