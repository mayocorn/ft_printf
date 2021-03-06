/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 05:49:21 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:26:51 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_count_digit_u(unsigned int n)
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

static size_t	ft_getdigit(unsigned int n)
{
	size_t	res;

	res = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static void	ft_setnum(char *dst_head, size_t index, unsigned int n)
{
	char	*dst;

	if (index != 0)
		ft_setnum(dst_head, index - 1, n / 10);
	dst = dst_head + index;
	*dst = (n % 10) + '0';
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	size_t	res_size;

	res_size = ft_getdigit(n);
	res = (char *)malloc((res_size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_setnum(res, res_size - 1, n);
	*(res + res_size) = 0;
	return (res);
}
