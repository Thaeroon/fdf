# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2017/08/22 07:28:34 by nmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##############
# PARAMETERS #
##############

# directories
LIB_PATH = lib
SRC_PATH = src
OBJ_PATH = obj


# compiler flags
CC = clang
CFLAGS = -Werror -Wall -Wextra -ggdb -Iinc
LFLAGS = -I $(LIB_PATH)/libft

# linker flags
LKFLAGS =  -lmlx -lXext -lX11

# libs
LIB = $(LIB_PATH)/libftall/libftall.a

# files
SRC_FILES =	main.c input.c

# executable name
NAME = fdf

##############
# PROCESSING #
##############

# variables
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

# rules
.PHONY: clean fclean re norme lib fcleanall
all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) -o $(NAME) $(LKFLAGS) $(LFLAGS)

lib:
	@make -C $(LIB_PATH)/libftall

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -v $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

fcleanall: fclean
	@make fclean -C $(LIB_PATH)/libftall

re: fclean all fcleanall

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h