/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:09:25 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 14:33:49 by mayocorn         ###   ########.fr       */
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

static void	ft_write(t_info *info)
{
	if (info->write_count == ERROR)
		return ;
	info->write_count = write(1, info->str, info->buffer_size);
	free(info->str);
}

static int	ft_parse_format(const char *format, t_info *info)
{
	int	result;
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_eval_format(&format, info);
			ft_write(info);
			result = info->write_count;
		}
		else
			result = write(1, format, 1);
		if (result == -1 || INT_MAX - ret < result)
			return (-1);
		ret += result;
		format++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_info	info;

	va_start(info.args, format);
	ret = ft_parse_format(format, &info);
	va_end(info.args);
	return (ret);
}
