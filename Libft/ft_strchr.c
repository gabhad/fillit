/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:07:52 by acarcena          #+#    #+#             */
/*   Updated: 2017/11/23 13:25:06 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	l;

	i = 0;
	l = (char)c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == l)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
