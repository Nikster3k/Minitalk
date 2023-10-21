/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:02 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/21 17:01:10 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "printf/ft_printf.h"

int	g_success = 0;

int	ft_send_char(int c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		g_success = 0;
		if (c & 4294967296)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_success != 1)
			pause();
		c <<= 1;
		i++;
	}
	return (0);
}

void	ft_send_string(char *str, pid_t pid)
{
	while (*str)
	{
		ft_send_char(*str, pid);
		str++;
	}
	ft_send_char(*str, pid);
}

void	ft_sig_handler(int num)
{
	if (num == SIGUSR1)
		g_success = 1;
	if (num == SIGUSR2)
		ft_printf("Successfully sent string!\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				servpid;

	sa.sa_flags = 0;
	sa.sa_handler = ft_sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	if (argc != 3)
		return (1);
	servpid = ft_atoi(argv[1]);
	ft_send_string(argv[2], servpid);
}
