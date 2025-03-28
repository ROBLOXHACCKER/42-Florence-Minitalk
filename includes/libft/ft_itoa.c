/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrogi <pbrogi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:46:51 by pbrogi            #+#    #+#             */
/*   Updated: 2024/11/21 12:32:28 by pbrogi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(long a)
{
	size_t	len;

	len = 0;
	if (a < 0)
	{
		a = -a;
		len++;
	}
	while (a > 0)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

char	*ft_tab0(void)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 2);
	if (!tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	long	a;
	char	*tab;
	size_t	len;

	a = n;
	len = ft_len(a);
	tab = NULL;
	if (a == 0)
		return (ft_tab0());
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len--] = '\0';
	if (a < 0)
	{
		tab[0] = '-';
		a = -a;
	}
	while (a > 0)
	{
		tab[len] = a % 10 + '0';
		a = a / 10;
		len--;
	}
	return (tab);
}
