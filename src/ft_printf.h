#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
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
void	ft_init_info(t_info *info);
void	ft_check_flag(const char **format, t_info *info);
#endif