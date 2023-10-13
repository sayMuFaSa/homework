#include <iostream>
#include <string.h>

class bignum {
public:
	// static char *internal_buffer;
	char *nums = nullptr;
	int length = 0;
	int max_length = 0;

	bignum() {}

	bignum operator+(const bignum&);
	bignum operator=(const char*);
	bignum operator=(const bignum&);
	bignum operator=(const std::string&);
	bignum (const std::string&);
	bignum(const char* as_string);
	bignum(const bignum&);
	bignum(bignum&&);

	~bignum(){
		std::cout << "Destructor" << std::endl;
		if(nums != nullptr){
			free(nums);
		}
	}


	void input(std::string& buffer);
	void stringify(char* buffer);
	bool error();
	
// private:
	
};

extern std::istream& operator >> (std::istream&, bignum&);

extern std::ostream& operator << (std::ostream&, const bignum&);

extern std::ostream& operator << (std::ostream&, bignum&&);


// extern std::istream& operator >>(std::istream&, number&);

