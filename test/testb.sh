# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testb.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 04:26:46 by stsunoda          #+#    #+#              #
#    Updated: 2022/01/30 04:30:50 by stsunoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang testb.c libftprintf.a -Wall -Werror -Wextra -g -fsanitize=address -o b.out