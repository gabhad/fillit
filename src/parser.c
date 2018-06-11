/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:17:28 by acarcena          #+#    #+#             */
/*   Updated: 2018/02/01 14:18:28 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			move_point_origin(t_point *tet)
{
	size_t	sharp;

	sharp = 3;
	while (sharp > 0)
	{
		tet[sharp].x -= tet[0].x;
		tet[sharp].y -= tet[0].y;
		sharp--;
	}
	tet[0].x = 0;
	tet[0].y = 0;
}

static t_point		*tab_tet(char *file)
{
	t_point	*tet;
	size_t	i;
	size_t	sharp;

	i = 0;
	sharp = 0;
	if (!(tet = (t_point*)malloc(sizeof(t_point) * 4)))
		return (NULL);
	while (i < 19 && sharp < 4)
	{
		if (file[i] == '#')
		{
			tet[sharp].y = i / (L_T + 1);
			tet[sharp].x = i % (L_T + 1);
			sharp++;
		}
		i++;
	}
	move_point_origin(tet);
	return (tet);
}

size_t				nb_sharp(char *file, size_t nb_tet)
{
	size_t index;
	size_t tet;
	size_t sharp;

	index = 0;
	tet = 0;
	while (tet < nb_tet)
	{
		sharp = 0;
		while (index < L_T * (L_T + 1) * (tet + 1) + tet)
		{
			if (file[index] == '#')
				sharp++;
			index++;
		}
		if (sharp != 4)
			display_error();
		tet++;
	}
	return (1);
}

t_point				**parser(char *file, int length)
{
	size_t		nb_tet;
	size_t		tet;
	t_point		**parser;

	nb_tet = file_is_valid(file, length);
	if (!(parser = (t_point**)malloc(sizeof(t_point*) * (nb_tet + 1))))
		return (NULL);
	tet = 0;
	while (tet < nb_tet)
	{
		parser[tet] = tab_tet(file + L_T * (L_T + 1) * tet + tet);
		tet++;
	}
	parser[tet] = NULL;
	return (parser);
}
