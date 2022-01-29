/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:08:41 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/30 00:18:36 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_setstr_minusflag(t_info *info, char *s)
{
	char	*str;
	char	*prefix;

	str = info->str;
	prefix = info->prefix;
	while (*prefix != '\0')
		*(str++) = *(prefix++);
	ft_memset(str, '0', info->zero_len);
	str += info->zero_len;
	ft_memcpy(str, s, info->s_len);
	str += info->s_len;
	ft_memset(str, ' ', info->space_len);
}

static void	ft_setstr_zeroflag(t_info *info, char *s)
{
	char	*str;
	char	*prefix;

	str = info->str;
	prefix = info->prefix;
	while (*prefix != '\0')
		*(str++) = *(prefix++);
	ft_memset(str, '0', info->space_len);
	ft_memcpy(str + info->space_len, s, info->s_len);
}

static void	ft_setstr_nonflag(t_info *info, char *s)
{
	char	*str;
	char	*prefix;

	str = info->str;
	prefix = info->prefix;
	ft_memset(str, ' ', info->space_len);
	str += info->space_len;
	while (*prefix != '\0')
		*(str++) = *(prefix++);
	ft_memset(str, '0', info->zero_len);
	str += info->zero_len;
	ft_memcpy(str, s, info->s_len);
}

void	ft_setstr(t_info *info, char *s)
{
	info->str = (char *)malloc(info->buffer_size);
	if (info->str == NULL)
	{
		info->write_count = -1;
		return ;
	}
	if (info->minus_flag == TRUE)
		ft_setstr_minusflag(info, s);
	else if (info->zero_flag == TRUE)
		ft_setstr_zeroflag(info, s);
	else
		ft_setstr_nonflag(info, s);
}

void	ft_setinfo(t_info *info)
{
	info->buffer_size = ft_max(info->field_width, \
							ft_strlen(info->prefix) + info->zero_len + info->s_len);
	info->space_len = info->buffer_size - \
						(ft_strlen(info->prefix) + info->zero_len + info->s_len);
}