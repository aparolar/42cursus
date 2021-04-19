#include "libft.h"

int	main(void)
{
	char	**str;
	int		i;
/*
	str = ft_split("      split       this for   me  !", ' ');
	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
*/
	str = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	str = ft_split("  tripouille  42", 0);
	i = 0;
	while (str && str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}