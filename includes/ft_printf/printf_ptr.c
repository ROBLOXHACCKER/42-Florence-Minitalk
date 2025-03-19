/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrogi <pbrogi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:59:04 by pbrogi            #+#    #+#             */
/*   Updated: 2024/12/14 09:21:09 by pbrogi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	size_hex_address(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static int	ft_hex_address(unsigned long long n)
{
	char	*base_16;
	int		size;

	base_16 = "0123456789abcdef";
	size = size_hex_address(n);
	if (n >= 16)
	{
		if (ft_hex_address(n / 16) == -1)
			return (-1);
	}
	if (write(1, &base_16[n % 16], 1) == -1)
		return (-1);
	return (size);
}

int	printf_ptr(void *ptr)
{
	int	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	n = ft_hex_address((unsigned long long)ptr);
	if (n != 0)
		return (n + 2);
	return (3);
}
