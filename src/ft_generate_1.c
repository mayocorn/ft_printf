/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 05:29:42 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 07:26:21 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"


void	ft_generate_u(t_info *info)
{
	unsigned int	n;
	char			*s;

	n = va_arg(info->args, int);
	if (info->precision < 0)
		info->s_len = ft_max(ft_count_digit_u(n), 1);
	else
	{
		info->s_len = ft_count_digit_u(n);
		info->zero_flag = FALSE;
		info->zero_len = ft_max(info->precision, info->s_len) - info->s_len;
	}
	info->buffer_size = ft_max(info->field_width, info->s_len + info->zero_len);
	info->space_len = info->buffer_size - info->s_len - info->zero_len;
	s = ft_utoa(n);
	if (s == NULL)
	{
		info->write_count = -1;
		return ;
	}
	ft_setstr(info, s);
	free(s);
}

static void	ft_generate_xX_sub(t_info *info, unsigned int n)
{
	char	*s;
	size_t	index;

	s = ft_utohex(n);
	if (s == NULL)
	{
		info->write_count  = -1;
		return ;
	}
	if (info->specifier == 'X')
	{
		index = -1;
		while (s[++index])
			s[index] = ft_toupper(s[index]);
	}
	ft_setstr(info, s);
	free(s);
}

void	ft_generate_xX(t_info *info)
{
	unsigned int	n;
	size_t num_len;

	n = va_arg(info->args, int);
	if (info->sharp_flag == TRUE && n != 0)
	{
		if (info->specifier == 'x')
			ft_strlcpy(info->prefix, "0x", 3);
		else
			ft_strlcpy(info->prefix, "0X", 3);
	}
	if (info->precision < 0)
		info->s_len = ft_max(ft_count_digit_h(n), 1);
	else
	{
		info->s_len = ft_count_digit_u(n);
		info->zero_flag = FALSE;
		info->zero_len = ft_max(info->precision, info->s_len) - info->s_len;
	}
	num_len = info->s_len + info->zero_len + ft_strlen(info->prefix);
	info->buffer_size = ft_max(info->field_width, num_len);
	info->space_len = info->buffer_size - num_len;
	ft_generate_xX_sub(info, n);
}