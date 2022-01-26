/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:09:25 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/27 05:40:09 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../libft/libft.h"
#include	"ft_printf.h"
#include	<stdio.h>
void	ft_eval_format(const char **format, t_info *info)
{
	ft_init_info(info);
	ft_eval_flag(format, info);
	ft_eval_field_width(format, info);
	ft_eval_precision(format, info);
	ft_eval_specifier(format, info);
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
			// result = ft_print_arg(format);
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

int main()
{
	ft_printf("%-0#");
}
