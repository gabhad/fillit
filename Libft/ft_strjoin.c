/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 02:53:54 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 20:58:40 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(cat = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memmove(cat, s1, ft_strlen(s1));
	ft_memmove((cat + ft_strlen(s1)), s2, ft_strlen(s2));
	cat[len] = '\0';
	return (cat);
}
