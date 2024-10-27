/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dserhiei <dserhiei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:36:27 by dserhiei          #+#    #+#             */
/*   Updated: 2024/10/27 20:08:59 by dserhiei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <sys/types.h>

void	send_message(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c << i & 128)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	int					server_pid;
	int					i;

	server_pid = 0;
	i = 0;
	if (argc != 3)
	{
		ft_printf("Too much or too few arguments!\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (!server_pid)
	{
		ft_printf("The PID is not correct!\n");
		return (1);
	}
	message = argv[2];
	while (message[i] != '\0')
	{
		send_message(server_pid, message[i]);
		i++;
	}
	send_message(server_pid, (char ) '\n');
	return (0);
}
