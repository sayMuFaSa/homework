#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <filesystem>
#include <errno.h>
#include <format>

namespace fs = std::filesystem;


void usage(const char *prog);

void find_in_dir(const std::string& path, const std::string& pattern);

int find_in_file(const std::string& path, const std::string& pattern);

int find_in_string(const char*  string, const size_t length , const char *pattern, const size_t pattern_length);

int main(int argc, char **argv)
{
	std::string path;
	std::string pattern;
	char option;
	std::cout << "Search in a file or directory ? \n(f = file, d = directory): ";

	std::cin >> option;

	switch(option){
		case 'f':
			std::cout << "Enter path to the file: ";
			std::getline(std::cin >> std::ws, path);
			break;
		case 'd':
			std::cout << "Enter path to the directory: ";
			std::getline(std::cin >> std::ws, path);
			break;
		default:
			std::cerr << "Unknown option." << std::endl;
			return 1;
	}

	std::cout << "Enter the pattern: ";
	std::getline(std::cin, pattern);

	if (option == 'd'){
		find_in_dir(path, pattern);
		return 0;
	}

	int number;

	try {
		number = find_in_file(path, pattern);
	}catch(const std::exception& err){
		std::cerr << "An error occured\n" << err.what() << std::endl;
		return 1;
	}

	std::cout << path << ": " << number << std::endl;

	return 0;
}

void find_in_dir(const std::string& path, const std::string& pattern)
{
	int dir_ctr = 0;
	fs::path dir = path;

	for (const auto& file : fs::recursive_directory_iterator(dir)){

		if (fs::is_regular_file(file)){
			int number = find_in_file(file.path().string(), pattern);
			const std::string& file_name = file.path().string();

			if (number != 0){
				std::cout << file_name << ": " << number << std::endl;
				dir_ctr++;
			}
		}

	}

	if (dir_ctr == 0){
		std::cout << "No file in the directory [ " << path << " ] contains the pattern" << std::endl;
	}
}


int find_in_file(const std::string& path, const std::string& pattern)
{
	std::ifstream file;

	std::string line;
	int ctr = 0;

	file.open(path);

	if (file.fail()){
		throw std::runtime_error(std::format("Problem with file {} {}", path, strerror(errno)));
	}

	while(std::getline(file, line)){

		ctr += find_in_string(line.data(), line.length(), pattern.data(), pattern.length());
	}

	

	file.close();

	return ctr;

}




int find_in_string(const char *string, const size_t string_length, const char* pattern, const size_t pattern_length)
{
	if (string_length < pattern_length){
		return 0;
	}

	const size_t it = string_length - pattern_length + 1;
	int ctr = 0;

	for (size_t i = 0; i < it; i++){
		int flag = 1;

		for (size_t j = 0; j < pattern_length; j++){

			if (string[i + j] != pattern[j]){
				flag = 0;
				break;
			}
		}
		if (flag) ctr++;
	}

	return ctr;
}

