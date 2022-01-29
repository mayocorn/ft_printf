#include "include/ft_printf.h"
#include <stdio.h>

int main()
{
	int a,b;
	a=ft_printf("123\n");
	b=printf("123\n");
	printf("%d\n",a);
	printf("%d\n",b);
	
	// puts("********************");
	// a=ft_printf("A%cA\n", 'a');
	// b=printf("A%cA\n", 'a');
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	
	// puts("********************");
	// a=ft_printf("A%-3cA\n", 'a');
	// b=printf("A%-3cA\n", 'a');
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********************");
	// a=ft_printf("A%.cA\n", 'a');
	// b=printf("A%.cA\n", 'a');
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********************");
	// a=ft_printf("A%#cA\n", 'a');
	// b=printf("A%#cA\n", 'a');
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********************");
	// a=ft_printf("A% cA\n", 'a');
	// b=printf("A% cA\n", 'a');
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********************");
	// a=ft_printf("A%+cA\n", 'a');
	// b=printf("A%+cA\n", 'a');
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	//s
	
	// puts("********A%sA************");
	// a=ft_printf("A%sA\n", "HELLO");
	// b=printf("A%sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********A%3sA************");
	// a=ft_printf("A%3sA\n", "HELLO");
	// b=printf("A%3sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("*********A%5sA***********");
	// a=ft_printf("A%5sA\n", "HELLO");
	// b=printf("A%5sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********A%6A************");
	// a=ft_printf("A%6sA\n", "HELLO");
	// b=printf("A%6sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********A%03sA************");
	// a=ft_printf("A%03sA\n", "HELLO");
	// b=printf("A%03sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("*********%-8s***********");
	// a=ft_printf("A%-8sA\n", "HELLO");
	// b=printf("A%-8sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("*********%.s***********");
	// a=ft_printf("A%.sA\n", "HELLO");
	// b=printf("A%.sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("*********%.1s***********");
	// a=ft_printf("A%.1sA\n", "HELLO");
	// b=printf("A%.1sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	//d,i

#include <limits.h>
	puts("********A%dA***********");
	a=printf(" %p %p ", 0, 0);
	b=ft_printf(" %p %p ", 0, 0);
//	b=ft_printf(" NULL %s NULL ", NULL);
	printf("%d\n",a);
	printf("%d\n",b);
	
	// puts("********A%4dA***********");
	// a=ft_printf("A%4dA\n", 12);
	// b=printf("A%4dA\n", 12);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********A%dA***********");
	// a=ft_printf("A%.dA\n", 0);
	// b=printf("A%.dA\n", 0);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********A%dA***********");
	// a=ft_printf("A%6.5dA\n", 12);
	// b=printf("A%6.5dA\n", 12);
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********A%dA***********");
	// a=ft_printf("A%5dA\n", -12);
	// b=printf("A%5dA\n", -12);
	// printf("%d\n",a);
	// printf("%d\n",b);
	// puts("********A%dA***********");
	// a=ft_printf("A%.5dA\n", -12);
	// b=printf("A%.5dA\n", -12);
	// printf("%d\n",a);
	// printf("%d\n",b);
	// puts("********A%dA***********");
	// a=ft_printf("A%3.dA\n", 0);
	// b=printf("A%3.dA\n", 0);
	// printf("%d\n",a);
	// printf("%d\n",b);
	return 0;
}