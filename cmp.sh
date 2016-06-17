#!/bin/zsh
rm *.o test_gnl
clear
make -C ./libft fclean && make -C ./libft
echo "Libft OK"
echo ""
clang -Wall -Wextra -Werror -I ./libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I ./libft/includes -o main.o -c main.c
echo "Sources files OK"
echo ""
clang -o test_gnl main.o get_next_line.o libdbg.a -I libft/includes -L libft/ -lft
echo "Executable OK"
echo ""
echo ""

echo -n "12345678" > test
#cat -e test
echo "Without EOL"
./test_gnl
echo "12345678" > test
#cat -e test
echo "With EOL"
./test_gnl
