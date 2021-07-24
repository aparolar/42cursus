#include "ft_printf.h"
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
	c = ft_printf(" %p ", -1);
	//c = ft_printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011);
	//c = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%    %%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", "-42", -42 ,-42 ,-42, 42, 'C'    , "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n\n\n");
	printf("a = %d , b = %d, c = %d\n",a,b,c);
	//printf("%ld\n", sizeof(long long));
	if (system ("valgrind -s test") == 0)
		return (0);
	return (0);
}
