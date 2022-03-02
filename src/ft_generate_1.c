/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 05:29:42 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:19:52 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_generate_u(t_info *info)
{
	unsigned int	n;
	char			*s;

	n = va_arg(info->args, int);
	s = ft_utoa(n);
	if (s == NULL)
	{
		info->write_count = ERROR;
		return ;
	}
	if (info->precision < 0)
		info->s_len = ft_max(ft_count_digit_u(n), 1);
	else
	{
		info->s_len = ft_count_digit_u(n);
		info->zero_flag = false;
		info->zero_len = ft_max(info->precision, info->s_len) - info->s_len;
	}
	ft_setinfo(info);
	ft_setstr(info, s);
	free(s);
}

static void	ft_generate_x_sub(t_info *info, char c, unsigned int n)
{
	char	*s;
	size_t	index;

	s = ft_utohex(n);
	if (s == NULL)
	{
		info->write_count = ERROR;
		return ;
	}
	if (c == 'X')
	{
		index = -1;
		while (s[++index])
			s[index] = ft_toupper(s[index]);
	}
	ft_setstr(info, s);
	free(s);
}

void	ft_generate_x(t_info *info, char c)
{
	unsigned int	n;

	n = va_arg(info->args, int);
	if (info->sharp_flag == true && n != 0)
	{
		if (c == 'x')
			ft_strlcpy(info->prefix, "0x", 3);
		else
			ft_strlcpy(info->prefix, "0X", 3);
	}
	if (info->precision < 0)
		info->s_len = ft_max(ft_count_digit_h(n), 1);
	else
	{
		info->s_len = ft_count_digit_h(n);
		info->zero_flag = false;
		info->zero_len = ft_max(info->precision, info->s_len) - info->s_len;
	}
	ft_setinfo(info);
	ft_generate_x_sub(info, c, n);
}

void	ft_generate_ps(t_info *info);