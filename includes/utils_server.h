/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:00:32 by pbrogi            #+#    #+#             */
/*   Updated: 2025/03/25 14:53:57 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_SERVER_H
# define UTILS_SERVER_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <signal.h>

int	pow_two(int exponent)
{
	int		base;

	base = 1;
	while (exponent > 0)
	{
		base *= 2;
		exponent--;
	}
	return (base);
}

void	signal_handler(int sig)
{
	static int		i = 0;
	static int		ascii = 0;
	static char		message[1024];
	static int		index = 0;

	ascii = (ascii << 1) | (sig == SIGUSR2);
	i++;
	if (i == 8)
	{
		message[index++] = ascii;
		if (ascii == '\0')
		{
			ft_printf("%s\n", message);
			index = 0;
		}
		i = 0;
		ascii = 0;
	}
}

#endif