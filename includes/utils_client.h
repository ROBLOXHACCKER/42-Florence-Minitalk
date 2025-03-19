/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:10:29 by hurasmi           #+#    #+#             */
/*   Updated: 2025/03/19 17:10:31 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
#define MINI_TALK_H

#include "../includes/ft_printf/ft_printf.h"
#include "../includes/libft/libft.h"
#include <signal.h>

extern int g_server_pid;

unsigned char charToBit(char c)
{
    unsigned char bits = 0;
    int max_bit = 7;
    
    while (max_bit >= 0)
    {
        bits |= ((c >> max_bit) & 1) << (7 - max_bit);
        max_bit--;
    }
    
    return bits;
}

void sendBit(unsigned char sig)
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

void sendToServer(unsigned char byte_to_send)
{
    int max_bits = 7;

    while (max_bits >= 0)
    {
        unsigned char bit = (byte_to_send >> max_bits) & 1;
        sendBit(bit);
        usleep(100);
        max_bits--;
    }
}

void sendMessage(char *message)
{
    while (*message)
    {
        unsigned char byte_to_send = *message;
        
        sendToServer(byte_to_send);
        message++;
    }

    unsigned char byte_to_send = '\0';
    sendToServer(byte_to_send);
}
#endif
