#include "libft.h"
#include <stdio.h>

void	main(void)
{
	char *s1 = "atoms\0\0\0\0";
	char *s2 = "atoms\0abc";
	int len = 8;
	int i = 0;

	printf("Iniciando\n");
	i = ft_strncmp(s1, s2, len);
}
