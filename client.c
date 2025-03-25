/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:28:42 by hurasmi           #+#    #+#             */
/*   Updated: 2025/03/25 14:42:33 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils_client.h"

int		g_server_pid;

int	main(int argc, char *argv[])
{
	char	*client_message;

	if (argc != 3 || ft_atoi(argv[1]) < 0 || kill(ft_atoi(argv[1]), 0) == -1)
	{
		ft_printf("Errore: incorrect input values\n");
		return (-1);
	}
	g_server_pid = ft_atoi(argv[1]);
	client_message = argv[2];
	send_message(client_message);
	return (0);
}
