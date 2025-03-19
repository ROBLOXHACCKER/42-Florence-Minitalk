/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:54:46 by hurasmi           #+#    #+#             */
/*   Updated: 2025/03/19 16:18:38 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ft_printf.h"
#include "../includes/libft/libft.h"
#include <signal.h>



void ifChar(int count_bit, unsigned char byte, char *message ,int *index)
{
    if(count_bit == 8)
    {
        if(byte == '\0')
        {
            message[*index] = '\0';
            ft_printf("%s\n",message);
            *index = 0;
        }        
    }else
    {
        message[*index] = byte;
        (*index)++;
    }
    byte = 0;
    count_bit = 0;
}

void SignalHandler(int sig)
{
    static unsigned char byte = 0; 
    static int bit_count = 0;  
    static char message[1024];
    static int index = 0;  
    
    if(sig == SIGUSR2)
        byte |= (1 <<(7 - bit_count));
        
    bit_count++;
        
    ifChar(bit_count, byte, message, &index);
} 

void StructSignalHandler()
{
    struct sigaction sa;
    sa.sa_handler = SignalHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    
    if(sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("Errore: handler del segnale SIGUSR1");
        _exit(1);
    }
    if(sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("Errore: handler del segnale SIGUSR2");
        _exit(1);
    }
}
