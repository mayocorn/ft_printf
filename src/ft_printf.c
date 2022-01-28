/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:09:25 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 08:38:57 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/ft_printf.h"

static void	ft_eval_format(const char **format, t_info *info)
{
	ft_init_info(info);
	ft_eval_flag(format, info);
	ft_eval_field_width(format, info);
	ft_eval_precision(format, info);
	ft_eval_specifier(format, info);
}

static void	ft_generate_str(t_info *info)
{
	if (info->specifier == 'c')
		ft_generate_c(info);
	else if (info->specifier == 's')
		ft_generate_s(info);
	else if (info->specifier == 'p')
		ft_generate_p(info);
	else if (info->specifier == 'd' || info->specifier == 'i')
		ft_generate_di(info);
	else if (info->specifier == 'u')
		ft_generate_u(info);
	else if (info->specifier == 'x' || info->specifier == 'X')
		ft_generate_x(info);
	else if (info->specifier == '%')
		info->write_count = write(1, "%", 1);
	else
		info->write_count = -1;
}

static void	ft_write(t_info *info)
{
	ft_generate_str(info);
	if (info->write_count == -1)
		return ;
	info->write_count = write(1, info->str, info->buffer_size);
	free(info->str);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		result;
	t_info	info;

	ret = 0;
	va_start(info.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_eval_format(&format, &info);
			ft_write(&info);
			result = info.write_count;
		}
		else
			result = write(1, format, 1);
		if (result == -1)
			return (-1);
		ret += result;
		format++;
	}
	va_end(info.args);
	return (ret);
}
