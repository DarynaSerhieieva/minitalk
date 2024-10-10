#include "minitalk.h"
#include "libft.h"

volatile sig_atomic_t g_bit = 0;

void	handle_signal(int sig)
{
	static int	bits_received = 0;
	static char	current_char = 0;

	// SIGUSR1 is bit 0, SIGUSR2 is bit 1
	if (sig == SIGUSR1)
		current_char |= (0 << bits_received);
	else if (sig == SIGUSR2)
		current_char |= (1 << bits_received);

	bits_received++;

	// Once we receive 8 bits, we can print the character
	if (bits_received == 8)
	{
		write(1, &current_char, 1); // Write the character to stdout
		bits_received = 0;
		current_char = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("PID: %u\n", server_pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
