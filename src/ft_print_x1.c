/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:01:23 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/28 06:31:56 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

int	ft_print_c(t_info info)
{
	int		length;
	char	s[2];

	length = ft_max(1, info.field_width);
	s[0] = (char)va_arg(info.args, int);
	s[1] = '\0';
	if (info.minus_flag == TRUE)
		return (ft_left_write(length, s));
	else
		return (ft_right_write(length, s));
}

int	ft_print_s(t_info info)
{
	int		res;
	int		length;
	char	*s;

	s = va_arg(info.args, char *);
	if (info.precision < 0)
		length = ft_strlen(s);
	else
		length = ft_min((int)ft_strlen(s), info.precision);
	length = ft_max(length, info.field_width);
	if (info.minus_flag == TRUE)
		return (ft_left_write(length, s));
	else
		return (ft_right_write(length, s));
	return (res);
}

// int	ft_print_p(t_info info)
// {

// }

// int	ft_print_di(t_info info)
// {
// 	int		res;
// 	int		length;
// 	int		n;
// 	char	*s;
// 	char	*t;

// 	n = va_arg(info.args, int);
// 	s = ft_itoa(n);
// 	if (s == NULL)
// 		return (-1);
// 	t = ft_apply_psflag
// 	free(s);
// 	if (t == NULL)
// 		return (-1);
// 	length = ft_max(ft_max((int)ft_strlen(s), info.precision), info.field_width);
// 	ft_write(info, );
// 	free(s);
// 	return (res);
// }

// int	ft_print_u(t_info info)
// {

// }
