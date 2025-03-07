/* programa para copiar um arquivo de texto */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// ifndef para possibilidade de mudar as constantes em tempo de compilação
#ifndef BUF_SIZE
# define BUF_SIZE 4096
#endif

#ifndef OUTPUT_MODE
# define OUTPUT_MODE 0640
#endif

int main(int argc, char* argv[])
{
	int fd_in, fd_out, r_count, w_count; // file descriptor de entrada, de saída, contagem de bytes de leitura e escrita
	char buffer[BUF_SIZE]; // variável onde será armazenada o conteúdo lido

	if (argc != 3)
		exit(1);
	fd_in = open(argv[1], O_RDONLY); // abertura de arquivo em modo leitura
	if (fd_in < 0)
		exit(2);
	fd_out = creat(argv[2], OUTPUT_MODE); // criação de arquivo com as permissões descritas em output_mode
	if (fd_out < 0)
		exit(3);
	while(true) {
		r_count = read(fd_in, buffer, BUF_SIZE); // leitura do arquivo de entrada
		if (r_count <= 0)
			break;
		w_count = write(fd_out, buffer, r_count); // escrita no arquivo de saída
		if (w_count <= 0)
			exit(4);
	}
	close(fd_in);
	close(fd_out);
	if (r_count == 0)
		exit(0);
	else
		exit(5);
}
