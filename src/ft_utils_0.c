/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:19:32 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/01 11:07:53 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	size_t	res;

	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

size_t	ft_count_digit_u(unsigned int n)
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

size_t	ft_count_digit_h(unsigned long n)
{
	size_t	res;

	res = 0;
	while (n)
	{
		n /= 16;
		res++;
	}
	return (res);
}
