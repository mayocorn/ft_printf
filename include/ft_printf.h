#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
typedef int bool;
#define TRUE 1
#define FALSE 0
typedef struct s_info
{
	bool	minus_flag;
	bool	zero_flag;
	bool	sharp_flag;
	bool	space_flag;
	bool	plus_flag;
	int		field_width;
	int		precision;
	char	specifier;
	va_list	args;
}	t_info;
int		ft_printf(const char *format, ...);
void	ft_init_info(t_info *info);
void	ft_eval_flag(const char **format, t_info *info);
void	ft_eval_field_width(const char **format, t_info *info);
void	ft_eval_precision(const char **format, t_info *info);
void	ft_eval_specifier(const char **format, t_info *info);
int		ft_print_c(t_info info);
int		ft_print_s(t_info info);
int		ft_write(t_info info, int length, char *s);
int		ft_right_write(int length, char *s);
int		ft_left_write(int length, char *s);
int		ft_zeropd_write(int length, char *s);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
#endif