#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <string.h>
#include <errno.h>
#include <vector>
#include <utility>
#include <limits.h>
#include <filesystem>
#include <format>

namespace fs = std::filesystem;


void usage();

void find_in_dir(const char *path, const char* pattern);

int find_in_cstring(const char *str, const char *substr, int length, int sub_length);

int find_in_file(const std::string& path, const char *pattern);

int find_in_string(const std::string& string, const std::string& pattern);

int main(int argc, char **argv)
{
	int number;
	char *path = nullptr;
	char *pattern = nullptr;
	
	if (argc == 4){
		path = argv[2];
		pattern = argv[3];

		if(!strcmp(argv[1], "-d") || !strcmp(argv[1], "--directory")) {
			find_in_dir(path, pattern);
			return 0;
		}else if (!strcmp(argv[1], "-f") || !strcmp(argv[1], "--file")) { }

		else goto Help;

	} else if (argc == 3){
		path = argv[1];
		pattern = argv[2];
	} 
	else goto Help;

	std::cout << path << ": ";


	if ((number = find_in_file(path, pattern)) >= 0){
		std::cout << number;
	}

	std::cout << std::endl;

	return 0;

Help: // Should not reach

	usage();
	return 1;

}

void usage()
{

const char *text = R"(Usage:	search [OPTIONS] PATTERN
-f, --file 		search in a regular file(default)
-d, --search		search recursively in a directory
)";

	std::cerr << text << std::endl;
}

void find_in_dir(const char *path, const char *pattern)
{
	fs::path dir = path;

	for (const auto& file : fs::recursive_directory_iterator(dir)){

		if (fs::is_regular_file(file)){
			int number = find_in_file(file.path().string(), pattern);
			const std::string& file_name = file.path().string();

			if (number != 0){
				std::cout << file_name << ": " << number << std::endl;
			}
		}

	}
}


int find_in_file(const std::string& path, const char *pattern)
{
	static std::stringstream stream;

	std::ifstream file;

	file.open(path);

	if (file.fail()){
		std::cout << strerror(errno);
		exit(1);
		return -1;
	}

	stream << file.rdbuf();

	std::string contents = stream.str();

	file.close();

	stream.clear();

	stream.str("");

	return find_in_string(contents, pattern);

	// return find_in_cstring(&contents[0], pattern, contents.length(), strlen(pattern));

}




int find_in_string(const std::string& string, const std::string& pattern)
{
	const char *substr = &pattern[0];
	const char *str = &string[0];
	const int sub_length = pattern.length();
	const int it = string.length() - pattern.length() + 1;

	int ctr = 0;
	int flag = 0;

	for (int i = 0; i < it; i++){
		flag = 1;

		for (int j = 0; j < sub_length; j++){

			if (string[i + j] != pattern[j]){
				flag = 0;
				break;
			}
		}
		if (flag) ctr++;
	}
		
	return ctr;
}




// int find_in_cstring(const char *str, const char *substr,  int str_length, int sub_length)
// {
// 	const int it = str_length - sub_length + 1;
//
// 	int ctr = 0;
// 	int flag = 0;
//
// 	if (it < 0) return 0;
//
// 	for (int i = 0; i < it; i++){
// 		flag = 1;
//
// 		for (int j = 0; j < sub_length; j++){
//
// 			if (str[i + j] != substr[j]){
// 				flag = 0;
// 				break;
// 			}
// 		}
// 		if (flag) ctr++;
// 	}
// 		
//
// 	return ctr;
// }

