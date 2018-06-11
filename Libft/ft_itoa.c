/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 10:43:08 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/06 00:06:48 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*value;
	int		len;
	int		i;

	len = ft_count_digit(n);
	if (!(value = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = len - 1;
	if (n == 0)
		value[0] = '0';
	if (n < 0)
	{
		value[0] = '-';
		value[i] = (n % 10) * -1 + '0';
		n /= 10 * -1;
		i--;
	}
	while ((n / 10) != 0 || n != 0)
	{
		value[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	value[len] = '\0';
	return (value);
}
