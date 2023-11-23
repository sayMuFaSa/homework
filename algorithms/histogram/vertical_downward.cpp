#include <iostream>
#include <string.h>

int main(void){
	char buffer[1024] = {0};

	std::cout << "Enter some text" << std::endl;

	fgets(buffer, 1024, stdin);

	*strchr(buffer, '\n') = 0;
	int length = strlen(buffer);

	int frequency[256] = {0};

	for (int i = 0; i < length; i++)
		frequency[buffer[i]]++;

	std::cout << std::endl;

	int max = frequency[0];

	for (int i = 0; i < 256; i++){
		if (max < frequency[i]){
			max = frequency[i];
		}
	}

	for (auto& i : frequency){
		if (i == 0) i = -1;
	}


	while (max > 0){
		for (int j = 0; j < 256; j++){
			if (frequency[j] > 0){
				std::cout << static_cast<char>(j) << "  ";
				frequency[j]--;
			}else if(frequency[j] == 0){
				std::cout << "   ";
			}
		}
		std::cout << std::endl;
		max--;
	}
	
}
