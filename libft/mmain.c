#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	size_t	len;
	char	*i;

	s1 = "MZIRIBMZIRIBMZE123";
	s2 = "MZIRIBMZE";
	len = ft_strlen(s2);
	printf("Iniciando\n");
	i = ft_strnstr(s1, s2, len);
	printf("%s\n", i);
	return (0);
}