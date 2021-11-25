/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:11:53 by aregenia          #+#    #+#             */
/*   Updated: 2021/11/25 14:37:28 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void put_char(int b)
{
	static int i = 0;
	static unsigned char c = 0;

	c = c | (b << i);
	i++;
	if (i > 7)
	{
		if (c == '\0')
		{
			write(1, "\n",1);
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void get_pid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		put_char(0);
	else if (sig == SIGUSR2)
		put_char(1);
	kill((*info).si_pid, SIGUSR2);
}

int	main(void)
{
	int	pid;
	struct sigaction	sigact;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = get_pid;
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
