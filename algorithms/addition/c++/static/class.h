#include <iostream>
#include <string.h>

#define MAX_LENGTH 100

class number;

std::istream& operator >> (const std::istream&, const number&);

class number {
public:
	char digits[MAX_LENGTH];
	int length;
	number operator+(const number&);
	number operator=(const char*);
	number operator=(const number&);
	number(const char* as_string);
	number();

	void stringify(char* buffer);
	bool error();
// private:

	friend std::istream& operator >> (std::istream& my_stream, number& my_num) {
		char buffer[MAX_LENGTH] = {0};
		do {
			// fgets(buffer, MAX_LENGTH, stdin);
			my_stream.getline(buffer, MAX_LENGTH);
		}while(buffer[0] == '\0');
		my_num = buffer;
		// *strchr(buffer, '\n') = '\0';
		// my_stream.getline(buffer, MAX_LENGTH);
		// my_num = buffer;
		return my_stream;
	};
	friend std::ostream& operator << (std::ostream& my_stream, number& my_num){
		char buffer[MAX_LENGTH] = {0};

		my_num.stringify(buffer);
		
		my_stream << buffer;
		return my_stream;
	}
};

// extern std::istream& operator >>(std::istream&, number&);

