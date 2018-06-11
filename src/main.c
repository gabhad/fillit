/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:16:23 by acarcena          #+#    #+#             */
/*   Updated: 2018/01/18 09:23:08 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		main(int ac, char **av)
{
	int		ret;
	int		fd;
	char	buf[BUF_SIZE + 1];
	t_point	**result_parser;

	if (ac != 2)
		return (write(1, "usage: ./fillit source_file\n", 28));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		display_error();
	if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		display_error();
	buf[ret] = '\0';
	result_parser = parser(buf, ret);
	start_solver(result_parser);
	if (close(fd) == -1)
		display_error();
	return (0);
}
