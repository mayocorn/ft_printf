/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:01:23 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 05:15:16 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

void	ft_generate_c(t_info *info)
{
	char	s;

	info->s_len = 1;
	info->buffer_size = ft_max(1, info->field_width);
	info->space_len = info->buffer_size - info->s_len;
	info->zero_flag = FALSE;
	s = (char)va_arg(info->args, int);
	ft_setstr(info, &s);
}

void	ft_generate_s(t_info *info)
{
	char	*s;

	s = va_arg(info->args, char *);
	if (info->precision < 0)
		info->s_len = ft_strlen(s);
	else
		info->s_len = ft_min(ft_strlen(s), info->precision);
	info->buffer_size = ft_max(info->s_len, info->field_width);
	info->space_len = info->buffer_size - info->s_len;
	info->zero_flag = FALSE;
	ft_setstr(info, s);
}

// void	ft_generate_p(t_info *info)
// {

// }
static void	ft_generate_di_sub(t_info *info,int n)
{
	char	*s;

	s = ft_itoa(n);
	if (s == NULL)
	{
		info->write_count = -1;
		return ;
	}
	if (*s == '-')
		ft_setstr(info, s + 1);
	else
		ft_setstr(info, s);
	free(s);
	
}

void	ft_generate_di(t_info *info)
{
	int		n;
	size_t	num_len;

	n = va_arg(info->args, int);
	if (n < 0)
		ft_strlcpy(info->prefix, "-", 3);
	else if (info->plus_flag == TRUE)
		ft_strlcpy(info->prefix, "+", 3);
	else if (info->space_flag == TRUE)
		ft_strlcpy(info->prefix, " ", 3);
	if (info->precision < 0)
		info->s_len = ft_max(ft_count_digit(n), 1);
	else
	{
		info->s_len = ft_count_digit(n);
		info->zero_flag = FALSE;
		info->zero_len = ft_max(info->precision, info->s_len) - info->s_len;
	}
	num_len = info->s_len + info->zero_len + ft_strlen(info->prefix);
	info->buffer_size = ft_max(info->field_width, num_len);
	info->space_len = info->buffer_size - num_len;
	ft_generate_di_sub(info, n);
}

