/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:03:39 by acarcena          #+#    #+#             */
/*   Updated: 2018/01/16 06:27:24 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	nb_link_tet(char *file, int i, int tet)
{
	int nb_link;

	nb_link = 0;
	if (file[i - 1] == '#')
		nb_link++;
	if (file[i + 1] == '#')
		nb_link++;
	if (i > L_T * (L_T + 1) * tet + L_T + tet && file[i - (L_T + 1)] == '#')
		nb_link++;
	if (i < (((L_T * (L_T + 1)) * tet) + ((L_T + 1) * L_T * (tet + 1)) - L_T
			+ 2 * tet) && file[i + (L_T + 1)] == '#')
		nb_link++;
	return (nb_link);
}

static int	nb_link_sharp(char *file, int nb_tet)
{
	int index;
	int o_link;
	int mt_link;
	int tet;

	index = 0;
	tet = 0;
	while (tet < nb_tet)
	{
		o_link = 0;
		mt_link = 0;
		while (index < L_T * (L_T + 1) * (tet + 1) + tet)
		{
			if (file[index] == '#' && nb_link_tet(file, index, tet) == 1)
				o_link++;
			else if (file[index] == '#' && nb_link_tet(file, index, tet) > 1)
				mt_link++;
			index++;
		}
		if (o_link + mt_link != L_T || mt_link < 1)
			display_error();
		tet++;
	}
	return (1);
}

static int	verif_syntax(char *file, int length, int nb_tet)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= length && j < nb_tet && file[i] != '\0')
	{
		if ((i + 1 - j) % (L_T + 1) == 0 && file[i] == '\n')
			i++;
		else if ((((i - j) % L_T * (L_T + 1))) == 0 && file[i] == '\n')
		{
			i++;
			j++;
		}
		else if (((i + 1 - j) % (L_T + 1)) != 0 && (file[i] == '.'
				|| file[i] == '#'))
			i++;
		else
			display_error();
	}
	return (1);
}

static int	count_nb_tet(int length)
{
	int i;

	i = 1;
	while (i <= TET_MAX && length != ((i * (L_T + 1) * L_T) + (i - 1)))
	{
		if (i < TET_MAX)
			i++;
		else
			display_error();
	}
	return (i);
}

size_t		file_is_valid(char *file, int length)
{
	int nb_tet;

	nb_tet = count_nb_tet(length);
	if ((nb_tet < TET_MIN) || nb_tet > TET_MAX)
		display_error();
	else if (verif_syntax(file, length, nb_tet) != 1)
		display_error();
	else if (nb_sharp(file, nb_tet) != 1 || nb_link_sharp(file, nb_tet) != 1)
		display_error();
	return (nb_tet);
}
