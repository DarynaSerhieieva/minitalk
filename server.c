#include "minitalk.h"
#include "libft.h"

void	sig_proc()
{

}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %u\n", pid);
	signal(SIGUSR1, sig_proc);
	signal(SIGUSR2, sig_proc);
	while (1)
		pause();
}
