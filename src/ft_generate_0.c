/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:01:23 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:12:23 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_generate_c(t_info *info)
{
	char	c;

	c = (char)va_arg(info->args, int);
	info->s_len = 1;
	info->zero_flag = false;
	ft_setinfo(info);
	ft_setstr(info, &c);
}

void	ft_generate_s(t_info *info)
{
	char	*s;

	s = va_arg(info->args, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if (s == NULL)
	{
		info->write_count = ERROR;
		return ;
	}
	info->s_len = ft_strlen(s);
	if (info->precision >= 0)
	{
		if (INT_MAX < info->s_len)
			info->s_len = INT_MAX;
		info->s_len = ft_min(info->s_len, info->precision);
	}
	info->zero_flag = false;
	ft_setinfo(info);
	ft_setstr(info, s);
	free(s);
}

void	ft_generate_p(t_info *info)
{
	unsigned long	n;
	char			*s;

	n = va_arg(info->args, unsigned long);
	s = ft_utohex(n);
	if (s == NULL)
	{
		info->write_count = ERROR;
		return ;
	}
	info->s_len = ft_max(ft_count_digit_h(n), 1);
	ft_strlcpy(info->prefix, "0x", 3);
	ft_setinfo(info);
	ft_setstr(info, s);
	free(s);
}

static void	ft_generate_di_sub(t_info *info, int n)
{
	char	*s;

	s = ft_itoa(n);
	if (s == NULL)
	{
		info->write_count = ERROR;
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

	n = va_arg(info->args, int);
	if (n < 0)
		ft_strlcpy(info->prefix, "-", 3);
	else if (info->plus_flag == true)
		ft_strlcpy(info->prefix, "+", 3);
	else if (info->space_flag == true)
		ft_strlcpy(info->prefix, " ", 3);
	if (info->precision < 0)
		info->s_len = ft_max(ft_count_digit(n), 1);
	else
	{
		info->s_len = ft_count_digit(n);
		info->zero_flag = false;
		info->zero_len = ft_max(info->precision, info->s_len) - info->s_len;
	}
	ft_setinfo(info);
	ft_generate_di_sub(info, n);
}
