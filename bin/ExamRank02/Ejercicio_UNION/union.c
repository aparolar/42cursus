/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:08:27 by icastell          #+#    #+#             */
/*   Updated: 2021/10/26 16:59:37 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char			usedchar[255];
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	if (argc == 3)
	{
		while (i < 255)
			usedchar[i++] = 0;
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				c = argv[i][j];
				if (!usedchar[c])
				{
					usedchar[c] = 1;
					write(1, &c, 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
