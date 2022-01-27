/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 07:42:52 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/28 04:57:30 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_write(t_info info, int length, char *s)
{
	if (info.minus_flag == TRUE)
		return (ft_left_write(length, s));
	else if(info.zero_flag == TRUE)
		return (ft_zeropd_write(length, s));
	else
		return (ft_right_write(length, s));
}

int	ft_right_write(int length, char *s)
{
	size_t	s_len;
	size_t	space_len;
	char	*out;
	int		res;

	out = (char *)ft_calloc(length + 1, sizeof(char));
	if (out == NULL)
		return (-1);
	s_len = ft_strlen(s);
	space_len = length - s_len;
	ft_memset(out, ' ', space_len);
	ft_strlcat(out, s, length + 1);
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
	out = (char *)ft_calloc(length + 1, sizeof(char));
	if (out == NULL)
		return (-1);
	ft_strlcpy(out, s, length + 1);
	ft_memset(out + s_len, ' ', space_len);
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
	out = (char *)ft_calloc(length + 1, sizeof(char));
	if (out == NULL)
		return (-1);
	ft_memset(out, '0', zero_len);
	ft_strlcat(out, s, length + 1);
	res = write(1, out, length);
	free(out);
	return (res);
}
