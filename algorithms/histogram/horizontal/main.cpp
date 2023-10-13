#include <iostream>
#include <string.h>
#include <iomanip>

int main(void){
	char buffer[1024] = {0};

	std::cout << "Enter some text" << std::endl;

	fgets(buffer, 1024, stdin);

	*strchr(buffer, '\n') = 0;
	int length = strlen(buffer);

	int frequency[256] = {0};

	for (int i = 0; i < length; i++)
		frequency[buffer[i]]++;


	for (int i = 0; i < 256; i++){
		if (frequency[i] != 0){
			for (int j = 0; j < frequency[i]; j++){
				std::cout << static_cast<char>(i);
			}
			std::cout << std::setw(35 - frequency[i]) << frequency[i];
			std::cout << std::endl;
		}
	}
	
}
