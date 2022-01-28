/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:01:23 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 02:07:50 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

void	ft_generate_c(t_info *info)
{
	char	*s;

	info->s_len = 1;
	info->buffer_size = ft_max(1, info->field_width) + 1;
	info->space_len = info->buffer_size - info->s_len - 1;
	info->zero_flag = FALSE;
	s = (char *)calloc(2, sizeof(char));
	if (s == NULL)
	{
		info->write_count = -1;
		return ;
	}
	*s = (char)va_arg(info->args, int);
	ft_setstr(info, s);
	free(s);
}

// int	ft_print_c_zero(t_info *info, size_t length)
// {
// 	int	res;

// 	res = 0;
// 	if (info->minus_flag == TRUE)
// 	{
// 		res += write(1,"", 1);
// 		while (--length)
// 			res += write(1, " ", 1);
// 	}
// 	else
// 	{
// 		while (--length)
// 			res += write(1, " ", 1);
// 		res += write(1, "", 1);
// 	}
// 	return (res);
// }

int	ft_print_s(t_info *info)
{
	int		res;
	size_t	length;
	char	*s;
	char	*t;

	s = va_arg(info->args, char *);
	if (info->precision < 0)
		length = ft_strlen(s);
	else
		length = ft_min(ft_strlen(s), info->precision);
	length = ft_max(length, info->field_width);
	t = ft_substr(s, 0, length);
	if (t == NULL)
		return (-1);
	if (info->minus_flag == TRUE)
		res = ft_left_write(length, t);
	else
		res = ft_right_write(length, t);
	free(t);
	return (res);
}

// int	ft_print_p(t_info info)
// {

// }

int	ft_print_di(t_info *info)
{
	int		res;
	int		n;
	size_t	length;
	char	*s;

	n = va_arg(info->args, int);
	if (info->precision < 0)
		length = ft_max(ft_count_digit(n), 1);
	else
		length = ft_max(ft_count_digit(n), info->precision);
	s = ft_trim_number(info, n, length);
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

