/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:00:32 by pbrogi            #+#    #+#             */
/*   Updated: 2025/03/24 13:42:13 by hurasmi          ###   ########.fr       */
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
	static int	i;
	static int	ascii;
	static char	message[1024];
	static int	index;

	i = 7;
	index = 0;
	ascii = 0;
	if (sig == SIGUSR2)
		ascii += pow_two(i);
	if (i == 0)
	{
		message[index] = ascii;
		index++;
		if (ascii == 0)
		{
			message[index] = '\0';
			ft_printf("%s\n", message);
			index = 0;
		}
		i = 7;
		ascii = 0;
	}
	else
		i--;
}

#endif