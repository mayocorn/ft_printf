/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cspdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:01:23 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/27 07:42:12 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_printc(t_info info)
{
	int		res;
	int		length;
	char	s[2];

	length = 1 + info.field_width;
	s[0] = (char)va_arg(info.args, int);
	s[1] = '\0';
	if (info.minus_flag == TRUE)
		res = ft_left_write(length, s);
	else
		res = ft_right_write(length, s);
	return (res);
}