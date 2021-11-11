/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:49:36 by icastell          #+#    #+#             */
/*   Updated: 2021/10/26 18:10:17 by icastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char			usedchar[256];
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	if (argc == 3)
	{
		while (i < 256)
			usedchar[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				c =  argv[i][j];
				if (i == 2 && usedchar[c] == 0)
					usedchar[c] = 1;
				if (i == 1 && usedchar[c] == 1)
				{
					write(1, &c, 1);
					usedchar[c] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
