#include "libftprintf.h"
//#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%s\n", TYPES);
	//printf("%p\n", &TYPES);
	printf("printf    [%-6s|%-10d|%010d|%-10d|%-10d]\n", "abcd", 2, 3, 4, 5);
	printf("\n\n\n");
	ft_printf("ft_printf [%s|%-10d|%010d|%-10d|%-10d]\n", "", 2, 3, 4, 5);
	printf("\n\n\n");
	//printf("%ld\n", sizeof(long long));
/*	if (system ("valgrind -s test") == 0)
		return (0);*/
	return (0);
}
