#include <iostream>

using namespace std;

char *getExecutablesName(char *str) {
	int len = strlen(str);
	int i;
	for (i = len - 1; str[i] != '\\'; i--);
	return &str[++i];
}

int main(int argc, char *argv[]) {
	
	//fst arg is opener itself, second is the file to open
	
	if (argc < 2)
		return 0;
	
	FILE * temp = fopen("temp.ubtemp", "w");
	
	char *fileName = getExecutablesName(argv[1]);
	
	fprintf(temp, "./%s", fileName);
	
	fclose(temp);
	
	system("C:/Windows/SysNative/bash.exe temp.ubtemp");
	
	system("del temp.ubtemp");
	
	return 0;
}

