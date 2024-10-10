#include "libft.h"
#include "minitalk.h"

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
