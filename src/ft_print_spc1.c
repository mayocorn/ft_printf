/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:01:23 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/27 08:44:55 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_print_c(t_info info)
{
	int		length;
	char	s[2];

	length = ft_max(1, info.field_width);
	s[0] = (char)va_arg(info.args, int);
	s[1] = '\0';
	return (ft_write(info, length, s));
}

int	ft_print_s(t_info info)
{
	int		res;
	int		length;
	char	*s;

	s = va_arg(info.args, char *);
	length = ft_max(ft_min((int)ft_strlen(s), info.precision), info.field_width);
	if (info.minus_flag == TRUE)
		res = ft_left_write(length, s);
	else if(info.zero_flag == TRUE)
		res = ft_zeropd_write(length, s);
	else
		res = ft_right_write(length, s);
	return (res);
}