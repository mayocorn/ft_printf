/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:19:32 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:31:48 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_count_digit(int n)
{
	int	res;

	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

int	ft_atoi2(const char *format)
{
	int	res;

	res = 0;
	while (ft_isdigit(*format))
	{
		if (INT_MAX/10 < res)
			return (ERROR);
		res *= 10;
		if (INT_MAX - res < *format - '0')
			return (ERROR);
		res += *format - '0';
		format++;
	}
	return (res);
}
