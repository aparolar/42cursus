/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:25:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/08 18:44:02 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	line = 0;
	fd = open("get_next_line.h", O_RDONLY);
	//fd = open("nl", O_RDONLY);
	//line = "";
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret >= 0)
		{
			printf("%s\n", line);
			free(line);
			line = NULL;
		}
	}
	//system("leaks myld");
	return (0);
}
