/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:08:41 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:19:22 by mayocorn         ###   ########.fr       */
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
	if (info->write_count == ERROR)
		return ;
	info->str = (char *)malloc(info->buffer_size);
	if (info->str == NULL)
	{
		info->write_count = ERROR;
		return ;
	}
	if (info->minus_flag == true)
		ft_setstr_minusflag(info, s);
	else if (info->zero_flag == true)
		ft_setstr_zeroflag(info, s);
	else
		ft_setstr_nonflag(info, s);
}

void	ft_setinfo(t_info *info)
{
	size_t	entity_len;

	entity_len = ft_strlen(info->prefix) + info->zero_len + info->s_len;
	if (INT_MAX < entity_len)
	{
		info->write_count = ERROR;
		return ;
	}
	info->buffer_size = ft_max(info->field_width, entity_len);
	info->space_len = info->buffer_size - entity_len;
}
