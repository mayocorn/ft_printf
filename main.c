#include "include/ft_printf.h"
#include <stdio.h>

int main()
{
	int a,b;
	// a=ft_printf("123\n");
	// b=printf("123\n");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("********************");
	// a=ft_printf("A%cA\n", 'a');
	// b=printf("A%cA\n", 'a');
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	
	puts("********************");
	a=ft_printf("A%-3cA\n", 'a');
	b=printf("A%-3cA\n", 'a');
	printf("%d\n",a);
	printf("%d\n",b);
	
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
	
	// puts("*********%08s***********");
	// a=ft_printf("A%08sA\n", "HELLO");
	// b=printf("A%08sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	
	// puts("*********%.s***********");
	// a=ft_printf("A%.sA\n", "HELLO");
	// b=printf("A%.-1sA\n", "HELLO");
	// printf("%d\n",a);
	// printf("%d\n",b);
	return 0;
}