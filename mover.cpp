#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
		exit(1);
	if(rename(argv[1], argv[2]) != 0) {
		perror("Erro ao renomear arquivo");
		exit(2);
	} else
		cout << "Arquivo renomeado" << endl;
	return 0;
}
