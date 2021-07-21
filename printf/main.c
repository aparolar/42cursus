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
	//a = printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011);
	a = 0;//printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011);
	printf("\n");
	//c = ft_printf(" %4s %4s ", "123", "4567");
	//c = ft_printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011);
	c = ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1);
	printf("\n\n\n");
	printf("a = %d , b = %d, c = %d\n",a,b,c);
	//printf("%ld\n", sizeof(long long));
	if (system ("valgrind -s test") == 0)
		return (0);
	return (0);
}
