# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 05:33:16 by stsunoda          #+#    #+#              #
#    Updated: 2022/03/02 17:28:20 by mayocorn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCDIR = ./src/
OBJDIR = ./obj/
SRCS = ft_printf.c ft_eval_format.c ft_generate_0.c \
		ft_generate_1.c ft_setstr.c ft_utoa.c ft_utohex.c ft_utils.c
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:%.c=%.o)))
DEPS = $(OBJS:%.o=%.d)
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $@
	ar -rcs $@ $(OBJS) 

$(OBJDIR):
	mkdir obj

-include $(DEPS)

all: $(NAME)

bonus: all

clean: 
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
