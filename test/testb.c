#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int	a, b;

	(void)argc;
	(void)argv;
	puts("********** test c **********");;
	a = printf("[%c][%-3c][%3c]\n", 0, 0, 0);
	b = ft_printf("[%c][%-3c][%3c]\n", 0, 0, 0);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%c][%-3c][%3c]\n", 1, 300, 'a');
	b = ft_printf("[%c][%-3c][%3c]\n", 1, 300, 'a');
	printf("%d\n",a);
	printf("%d\n",b);
	
	puts("********** test s **********");;
	a = printf("[%s][%-3s][%.3s]\n", "BANANA", "OH", "BANANA");
	b = ft_printf("[%s][%-3s][%.3s]\n", "BANANA", "OH", "BANANA");
	printf("%d\n",a);
	printf("%d\n",b);

	puts("********** test p **********");;
	a = printf("[%p][%-17p][%17p]\n", &a, &a, &a);
	b = ft_printf("[%p][%-17p][%17p]\n", &a, &a, &a);
	printf("%d\n",a);
	printf("%d\n",b);
	
	puts("********** test d **********");;
	a = printf("[%d][%-5d][%05d]\n", 123, 123, 123);
	b = ft_printf("[%d][%-5d][%05d]\n", 123, 123, 123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%d][%-5d][%05d]\n", -123, -123, -123);
	b = ft_printf("[%d][%-5d][%05d]\n", -123, -123, -123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[% .5d][%+-8.5d][% 08.5d]\n", 123, 123, 123);
	b = ft_printf("[% .5d][%+-8.5d][% 08.5d]\n", 123, 123, 123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[% .5d][%+-8.5d][% 08.5d]\n", -123, -123, -123);
	b = ft_printf("[% .5d][%+-8.5d][% 08.5d]\n", -123, -123, -123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%+d][% -3.d][% d]\n", 0, 0, 0);
	b = ft_printf("[%+d][% -3.d][% d]\n", 0, 0, 0);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%+d][% -3.d][% d]\n", INT_MAX, INT_MIN, INT_MAX);
	b = ft_printf("[%+d][% -3.d][% d]\n", INT_MAX, INT_MIN, INT_MAX);
	printf("%d\n",a);
	printf("%d\n",b);
	
	// puts("********** test i **********");;
	// a = printf("[%i][%-5i][%05i]\n", 123, 123, 123);
	// b = ft_printf("[%i][%-5i][%05i]\n", 123, 123, 123);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[%i][%-5i][%05i]\n", -123, -123, -123);
	// b = ft_printf("[%i][%-5i][%05i]\n", -123, -123, -123);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[% .5i][%+-8.5i][% 08.5i]\n", 123, 123, 123);
	// b = ft_printf("[% .5i][%+-8.5i][% 08.5i]\n", 123, 123, 123);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[% .5i][%+-8.5i][% 08.5i]\n", -123, -123, -123);
	// b = ft_printf("[% .5i][%+-8.5i][% 08.5i]\n", -123, -123, -123);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[%+i][% -3.i][% i]\n", 0, 0, 0);
	// b = ft_printf("[%+i][% -3.i][% i]\n", 0, 0, 0);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[%+i][% -3.i][% i]\n", INT_MAX, INT_MIN, INT_MAX);
	// b = ft_printf("[%+i][% -3.i][% i]\n", INT_MAX, INT_MIN, INT_MAX);
	// printf("%d\n",a);
	// printf("%d\n",b);

	puts("********** test u **********");;
	a = printf("[%u][%-5u][%05u]\n", 123, 123, 123);
	b = ft_printf("[%u][%-5u][%05u]\n", 123, 123, 123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%.5u][%-8.5u][%08.2u]\n", 123, 123, 123);
	b = ft_printf("[%.5u][%-8.5u][%08.2u]\n", 123, 123, 123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%u][%-3.u][%3.0u]\n", 0, 0, 0);
	b = ft_printf("[%u][%-3.u][%3.0u]\n", 0, 0, 0);
	printf("%d\n",a);
	printf("%d\n",b);
	
	puts("********** test x **********");;
	a = printf("[%x][%-5x][%05x]\n", 123, 123, 123);
	b = ft_printf("[%x][%-5x][%05x]\n", 123, 123, 123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%.5x][%-8.5x][%08.2x]\n", 123, 123, 123);
	b = ft_printf("[%.5x][%-8.5x][%08.2x]\n", 123, 123, 123);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%x][%-3.x][%3.0x]\n", 0, 0, 0);
	b = ft_printf("[%x][%-3.x][%3.0x]\n", 0, 0, 0);
	printf("%d\n",a);
	printf("%d\n",b);
	
	a = printf("[%x][%-.20x][%#x]\n", UINT_MAX, UINT_MAX, UINT_MAX);
	b = ft_printf("[%x][%-.20x][%#x]\n", UINT_MAX, UINT_MAX, UINT_MAX);
	printf("%d\n",a);
	printf("%d\n",b);
	
	// puts("********** test X **********");;
	// a = printf("[%X][%-5X][%05X]\n", 123, 123, 123);
	// b = ft_printf("[%X][%-5X][%05X]\n", 123, 123, 123);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[%.5X][%-8.5X][%08.2X]\n", 123, 123, 123);
	// b = ft_printf("[%.5X][%-8.5X][%08.2X]\n", 123, 123, 123);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[%X][%-3.X][%3.0X]\n", 0, 0, 0);
	// b = ft_printf("[%X][%-3.X][%3.0X]\n", 0, 0, 0);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// a = printf("[%X][%-.20X][%#X]\n", UINT_MAX, UINT_MAX, UINT_MAX);
	// b = ft_printf("[%X][%-.20X][%#X]\n", UINT_MAX, UINT_MAX, UINT_MAX);
	// printf("%d\n",a);
	// printf("%d\n",b);
	return 0;
}