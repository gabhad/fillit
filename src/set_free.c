/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 20:03:59 by acarcena          #+#    #+#             */
/*   Updated: 2018/02/11 20:30:20 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_free_map(char **map)
{
	size_t ligns;

	ligns = 0;
	while (map[ligns])
	{
		free(map[ligns]);
		map[ligns] = NULL;
		ligns++;
	}
	free(map);
	map = NULL;
}

void	set_free_parser(t_point **parser)
{
	size_t	tet;

	tet = 0;
	while (parser[tet])
	{
		free(parser[tet]);
		parser[tet] = NULL;
		tet++;
	}
	free(parser);
	parser = NULL;
}
