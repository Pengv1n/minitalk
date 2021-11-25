# include "minitalk.h"

static int g_pause = 0;

void error(char *msg)
{
	ft_putstr_fd("Error!\n", 3);
	if (msg)
		ft_putstr_fd(msg, 3);
	exit(EXIT_FAILURE);
}

void    ft_handler(int sig)
{
	if (sig == SIGUSR2)
		g_pause = 1;
	return ;
}

void    send_msg(char *msg, int pid)
{
	int b;
	int i;

	i = -1;
	while (msg[++i])
	{
		b = 0;
		while (b < 8)
		{
			usleep(50);
			g_pause = 0;
			if ((msg[i] >> b) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					error("Server not found!\n");
			}
			else
				if (kill(pid,SIGUSR1) == -1)
					error("Server not found!\n");
			while (!g_pause)
				;
			b++;
		}
	}
}

int main(int argc, char **argv)
{
	int pid;
	int b;

	if (argc != 3)
		error("Wrong number of arguments.\n");
	pid = ft_atoi(argv[1]);
	signal(SIGUSR2, ft_handler);
	send_msg(argv[2], pid);
	b = 0;
	while (b < 8)
	{
		g_pause = 0;
		usleep(50);
		kill(pid, SIGUSR1);
		while (!g_pause)
			;
		b++;
	}
	return (0);
}