/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:31:00 by hurasmi           #+#    #+#             */
/*   Updated: 2025/03/19 16:23:59 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils_server.h"



int main()
{
    int server_pid;
    
    server_pid = getpid();

    ft_printf("Server PID: %d\n", server_pid);
    
    StructSignalHandler();
    
    ft_printf("Waiting message..\n");

    while(1)
    {
        usleep(5000);
    }
      
    


    return 0;
}