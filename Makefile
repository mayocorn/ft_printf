# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 05:33:16 by stsunoda          #+#    #+#              #
#    Updated: 2022/01/29 07:48:11 by stsunoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCDIR	= ./src
SRC = ft_printf.c ft_eval_format.c ft_generate_0.c ft_generate_1.c ft_setstr.c \
		ft_utoa.c ft_utohex.c ft_utils.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(SRCDIR)/, $(notdir $(SRCS:.c=.o)))
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $@
	ar -rcs $@ $^

all: $(NAME)

bonus: all

clean: 
	$(MAKE) clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re