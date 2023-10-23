/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:02 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/23 20:29:03 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "printf/ft_printf.h"

int	g_success = 0;

int	ft_send_char(char c, pid_t pid)
{
	int	timeout;
	int	i;

	i = 0;
	timeout = 1;
	while (i < 8)
	{
		g_success = 0;
		if (c & 128)
		{
			if (kill(pid, SIGUSR1))
				return (1);
		}
		else
			if (kill(pid, SIGUSR2))
				return (1);
		while (g_success != 1 && timeout < 30)
			pause();
		c <<= 1;
		i++;
	}
	return (0);
}

int	ft_send_string(char *str, pid_t pid)
{
	while (*str)
	{
		if (ft_send_char(*str, pid))
			return (1);
		str++;
	}
	return (ft_send_char(*str, pid));
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
	return (ft_send_string(argv[2], servpid));
}
