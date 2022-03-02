/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:19:32 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:09:55 by mayocorn         ###   ########.fr       */
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
	int	res;

	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

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

int	ft_count_digit_h(unsigned long n)
{
	int	res;

	res = 0;
	while (n)
	{
		n /= 16;
		res++;
	}
	return (res);
}
