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
int		ft_print_di(t_info info);
int		ft_right_write(size_t length, char *s);
int		ft_left_write(size_t length, char *s);
int		ft_zeropd_write(size_t length, char *s);
char	*ft_trim_number(t_info info, int n, size_t length);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
size_t	ft_count_digit(int n);
#endif