/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 07:42:52 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/27 08:06:43 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_right_write(int length, char *s)
{
	size_t	s_len;
	size_t	space_len;
	char	*out;
	int		res;

	s_len = ft_strlen(s);
	space_len = length - s_len;
	out = (char *)malloc((length + 1)*sizeof(char));
	if (out == NULL)
		return (-1);
	out[length] = '\0';
	while (s_len--)
		out[space_len + s_len] = s[s_len];
	while (space_len--)
		out[space_len] = ' ';
	res = write(1, out, length);
	free(out);
	return (res);
}

int	ft_left_write(int length, char *s)
{
	size_t	s_len;
	size_t	space_len;
	char	*out;
	int		res;

	s_len = ft_strlen(s);
	space_len = length - s_len;
	out = (char *)malloc((length + 1)*sizeof(char));
	if (out == NULL)
		return (-1);
	out[length] = '\0';
	while (space_len--)
		out[s_len + space_len] = ' ';
	while (s_len--)
		out[s_len] = s[s_len];
	res = write(1, out, length);
	free(out);
	return (res);
}

int	ft_zeropd_write(int length, char *s)
{
	size_t	s_len;
	size_t	zero_len;
	char	*out;
	int		res;

	s_len = ft_strlen(s);
	zero_len = length - s_len;
	out = (char *)malloc((length + 1)*sizeof(char));
	if (out == NULL)
		return (-1);
	out[length] = '\0';
	while (s_len--)
		out[zero_len + s_len] = s[s_len];
	while (zero_len--)
		out[zero_len] = '0';
	res = write(1, out, length);
	free(out);
	return (res);
}
