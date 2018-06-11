/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:43:47 by acarcena          #+#    #+#             */
/*   Updated: 2018/02/11 19:44:29 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**set_map(size_t width)
{
	char	**map;
	size_t	init;
	size_t	char_init;

	init = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (width + 1))))
		return (NULL);
	while (init < width)
	{
		char_init = 0;
		if (!(map[init] = (char*)malloc(sizeof(char) * (width + 1))))
			return (NULL);
		while (char_init < width)
		{
			map[init][char_init] = '.';
			char_init++;
		}
		map[init][width] = '\0';
		init++;
	}
	map[width] = NULL;
	return (map);
}

static t_struct	algo_square(t_point **parser)
{
	t_struct	algo;

	algo.nb_tt_tet = 0;
	algo.width = 2;
	while (parser[algo.nb_tt_tet])
		algo.nb_tt_tet++;
	while ((algo.nb_tt_tet * L_T) > (size_t)((algo.width) * (algo.width)))
		algo.width++;
	return (algo);
}

void			print_map(char **map)
{
	size_t	ligns;

	ligns = 0;
	while (map[ligns])
	{
		ft_putstr(map[ligns]);
		write(1, "\n", 1);
		ligns++;
	}
}

void			start_solver(t_point **parser)
{
	t_struct	algo;
	char		**map;
	size_t		result;

	algo = algo_square(parser);
	result = 0;
	while (result != 1)
	{
		map = set_map(algo.width);
		if ((result = solver(map, parser, 0, algo)) == 1)
			print_map(map);
		set_free_map(map);
		algo.width++;
	}
	set_free_parser(parser);
}
