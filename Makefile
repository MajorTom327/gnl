#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  vthomas <vthomas@student.42.fr>           +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/29 21:15:40 by vthomas           #+#    #+#             *#
#*   Updated: 2015/12/29 23:50:29 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME=gnl
#Debugging commande (yes/no)
DEBUG=yes
CC=gcc
ifeq ($(DEBUG),yes)
	export CFLAGS=-Wall -Wextra -g
else
	export CFLAGS=-Wall -Wextra -Werror
endif

#* ******************************************* *#
#*                  MAIN VAR                   *#
#* These var, are listing all the files needed *#
#* and the directory where they are            *#
#* ******************************************* *#
SRC_PATH=./src/
INC_PATH=./include/
OBJ_PATH=./obj/
LIB_PATH=./

SRC_NAME=main.c\
		 get_next_line.c

INC_NAME=$(wildcard *.h)
OBJ_NAME=$(SRC_NAME:.c=.o)
LIB_NAME=libft


SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
INC=$(addprefix -I, $(INC_PATH))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB=$(addprefix $(LIB_PATH),$(LIB_NAME))

# Specific to the lib utilisation (More usefull)
LIB_FILE=$(addprefix $(LIB),/$(addprefix $(LIB_NAME),.a))


#* *********************************************** *#
#*                    MAIN RULES                   *#
#* There, it's the rules who compilate the program *#
#* *********************************************** *#
all: $(NAME)
$(NAME):$(OBJ) $(LIB)
ifeq ($(DEBUG),yes)
	@echo "\033[32m[MAIN]\033[0m\t\t\033[5;31m(debug)\033[0m"
else
	@echo "\033[32m[MAIN]\t\t(release)\033[0m"
endif
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB_FILE)

# Compilation of all .c with modulable rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

# Compilation of the librairie(s)
$(LIB):
	@echo "\033[34m[LIBRAIRIES]\033[0m"
	@(cd $@ && $(MAKE) re)

# Force dependance to be rebuild at all call of the rule(s)
.PHONY: clean fclean re $(LIB)
re: fclean all

clean:
	@rm -rf $(OBJ_PATH)
	@(cd $(LIB) && $(MAKE) $@)

fclean: clean
	@rm -rf $(NAME)
	@(cd $(LIB) && $(MAKE) $@)
	@echo "\nWow ! Student clean it so much !\n"

norme:
	@norminette $(SRC)
	@norminette $(addprefix $(INC_NAME),$(INC_PATH))

test: re
	@clear
	@./$(NAME) | cat -e
	@(cd ./ && $(MAKE) fclean)
