/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:25:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/23 11:46:20 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
int	main(void)
{
	int		fd;
	int		ret;
	char	*line;


	printf("char ** = %d\n", sizeof(char**));
/*	ret = 1;
	line = 0;
	fd = open("get_next_line.h", O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret >= 0)
			printf("%s\n", line);
	}	
*/	return (0);
}
