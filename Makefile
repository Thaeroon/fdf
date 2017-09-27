# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2017/09/27 22:26:24 by nmuller          ###   ########.fr        #
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
LFLAGS = -I $(LIB_PATH)/libftall/inc -I $(LIB_PATH)/minilibx_x11/includes

# linker flags
LKFLAGS =  -Llib/minilibx_x11 -lmlx -lXext -lX11 -Llib/libftall -lftall -lm

# libs
LIB = $(LIB_PATH)/libftall/libftall.a $(LIB_PATH)/minilibx_x11/libmlx.a

# files
SRC_FILES =	main.c input.c display.c utils.c

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
	$(CC) $(OBJ) -o $(NAME) $(LKFLAGS)

lib:
	@make -C $(LIB_PATH)/libftall
	@make -C $(LIB_PATH)/minilibx_x11

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -v $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

fcleanall: fclean
	@make fclean -C $(LIB_PATH)/libftall

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
