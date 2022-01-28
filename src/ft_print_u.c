/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:45:52 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/28 12:00:21 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*ft_trim_u_sub(char *s, unsigned int n)
{
	char	*res;

	if (n == 0)
		return (s);
	res = ft_trim_u_sub(s, n / 10);
	*res = n % 10 + '0';
	return (res + 1);
}

static char	*ft_trim_u(unsigned int n, size_t length)
{
	char	*res;
	size_t	zero_len;
	size_t	index;
	
	res = (char *)malloc((length + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	zero_len = length - ft_count_digit_u(n);
	index = 0;
	while (zero_len--)
		res[index++] = '0';
	ft_trim_u_sub(&res[index], n);
	res[length] = '\0';
	return (res);
}

int	ft_print_u(t_info *info)
{
	int				res;
	unsigned int	n;
	size_t			length;
	char			*s;

	n = va_arg(info->args, unsigned int);
	if (info->precision < 0)
		length = ft_max(ft_count_digit_u(n), 1);
	else
		length = ft_max(ft_count_digit_u(n), info->precision);
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
