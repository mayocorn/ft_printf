/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:50:22 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 02:07:12 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_info(t_info *info)
{
	info->minus_flag = FALSE;
	info->zero_flag = FALSE;
	info->sharp_flag = FALSE;
	info->space_flag = FALSE;
	info->plus_flag = FALSE;
	info->field_width = 0;
	info->precision = -1;
	info->specifier = 0;
	info->str = 0;
	info->buffer_size = 0;
	info->prefix = 0;
	info->s_len = 0;
	info->space_len = 0;
	info->zero_len = 0;
	info->write_count = 0;
}

void	ft_eval_flag(const char **format, t_info *info)
{
	while (1)
	{
		if (**format == '-')
			info->minus_flag = TRUE;
		else if (**format == '0')
			info->zero_flag = TRUE;
		else if (**format == '#')
			info->sharp_flag = TRUE;
		else if (**format == ' ')
			info->space_flag = TRUE;
		else if (**format == '+')
			info->plus_flag = TRUE;
		else
			break;
		(*format)++;
	}
}

void	ft_eval_field_width(const char **format, t_info *info)
{
	info->field_width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void	ft_eval_precision(const char **format, t_info *info)
{
	if (**format != '.')
		return ;
	(*format)++;
	info->precision = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void	ft_eval_specifier(const char **format, t_info *info)
{
	info->specifier = **format;
}