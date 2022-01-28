/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:01:35 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/28 12:07:48 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xX(t_info *info)
{
	int				res;
	unsigned int	n;
	size_t			length;
	char			*s;
	
	n = va_arg(info->args, unsigned int);
	if (info->precision < 0)
		length = ft_max(ft_count_digit_xX(n), 1);
	else
		length = ft_max(ft_count_digit_xX(n), info->precision);
	s = ft_trim_u(n, length);
	if (s == NULL)
		return (-1);
	length = ft_max(ft_strlen(s), info->field_width);
	if (info->minus_flag == TRUE)
		res = ft_left_write(length, s);
	else if (info->zero_flag == TRUE && info->precision < 0)
		res = ft_zeropd_write(length, s);
	else
		res = ft_right_write(length, s);
	free(s);
	return (res);
}