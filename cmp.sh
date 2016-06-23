#!/bin/zsh
rm *.o test_gnl
cp ../main.c ./
cp ../debug.h ./
clear
make -C ./libft fclean && make -C ./libft
echo "Libft \t\t\033[32m[OK]\033[0m"
echo ""
clang -Wall -Wextra -Werror -I ./libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I ./libft/includes -o main.o -c main.c
echo "Sources files \t\033[32m[OK]\033[0m"
echo ""
clang -o test_gnl main.o get_next_line.o libdbg.a -I libft/includes -L libft/ -lft
echo "Executable \t\033[32m[OK]\033[0m"
echo ""
echo ""

echo -n "12345678" > test
echo "\033[32mWithout EOL\033[0m"
./test_gnl | cat -e

echo "12345678" > test
echo "\033[32mWith EOL\033[0m"
./test_gnl | cat -e

echo ""

echo "123456789" > test
echo "\033[32m123456789\033[0m"
./test_gnl | cat -e

echo ""

echo "1234567812345678" > test
echo "\033[32m1234567812345678\033[0m"
./test_gnl | cat -e

echo ""

echo "123456789" > test
echo "ABCDEFGHI" >> test
echo "\033[32m123456789#ABCDEFGH\033[0m"
./test_gnl | cat -e

echo ""

echo "\033[32m1234\033[0m"
echo "1234" > test
./test_gnl | cat -e

echo ""

echo "1234" > test
echo "abcd" >> test
echo "5678" >> test
echo "efgh" >> test
echo "\033[32mSquare\033[0m"
./test_gnl | cat -e

echo ""

echo "abcdefghijklmnop" > test
echo "\033[32mabcdefghijklmnop\033[0m"
./test_gnl | cat -e

rm main.c
rm *.o test_gnl test debug.h
