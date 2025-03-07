#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	// std::string=path = "/";		-> Exemplo do livro, eu mudei para exibir a listagem de um diretório a escolha ao invés do diretório raiz
	if (argc != 2)
		return 1;
	std::string path = argv[1];
	for (const auto & entry: fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;
	return 0;
}
