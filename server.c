/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:10:22 by pbrogi            #+#    #+#             */
/*   Updated: 2025/03/19 17:13:23 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils_server.h"

int	main()
{
	int		server_pid;
	
	server_pid = getpid();
	ft_printf("Server PID: %d\n\n", server_pid);
	
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	
	while(1)
	{
		pause();
	}
    
	return 0;
}
