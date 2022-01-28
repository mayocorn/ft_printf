/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:19:32 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/28 07:32:05 by stsunoda         ###   ########.fr       */
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
	if(a < b)
		return (a);
	else
		return (b);
}

size_t	ft_count_digit(int n)
{
	size_t	res;

	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}