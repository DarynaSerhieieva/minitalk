#include "libft.h"
#include "minitalk.h"

void send_char(pid_t server_pid, char c)
{
    for (int i = 0; i < 8; i++)
    {
        if (c & (1 << i))
            kill(server_pid, SIGUSR2); // Send bit 1 as SIGUSR2
        else
            kill(server_pid, SIGUSR1); // Send bit 0 as SIGUSR1

        usleep(100); // Give the server time to process the signal
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];

    // Send each character of the message
    for (int i = 0; message[i] != '\0'; i++)
    {
        send_char(server_pid, message[i]);
    }

    return 0;
}

int	main(int argc, char **argv)
{
	char				message;
	int					pid;

	pid = 0;
	if (argc != 3)
	{
		ft_printf("Too much or too few arguments!\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("The PID is not correct!\n");
		return (1);
	}
	message = argv[2];
	send_message(pid, message);
	return (0);
}
