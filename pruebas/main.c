#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>

char	*func1(char *d1, char **d2)
{
	char	*dd1;
	char	*dd2;

	dd1 = (char *)malloc(50);
	dd2 = (char *)malloc(60);
	memset(dd1, 49, 50);
	memset(dd2, 50, 60);
	d1 = dd1;
	&d2[2] = &dd1;
	&d2[1] = &dd2;
	return (dd1);
}

int	main(void)
{
	char	*a1;
	char	**a2[10];

	a1 = malloc(1);
	//a2 = malloc(10 * sizeof(char *));
	func1(a1, &a2);
	return (0);
}