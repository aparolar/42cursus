#include "libft.h"

int	main(void)
{
	char	**str;
	int		i;

	str = ft_split("      split       this for   me  !", ' ');
	i = 0;
	while (ft_strncmp(str[i], "", ft_strlen(str[i])))
	{
		printf("%s\n", str[i]);
		i++;
	}
	str = ft_split("      split       this for   me  !       ", ' ');
	i = 0;
	while (ft_strncmp(str[i], "", ft_strlen(str[i])))
	{
		printf("%s\n", str[i]);
		i++;
	}
	str = ft_split("", ' ');
	i = 0;
	while (str && ft_strncmp(str[i], "", ft_strlen(str[i])))
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}