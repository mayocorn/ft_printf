/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:08:41 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 03:04:18 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_setstr_minusflag(t_info *info, char *s)
{
	while (*(info->prefix) != '\0')
		*(info->str++) = *(info->prefix++);
	ft_memcpy(info->str, s, info->s_len);
	ft_memset(info->str + info->s_len, ' ', info->space_len);
}

static void	ft_setstr_zeroflag(t_info *info, char *s)
{
	while (*(info->prefix) != '\0')
		*(info->str++) = *(info->prefix++);
	ft_memset(info->str, '0', info->space_len);
	fr_memcpy(info->str + info->space_len, s, info->s_len);
}

static void	ft_setstr_nonflag(t_info *info, char *s)
{
	ft_memset(info->str, ' ', info->space_len);
	info->str += info->space_len;
	while (*(info->prefix) != '\0')
		*(info->str++) = *(info->prefix++);
	ft_memcpy(info->str, s, info->s_len);
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
	info->str[info->buffer_size - 1] = '\0';
}