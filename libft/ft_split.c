/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:37:37 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/17 04:20:11 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_null(char *s, char c)
{
	char	*s_head;
	size_t	res;

	res = 0;
	s_head = s;
	while (*s)
	{
		if (*s == c)
			*s = 0;
		if (*s && (s == s_head || !*(s - 1)))
			res++;
		s++;
	}
	return (res);
}

static int	ft_split_set(char **ptr, size_t ptr_size, char const *s)
{
	char const	*s_head;
	char		**ptr_head;
	char		*inner;

	s_head = s;
	ptr_head = ptr;
	while (--ptr_size)
	{
		while (!*s || (s != s_head && *(s - 1)))
			s++;
		inner = ft_strdup(s++);
		if (!inner)
		{
			while (ptr_head < ptr--)
				free(*ptr);
			free(ptr_head);
			return (0);
		}
		*(ptr++) = inner;
	}
	*ptr = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*s_dup;
	size_t	res_size;

	if (!s)
		return (0);
	s_dup = ft_strdup(s);
	if (!s_dup)
		return (0);
	res_size = ft_split_null(s_dup, c);
	res = (char **)malloc((res_size + 1) * sizeof(char *));
	if (res && !ft_split_set(res, res_size + 1, s_dup))
		res = 0;
	free(s_dup);
	return (res);
}
