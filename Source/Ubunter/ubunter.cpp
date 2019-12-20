#include <iostream>
#include <fstream>
#include <string>


std::string getExecutablesName(std::string fpath) {
	
	int i = fpath.length() - 1;
	while (fpath[i] != '/' && fpath[i] != '\\') {
		i--;
	}
	
	int start = i + 1;
	return fpath.substr(start, fpath.length());
}

int main(int argc, char *argv[]) {
	
	if (argc < 2)
		return 0;
	
	std::ifstream tempFileTryRead("temp.ubtemp"); // an obvious #TODO is to generate a random tmp file using winapi
	
	if (tempFileTryRead.good()) {
		std::cout << "You have a \"temp.ubtemp\" file in your directory for some reason, please remove it and try again." << std::endl;
		system("pause");
		return 0;
	}
	
	tempFileTryRead.close();
	
	std::ofstream tempFile("temp.ubtemp");
	
	std::string fileName = getExecutablesName(std::string(argv[1]));
	
	tempFile << "./" << fileName;
	
	tempFile.close();
	
	system("C:/Windows/SysNative/bash.exe temp.ubtemp");
	
	system("del temp.ubtemp");
	
	return 0;
}

