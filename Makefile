NAME=gnl

all: $(NAME)

$(NAME): obj
	@clear
	@clang -I./include main.c ./src/get_next_line.c ./libdbg/libdbg.a ./libft/libft.a -o $(NAME)

obj:
	@clang -c main.c -I./include ./libft/libft.a ./libdbg/libdbg.a
	@clang -c -Wall -Wextra src/get_next_line.c -I./include ./libdbg/libdbg.a

clean:
	-@rm main.o get_next_line.o

fclean: clean
	-@rm $(NAME)

re: fclean all

test: re
	@clear
	-@./$(NAME)
	-@./$(NAME) no_line_feed

42fc:
	@cp ./include/get_next_line.h ../gnl_test
	@cp ./src/get_next_line.c ../gnl_test
