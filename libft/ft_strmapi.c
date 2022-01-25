/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:09:43 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/14 06:15:59 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	index;

	if (!s || !f)
		return (0);
	res = ft_strdup(s);
	if (!res)
		return (0);
	index = -1;
	while (s[++index])
		res[index] = f(index, s[index]);
	return (res);
}
