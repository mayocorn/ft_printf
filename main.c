#include <stdio.h>
#include "include/ft_printf.h"

int main()
{
    int i = 0;
    char *s = (char *)calloc(1, (size_t)INT_MAX + 10);
    memset(s, 'a', (size_t)INT_MAX + 5);
    i = ft_printf("%s\n", s);
    printf("%d\n", i);
    return (0);
}