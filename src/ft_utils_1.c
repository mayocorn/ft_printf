/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:48:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/03/01 10:44:37 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_atoi2(const char *format)
{
	int	res;

	res = 0;
	while (ft_isdigit(*format))
	{
		if (INT_MAX/10 < res)
			return (ERROR);
		res *= 10;
		if (INT_MAX - res < format - '0')
			return (ERROR);
		res += *format - '0';
		format++;
	}
	return (res);
}