#! Variables

LIB_NAME	= libasm.a
EXEC_NAME	= libasm_checker
INCLUDES	= ./
OBJ_DIR		= obj/
SRC_DIR		= src/

AR		= ar rcs
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror -I

#! Sources

SRC_FILES	=	ft_strlen ft_strcpy ft_strcmp ft_write ft_read ft_strdup

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

MAIN = main.c

#! Make

$(EXEC_NAME):
	@echo "Compiling $(EXEC_NAME)"
# TODO 	Compile main.c with libasm.a

$(LIB_NAME): $(OBJS)
	@echo "Compiling $(LIB_NAME) ..."
	@$(AR) $(LIB_NAME) $(OBJS)
	@echo "$(LIB_NAME) compiled!"

#? %  : Pattern ou Joker -
#?		Permet d'appliquer une regle a tous les fichiers designes
#? $@ : produit (ou but) de la règle
#? $< : nom de la première dépendance (ou source)
#? $? : toutes les dépendances plus récentes que le but
#? $^ : toutes les dépendances
#? $+ : idem mais chaque dépendance apparait autant de fois
#?		qu'elle est cité et l'ordre d'apparition est conservé.

#? On a besoin de la regle obj_mkdir pour n'executer qu'une seule
#? fois les mkdir, au lieu d'une fois par fichier.

#? OBJS = $(SRC_FILES:.c=.o)
$(OBJ_DIR)%.o : $(SRC_DIR)%.c | obj_mkdir
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# TODO 	Change for nasm compilation

all: $(EXEC_NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Libft objects files cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "Libft.a cleaned!"

libasm: $(LIB_NAME)
# TODO Libasm compilation with nasm

obj_mkdir:
	@mkdir -p $(OBJ_DIR)

re: fclean all
	@echo "Cleaned and rebuild Libft from zero!"

.PHONY: all clean fclean libasm obj_mkdir re
