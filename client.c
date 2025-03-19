/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:28:42 by hurasmi           #+#    #+#             */
/*   Updated: 2025/03/19 17:24:52 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils_client.h"

int g_server_pid;

int main(int argc, char *argv[])
{
    if(argc != 3 ||  ft_atoi(argv[1]) < 0 || kill(ft_atoi(argv[1]), 0) == -1)
    {
        ft_printf("Errore: incorrect input values\n");
        return -1;
    }
    
    g_server_pid = ft_atoi(argv[1]);
    
    
    ft_printf("Client message: %s\n", argv[2]);
    
    char *client_message = argv[2];
    
    sendMessage(client_message);
    
    return 0;
}


