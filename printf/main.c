#include "libftprintf.h"
//#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;
	printf("%s\n", TYPES);
	//printf("%p\n", &TYPES);
	//printf("%lu\n", ft_strlen(""));
	//a = printf("printf    [%s]","");
	//printf("\n\n\n");
	b = 0;//ft_printf("ft_printf [%s]", "");
	//printf("\n\n\n");
	//c = ft_printf("%s%s%s", "1", "2", "3's a charm");
	a = printf("%23s", NULL);
	printf("\n");
	c = ft_printf("%4s %4s", "123", "4567");
	printf("\n\n\n");
	printf("a = %d , b = %d, c = %d\n",a,b,c);
	//printf("%ld\n", sizeof(long long));
/*	if (system ("valgrind -s test") == 0)
		return (0);*/
	return (0);
}
