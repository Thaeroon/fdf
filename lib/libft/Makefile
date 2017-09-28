# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2017/09/28 17:48:58 by nmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############
# PARAMETERS #
##############

# directories
SRC_PATH = src
OBJ_PATH = obj
CPPFLAGS = -Iinc

# compiler flags
CC = clang
CFLAGS = -Werror -Wall -Wextra -ggdb

# files
SRC_FILES =	get_next_line.c \
			arg_handler.c \
			conv_misc.c \
			display.c \
			ft_printf.c \
			parsing.c \
			conv_number.c \
			ft_itoa_base_spec.c \
			utils.c \
			conv_str.c \
			ft_putchar.c ft_putstr.c ft_strlen.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_strnew.c ft_strdel.c ft_memdel.c ft_memalloc.c \
			ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c \
			ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_atoi.c ft_strncmp.c \
			ft_strcmp.c ft_strstr.c ft_strnstr.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_memcpy.c \
			ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_lstnew.c ft_lstdelone.c \
			ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strfjoin.c \
			ft_xtoi.c

# executable name
NAME = libft.a

##############
# PROCESSING #
##############

# variables
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

# rules
.PHONY: clean fclean re norme
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ar -s $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -v $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
