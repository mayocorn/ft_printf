/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:09:25 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/28 10:19:48 by stsunoda         ###   ########.fr       */
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

static int	ft_check_specifier(t_info *info)
{
	if (info->specifier == '%')
		return (write(1, "%", 1));
	else if (info->specifier == 'c')
		return (ft_print_c(info));
	else if (info->specifier == 's')
		return (ft_print_s(info));
	// else if (info->specifier == 'p')
	// 	return (ft_print_p(info));
	else if (info->specifier == 'd' || info->specifier == 'i')
		return (ft_print_di(info));
	// else if (info->specifier == 'u')
	// 	return (ft_print_u(info));
	// else if (info->specifier == 'x' || info->specifier == 'X')
	// 	return (ft_print_xX(info));
	else
		return (-1);
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
			result = ft_check_specifier(&info);
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
