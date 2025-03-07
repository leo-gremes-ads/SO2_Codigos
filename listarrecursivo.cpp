#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void listar(std::string path)
{
	for (const auto & entry : fs::directory_iterator(path)) {
		std::cout << entry.path() << std::endl;
		if (is_directory(entry.path()))
			listar(entry.path());
	}
}

int main(int argc, char* argv[])
{
	// listar("/home");		-> Exemplo do livro, mudei para poder listar o conteúdo do diretório a escolha
	if (argc != 2)
		return 1;
	listar(argv[1]);
	return 0;
}
