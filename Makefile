# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 17:36:07 by dbessmer          #+#    #+#              #
#    Updated: 2017/10/18 14:23:17 by dbessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CHECKER =   checker

LIBFT = ./libft/libft.a

FTPRINTF = ./libft/ft_printf/libftprintf.a

SRC1 =  push_swap.c \
        get_data.c \
        sort_a.c \
        sort_b.c \
        sort_three.c \
        sort_helpers.c \
        execute.c \
        execute_commands.c \
        execute_helpers.c \
        output.c

SRC2 =  checker.c \
        get_data.c \
        checker_instructions.c \
        execute.c \
        execute_helpers.c \
        execute_commands.c \
        output.c

FLAGS = -Wall -Wextra -Werror

OBJ1     = $(SRC1:.c=.o)

OBJ2     = $(SRC2:.c=.o)

all     : $(NAME) $(CHECKER)

$(NAME) : $(OBJ1) $(LIBFT) $(FTPRINTF)
	    gcc $(FLAGS) $(OBJ1) -o $(NAME) $(LIBFT) $(FTPRINTF)

$(CHECKER) : $(OBJ2) $(LIBFT) $(FTPRINTF)
	    gcc $(FLAGS) $(OBJ2) -o $(CHECKER) $(LIBFT) $(FTPRINTF)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $<

$(LIBFT)  :
	    make -C libft/

$(FTPRINTF)  :
	    make -C libft/ft_printf/

lclean  :
	    make -C libft/ clean
	    make -C libft/ft_printf/ clean

clean   : lclean
	    rm -f $(OBJ1)
	    rm -f $(OBJ2)

fclean  : clean
	    rm -f $(NAME) $(CHECKER)
		rm -f libft/libft.a
		rm -f libft/ft_printf/libftprintf.a

re: fclean all
