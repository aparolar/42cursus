/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:25:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/21 12:56:39 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		ret;
	char	**buff[BUFFER_SIZE + 1];

	ret = 1;
	fd = open("get_next_line.h", "r");
	while (ret)
	{
		ret = get_next_line(fd, &buff);
		if (ret >= 0)
		
	}
	return (0);
}
