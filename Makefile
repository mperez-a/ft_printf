# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manperez <manperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 14:31:54 by manperez          #+#    #+#              #
#    Updated: 2024/01/17 14:32:53 by manperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#**********************************VARIABLES***********************************#
CC = gcc
CFLAGS = -Wextra -Wall -Werror -c -MMD
NAME = libftprintf.a
HEADER = ft_printf.h
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_puthex.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

#**********************************COLORS**************************************#
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

#**********************************RULES***************************************#

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -I./ $< -o $@
	@echo "$(YELLOW)Compiling..."

all: $(NAME)

$(NAME): $(OBJ)
	@ar crs $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!"

-include $(DEP)

clean:
	@rm -f $(OBJ) $(DEP)
	@echo "$(RED)objects and dependences deleted"

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@echo "$(RED)libftprintf deleted"

re: fclean all


.PHONY: all clean fclean re
