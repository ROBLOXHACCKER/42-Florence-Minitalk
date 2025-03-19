/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrogi <pbrogi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:58:55 by pbrogi            #+#    #+#             */
/*   Updated: 2024/12/11 11:58:56 by pbrogi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex(unsigned int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	printf_hex(unsigned int n, int x_switch)
{
	char			*base_16;
	int				size;

	size = size_hex(n);
	base_16 = "0123456789abcdef";
	if (x_switch == 0)
		base_16 = "0123456789ABCDEF";
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (printf_hex(n / 16, x_switch) == -1)
			return (-1);
		if (printf_hex(n % 16, x_switch) == -1)
			return (-1);
	}
	return (size);
}
