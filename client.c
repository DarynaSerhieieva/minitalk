#include "libft.h"
#include "minitalk.h"

void send_message(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
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
	return (0);
}
