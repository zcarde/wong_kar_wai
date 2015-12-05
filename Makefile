# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 21:56:59 by zcarde            #+#    #+#              #
#    Updated: 2015/03/01 08:09:05 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SRC = borders.c\
checks.c\
deuxquatrehuit.c\
down.c\
ia.c\
init_colors.c\
left.c\
loose.c\
make_map.c\
print_cols.c\
print_lines.c\
print_map.c\
restart.c\
right.c\
signals.c\
up.c\
win.c

OBJ = $(SRC:.c=.o)

LIBFT = libft -lft -lncurses

FLAG = -Wall -Werror -Wextra

INCLUDES = -I libft/includes

all: libft.a $(NAME)

libft.a:
	@$(MAKE) -C ./libft

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(INCLUDES) -c $^

clean :
	@make clean -C ./libft
	rm -f $(OBJ)

fclean : clean
	rm -f libft.a
	rm -f $(NAME)

re : fclean all