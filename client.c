/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:28:42 by hurasmi           #+#    #+#             */
/*   Updated: 2025/03/19 14:31:11 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mini-talk.h"

int g_server_pid;

int main(int argc, char *argv[])
{
    if(argc != 3 || kill(ft_atoi(argv[1]), 0) == -1 || ft_atoi(argv[1]) < 0)\
    {
        ft_printf("Errore: incorrect input values\n");
        return -1;
    }
    
    g_server_pid = ft_atoi(argv[1]);
    char *client_message = (char *)malloc(ft_strlen(argv[2]) * sizeof(char));
    
    sendBitMessage(g_server_pid, client_message);
    
    free(client_message);
    
    return 0;
}