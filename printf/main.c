#include "libftprintf.h"
//#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%s\n", TYPES);
	//printf("%p\n", &TYPES);
	printf("printf    [%-d - %-10d - %010d - %-10d - %-10d - %.5f]\n", 1, 2, 3, 4, 5, 6.5);
	ft_printf("ft_printf [%-d - %-10d - %010d - %-10d - %-10d - %.5f]\n", 1, 2, 3, 4, 5, 6.5);
	printf("\n\n\n");
	if (system ("valgrind -s test") == 0)
		return (0);
	return (0);
}
