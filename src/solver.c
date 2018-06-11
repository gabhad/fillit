/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:34:11 by acarcena          #+#    #+#             */
/*   Updated: 2018/02/01 17:34:41 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		erase_tet(char **map, size_t nb_tet, int width)
{
	char	letter;
	size_t	nbr_lt;
	t_point	coord;

	letter = 65 + nb_tet;
	coord.y = 0;
	nbr_lt = 0;
	while (coord.y < width && nbr_lt < L_T)
	{
		coord.x = 0;
		while (coord.x < width && nbr_lt < L_T)
		{
			if (map[coord.y][coord.x] == letter)
			{
				map[coord.y][coord.x] = '.';
				nbr_lt++;
			}
			coord.x++;
		}
		coord.y++;
	}
}

static size_t	set_tet(char **map, t_point *tet, size_t nb_tet, t_point crd)
{
	int		lg_map;
	size_t	sharp;
	size_t	verif;

	lg_map = 0;
	sharp = 0;
	verif = 0;
	while (map[0][lg_map] != '\0')
		lg_map++;
	while (sharp < 4)
	{
		if ((crd.y + tet[sharp].y < lg_map) && (crd.x + tet[sharp].x < lg_map)
			&& (crd.x + tet[sharp].x >= 0)
			&& (map[crd.y + tet[sharp].y][crd.x + tet[sharp].x] == '.'))
		{
			map[crd.y + tet[sharp].y][crd.x + tet[sharp].x] = 65 + nb_tet;
			verif++;
			if (verif == 4)
				return (1);
		}
		sharp++;
	}
	erase_tet(map, nb_tet, lg_map);
	return (0);
}

static size_t	set_last_tet(char **map, t_point *tet, size_t nb_tet)
{
	t_point	crd;

	crd.y = 0;
	while (map[crd.y] != '\0')
	{
		crd.x = 0;
		while (map[crd.y][crd.x] != '\0')
		{
			if (map[crd.y][crd.x] == '.' &&
				set_tet(map, tet, nb_tet, crd) == 1)
				return (1);
			crd.x++;
		}
		crd.y++;
	}
	return (0);
}

size_t			solver(char **map, t_point **prs, size_t n_t, t_struct al)
{
	t_point cr;
	size_t	erase;

	cr.y = 0;
	if (n_t == al.nb_tt_tet - 1 && set_last_tet(map, prs[n_t], n_t) == 1)
		return (1);
	while (cr.y < al.width && n_t < al.nb_tt_tet - 1)
	{
		cr.x = 0;
		while (cr.x < al.width && !(erase = 0))
		{
			if (map[cr.y][cr.x] == '.' &&
				(erase = set_tet(map, prs[n_t], n_t, cr)) == 1)
			{
				if (solver(map, prs, n_t + 1, al) == 1)
					return (1);
			}
			if (erase == 1)
				erase_tet(map, n_t, al.width);
			cr.x++;
		}
		cr.y++;
	}
	return (0);
}
