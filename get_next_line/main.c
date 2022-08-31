/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:30:44 by anacamilalu       #+#    #+#             */
/*   Updated: 2022/08/31 16:24:17 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include "src/get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;			// Casting argc to quiet the compiler's warnings.
	fd = open(argv[1], O_RDONLY); 	// Open the file given as an argument at program launch
	if (fd)
	{
		line = "";			// Initialize this variable to be able to use it in the following loop
		while (line != NULL)
		{
			line = get_next_line(fd);
			printf("%s", line);	// We're omitting any \n in this printf because get_next_line is supposed to include the \n for each line
		}
		fd = close(fd);
	}
	return (0);
}
