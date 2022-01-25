# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 05:33:16 by stsunoda          #+#    #+#              #
#    Updated: 2022/01/26 06:31:48 by stsunoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_libft.c
OBJS = $(SRCS:%.c=%.o)
LIBFT = libft

%.o: %.c
	$(CC) $(CFLAG) -c $<

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