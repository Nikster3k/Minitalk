/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:29 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/25 17:36:27 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_message = NULL;

static	int	ft_exit_on_fail(int err)
{
	free(g_message);
	exit(err);
}

static	int	ft_add_char(char c)
{
	char	*tempdata;
	size_t	size;
	size_t	i;

	size = 0;
	if (g_message != NULL)
		size = ft_strlen(g_message);
	tempdata = ft_calloc(sizeof(char), size + 2);
	if (tempdata == NULL)
		return (EXIT_FAILURE);
	i = size;
	while (i--)
		tempdata[i] = g_message[i];
	free(g_message);
	g_message = tempdata;
	g_message[size] = c;
	g_message[size + 1] = '\0';
	return (EXIT_SUCCESS);
}

static void	ft_handle_char(siginfo_t *info, char *c, int *count)
{
	if (*c == '\0')
	{
		ft_printf("%s\n", g_message);
		if (kill(info->si_pid, SIGUSR2))
			ft_exit_on_fail(EXIT_FAILURE);
		free(g_message);
		g_message = NULL;
	}
	else
		if (ft_add_char(*c))
			ft_exit_on_fail(EXIT_FAILURE);
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
		ft_handle_char(info, &c, &count);
	if (kill(info->si_pid, SIGUSR1))
		ft_exit_on_fail(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		return (-1);
	if (sigaction(SIGUSR1, &sa, 0))
		return (-1);
	if (sigaction(SIGUSR2, &sa, 0))
		return (-1);
	ft_printf("Pid: %i\n", getpid());
	while (1)
		;
	free(g_message);
	return (EXIT_SUCCESS);
}
