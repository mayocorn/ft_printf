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
char	*ft_trim_number(t_info *info, int n, size_t length);
void	ft_setstr(t_info *info, char *s);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
size_t	ft_count_digit(int n);
size_t	ft_count_digit_u(unsigned int n);
#endif