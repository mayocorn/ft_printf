/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 04:50:22 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:16:08 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_info(t_info *info)
{
	info->minus_flag = false;
	info->zero_flag = false;
	info->sharp_flag = false;
	info->space_flag = false;
	info->plus_flag = false;
	info->field_width = 0;
	info->precision = -1;
	info->str = NULL;
	info->buffer_size = 0;
	ft_bzero(info->prefix, 3);
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
			info->minus_flag = true;
		else if (**format == '0')
			info->zero_flag = true;
		else if (**format == '#')
			info->sharp_flag = true;
		else if (**format == ' ')
			info->space_flag = true;
		else if (**format == '+')
			info->plus_flag = true;
		else
			break ;
		(*format)++;
	}
}

void	ft_eval_field_width(const char **format, t_info *info)
{
	int	result;

	result = ft_atoi2(*format);
	if (result == ERROR)
		info->write_count = ERROR;
	else
		info->field_width = result;
	while (ft_isdigit(**format))
		(*format)++;
}

void	ft_eval_precision(const char **format, t_info *info)
{
	int	result;

	if (**format != '.')
		return ;
	(*format)++;
	result = ft_atoi2(*format);
	if (result == ERROR)
		info->write_count = ERROR;
	else
		info->precision = result;
	while (ft_isdigit(**format))
		(*format)++;
}

void	ft_eval_specifier(const char **format, t_info *info)
{
	if (info->write_count == ERROR)
		return ;
	if (**format == 'c')
		ft_generate_c(info);
	else if (**format == 's')
		ft_generate_s(info);
	else if (**format == 'p')
		ft_generate_p(info);
	else if (**format == 'd' || **format == 'i')
		ft_generate_di(info);
	else if (**format == 'u')
		ft_generate_u(info);
	else if (**format == 'x' || **format == 'X')
		ft_generate_x(info, **format);
	else if (**format == '%')
		ft_generate_ps(info);
	else
		info->write_count = ERROR;
}
