/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:10:29 by hurasmi           #+#    #+#             */
/*   Updated: 2025/03/24 13:44:53 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CLIENT_H
# define UTILS_CLIENT_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <signal.h>

extern int	g_server_pid;

unsigned char	char_to_bit(char c)
{
	unsigned char	bits;
	int				max_bit;

	max_bit = 7;
	bits = 0;
	while (max_bit >= 0)
	{
		bits |= ((c >> max_bit) & 1) << (7 - max_bit);
		max_bit--;
	}
	return (bits);
}

void	send_bit(unsigned char sig)
{
	if (sig == 0)
	{
		kill(g_server_pid, SIGUSR1);
	}
	else if (sig == 1)
	{
		kill(g_server_pid, SIGUSR2);
	}
}

void	send_to_server(unsigned char byte_to_send)
{
	unsigned char	bit;
	int				max_bits;

	max_bits = 7;
	while (max_bits >= 0)
	{
		bit = (byte_to_send >> max_bits) & 1;
		send_bit(bit);
		usleep(100);
		max_bits--;
	}
}

void	send_message(char *message)
{
	unsigned char	byte_to_send;

	while (*message)
	{
		byte_to_send = *message;
		send_to_server(byte_to_send);
		message++;
	}
	byte_to_send = '\0';
	send_to_server(byte_to_send);
}

#endif
