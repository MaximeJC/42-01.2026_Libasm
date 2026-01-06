#! Variables

LIB_NAME	= libasm.a
EXEC_NAME	= libasm_checker
INCLUDES	= ./
OBJ_DIR		= obj/
SRC_DIR		= src/

AR			= ar rcs
CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror -I
NASM		= nasm
NASM_FLAGS	= -f elf64

#! Sources

SRC_FILES	=	ft_strlen ft_strcpy ft_strcmp #ft_write ft_read ft_strdup

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .s, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

MAIN = main.c

#! Make

$(EXEC_NAME): libasm
	@echo "Compiling $(EXEC_NAME)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(EXEC_NAME) $(MAIN) $(LIB_NAME)
	@echo "$(EXEC_NAME) compiled!"

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
$(OBJ_DIR)%.o : $(SRC_DIR)%.s | obj_mkdir
	@$(NASM) $(NASM_FLAGS) $< -o $@

all: $(EXEC_NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(LIB_NAME) objects files cleaned!"

fclean: clean
	@rm -f $(LIB_NAME) $(EXEC_NAME)
	@echo "$(LIB_NAME) & $(EXEC_NAME) cleaned!"

libasm: $(LIB_NAME)

obj_mkdir:
	@mkdir -p $(OBJ_DIR)

re: fclean all
	@echo "Cleaned and rebuild $(EXEC_NAME) from zero!"

.PHONY: all clean fclean libasm obj_mkdir re
