/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 07:42:52 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/28 09:27:18 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_right_write(size_t length, char *s)
{
	size_t	s_len;
	size_t	space_len;
	char	*out;
	int		res;

	out = (char *)ft_calloc((size_t)length + 1, sizeof(char));
	if (out == NULL)
		return (-1);
	s_len = ft_strlen(s);
	space_len = length - s_len;
	ft_memset(out, ' ', space_len);
	ft_strlcat(out, s, (size_t)length + 1);
	res = write(1, out, length);
	free(out);
	return (res);
}

int	ft_left_write(size_t length, char *s)
{
	size_t	s_len;
	size_t	space_len;
	char	*out;
	int		res;

	s_len = ft_strlen(s);
	space_len = length - s_len;
	out = (char *)ft_calloc((size_t)length + 1, sizeof(char));
	if (out == NULL)
		return (-1);
	ft_strlcpy(out, s, (size_t)length + 1);
	ft_memset(out + s_len, ' ', space_len);
	res = write(1, out, length);
	free(out);
	return (res);
}

int	ft_zeropd_write(size_t length, char *s)
{
	size_t	s_len;
	size_t	zero_len;
	char	*out;
	int		res;

	s_len = ft_strlen(s);
	zero_len = length - s_len;
	out = (char *)ft_calloc((size_t)length + 1, sizeof(char));
	if (out == NULL)
		return (-1);
	if (*s == '-' || *s == '+' || *s == ' ')
	{
		*out = *s;
		ft_memset(out + 1, '0', zero_len);
		ft_strlcat(out, s + 1, length + 1);
	}
	else
	{
	ft_memset(out, '0', zero_len);
	ft_strlcat(out, s, length + 1);
	}
	res = write(1, out, length);
	free(out);
	return (res);
}

char	*ft_trim_number(t_info info, int n, size_t length)
{
	char	*res;
	size_t 	index;
	size_t 	res_size;
	size_t 	zero_len;

	res_size = length;
	if (n < 0 || info.plus_flag == TRUE || info.space_flag == TRUE)
		res_size++;
	res = (char *)malloc((res_size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	index = 0;
	if (n < 0)
		res[index++] = '-';
	else if (info.plus_flag == TRUE)
		res[index++] = '+';
	else if (info.space_flag == TRUE)
		res[index++] = ' ';
	zero_len = length - ft_count_difit(n);
	while (zero_len--)
		res[index++] = '0';
	ft_trim_number_sub(&res[index], n);
	res[res_size] = '\0';
	return (res);
}

char	*ft_trim_number_sub(char *s, int n)
{
	char	*res;

	if (n == 0)
		return (s);
	res = ft_trim_number_sub(s, n / 10);
	*res = n % 10;
	if (*res < 0)
		*res *= -1;
	*res += '0';
	return (res + 1);
}