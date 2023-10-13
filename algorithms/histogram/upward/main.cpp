#include <iostream>
#include <string.h>

int main(void){
	char buffer[1024] = {0};

	fgets(buffer, 1024, stdin);

	*strchr(buffer, '\n') = 0;
	int length = strlen(buffer);

	int frequency[256] = {0};

	for (int i = 0; i < length; i++)
		frequency[buffer[i]]++;

	int max = frequency[0];

	for (int i = 0; i < 256; i++){
		if (max < frequency[i]){
			max = frequency[i];
		}
	}

	for (int i = 0; i < 256; i++){
		if (frequency[i] == 0){
			frequency[i] = -1;
		}
	}

	std::cout << std::endl;



	// for (int i = 0; i < max; i++){
	// 	for (int j = 0; j < 256; j++){
	// 		if (frequency[j] > 0){
	// 			std::cout << static_cast<char>(j) << "  ";
	// 		}else if (frequency[j] == 0){
	// 			std::cout << "   ";
	// 			continue;
	// 		}else continue;
	// 		frequency[j]--;
	// 	}
	// 	std::cout << std::endl;
	// }



	while (max > 0){
		for (int j = 0; j < 256; j++){
			if (frequency[j] == max){
				std::cout << static_cast<char>(j) << "  ";
				frequency[j]--;
			}else if (frequency[j] > 0){
				std::cout << "   ";
				continue;
			}else continue;
		}
		std::cout << std::endl;
		max--;
	}
	
}
