/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:48:38 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/29 09:49:04 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

typedef struct s_info
{
	int		minus_flag;
	int		zero_flag;
	int		sharp_flag;
	int		space_flag;
	int		plus_flag;
	int		field_width;
	int		precision;
	char	specifier;
	va_list	args;
	char	*str;
	size_t	buffer_size;
	char	prefix[3];
	size_t	s_len;
	size_t	space_len;
	size_t	zero_len;
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
void	ft_generate_x(t_info *info);
void	ft_setstr(t_info *info, char *s);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
size_t	ft_count_digit(int n);
size_t	ft_count_digit_u(unsigned int n);
size_t	ft_count_digit_h(unsigned long n);
char	*ft_utoa(unsigned int n);
char	*ft_utohex(unsigned long n);
#endif