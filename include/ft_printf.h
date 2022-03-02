/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:48:38 by stsunoda          #+#    #+#             */
/*   Updated: 2022/03/02 15:16:46 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# define ERROR -1

typedef struct s_info
{
	bool	minus_flag;
	bool	zero_flag;
	bool	sharp_flag;
	bool	space_flag;
	bool	plus_flag;
	int		field_width;
	int		precision;
	va_list	args;
	size_t	s_len;
	char	prefix[3];
	int		buffer_size;
	int		space_len;
	int		zero_len;
	char	*str;
	int		write_count;
}	t_info;
int		ft_printf(const char *format, ...);
void	ft_init_info(t_info *info);
void	ft_eval_flag(const char **format, t_info *info);
void	ft_eval_field_width(const char **format, t_info *info);
void	ft_eval_precision(const char **format, t_info *info);
void	ft_eval_specifier(const char **format, t_info *info);
void	ft_generate_c(t_info *info);
void	ft_generate_s(t_info *info);
void	ft_generate_p(t_info *info);
void	ft_generate_di(t_info *info);
void	ft_generate_u(t_info *info);
void	ft_generate_x(t_info *info, char c);
void	ft_generate_ps(t_info *info);
void	ft_setinfo(t_info *info);
void	ft_setstr(t_info *info, char *s);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_count_digit(int n);
int		ft_count_digit_u(unsigned int n);
int		ft_count_digit_h(unsigned long n);
char	*ft_utoa(unsigned int n);
char	*ft_utohex(unsigned long n);
#endif