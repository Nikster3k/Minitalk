/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:29 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/24 13:08:37 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "printf/ft_printf.h"

static void	ft_print_sig(siginfo_t *info, char *c, int *count)
{
	if (*c == 0)
	{
		ft_printf("\n");
		if (kill(info->si_pid, SIGUSR2))
			exit(1);
	}
	else
		ft_printf("%c", *c);
	(*count) = 0;
	(*c) = 0;
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	count = 0;
	static char	c = 0;

	if (count < 8)
	{
		c <<= 1;
		if (signum == SIGUSR1)
			c |= 1;
		if (signum == SIGUSR2)
			;
		count++;
	}
	if (count == 8)
		ft_print_sig(info, &c, &count);
	if (kill(info->si_pid, SIGUSR1))
		exit(1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, 0))
		return (-1);
	if (sigaction(SIGUSR2, &sa, 0))
		return (-1);
	ft_printf("Pid: %i\n", getpid());
	while (1)
		;
}
