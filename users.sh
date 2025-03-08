#!/bin/bash
# script que lista os usuários e separa por campo

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7; do
	echo "Usuário $f1 usa do shell $f7 e armazena arquivos em $f6"
done < /etc/passwd
