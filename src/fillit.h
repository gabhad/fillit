/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:33:14 by acarcena          #+#    #+#             */
/*   Updated: 2018/02/01 14:27:38 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define BUF_SIZE	4096
# define ABS(X)		(((X) < 0) ? -(X) : (X))
# define L_T		4
# define TET_MIN	1
# define TET_MAX	26

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_struct
{
	size_t			nb_tt_tet;
	int				width;
}					t_struct;

int					main(int ac, char **av);
void				display_error(void);
t_point				**parser(char *file, int lenght);
size_t				file_is_valid(char *file, int lenght);
void				start_solver(t_point **parser);
size_t				solver(char **map, t_point **prs, size_t n_t, t_struct al);
void				set_free_map(char **map);
void				set_free_parser(t_point **parser);
void				print_map(char **map);
size_t				nb_sharp(char *file, size_t nb_tet);

#endif
