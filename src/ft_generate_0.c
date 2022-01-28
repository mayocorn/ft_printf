/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:01:23 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 04:10:08 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

void	ft_generate_c(t_info *info)
{
	char	*s;

	info->s_len = 1;
	info->buffer_size = (size_t)ft_max(1, info->field_width) + 1;
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

void	ft_generate_s(t_info *info)
{
	char	*s;
	char	*t;

	s = va_arg(info->args, char *);
	if (info->precision < 0)
		info->s_len = ft_strlen(s);
	else
		info->s_len = ft_min(ft_strlen(s), info->precision);
	info->field_width = ft_max(info->s_len, info->field_width);
	info->buffer_size = (size_t)info->field_width + 1;
	info->space_len = info->buffer_size - info->s_len - 1;
	info->zero_flag = FALSE;
	t = ft_substr(s, 0, info->s_len);
	if (t == NULL)
	{
		info->write_count = -1;
		return ;
	}
	ft_setstr(info, t);
	free(t);
}

// void	ft_generate_p(t_info *info)
// {

// }

// void	ft_generate_di(t_info *info)
// {
// 	int		n;
// 	char	*s;

// 	n = va_arg(info->args, int);
// 	if (n < 0)
// 		ft_strlcpy(info->prefix, "-", 3);
// 	else if (info->plus_flag == TRUE)
// 		ft_strlcpy(info->prefix, "+", 3);
// 	else if (info->space_flag == TRUE)
// 		ft_strlcpy(info->prefix, " ", 3);
// 	if (info->precision < 0)
// 		info->s_len = ft_max(ft_count_digit(n), 1);
// 	else
// 	{
// 		info->zero_flag = FALSE;
// 		info->s_len = ft_count_digit(n);
// 		info->zero_len = ft_max(info->precision, info->s_len) - info->s_len;
// 	}
// 	info->buffer_size = 
// 	s = ft_trim_number(info, n, length);
// 	if (s == NULL)
// 		return (-1);
// 	length = ft_max(ft_strlen(s), info->field_width);
// 	ft_setstr(info, s);
// 	free(s);
// }

