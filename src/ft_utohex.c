/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 07:26:43 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 07:40:38 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_getdigit_hex(unsigned int n)
{
	size_t	res;

	res = 1;
	n /= 16;
	while (n)
	{
		n /= 16;
		res++;
	}
	return (res);
}

static void	ft_setnum_hex(char *dst_head, size_t index, unsigned int n)
{
	const char	order[] = "0123456789abcdef";
	char		*dst;

	if (index != 0)
		ft_setnum(dst_head, index - 1, n / 16);
	dst = dst_head + index;
	*dst = order[n % 16];
}

char	*ft_utohex(unsigned int n)
{
	char	*res;
	size_t	res_size;

	res_size = ft_getdigit_hex(n);
	res = (char *)malloc((res_size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_setnum(res, res_size - 1, n);
	*(res + res_size) = 0;
	return (res);
}