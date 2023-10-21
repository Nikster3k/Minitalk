/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:29 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/21 16:07:54 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "printf/ft_printf.h"

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned int	character = 0;
	static int			count = 0;

	if (count < 32)
	{
		character <<= 1;
		if (signum == SIGUSR1)
			character |= 1;
		if (signum == SIGUSR2)
			;
		count++;
	}
	if (count == 32)
	{
		if (character == 0)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_printf("%c", character);
		count = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	pid = getpid();
	ft_printf("Pid: %i\n", pid);
	while (1)
		;
}
