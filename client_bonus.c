/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:02 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/25 17:36:26 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_success = 0;

int	ft_send_char(char c, pid_t pid)
{
	int	i;

	i = 0;
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
		while (g_success != 1)
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
		ft_printf("String set successfully!\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				servpid;

	sa.sa_flags = 0;
	sa.sa_handler = ft_sig_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		return (-1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	if (argc != 3)
		return (1);
	servpid = ft_atoi(argv[1]);
	return (ft_send_string(argv[2], servpid));
}
