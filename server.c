/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:36:16 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/12 21:18:55 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	handle_signal(int sig)
{
	static int	bits_received = 0;
	static char	current_char = 0;

	if (sig == SIGUSR2)
		current_char |= (1 << bits_received);
	bits_received++;
	if (bits_received == 8)
	{
		write(1, &current_char, 1);
		bits_received = 0;
		current_char = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %u\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
