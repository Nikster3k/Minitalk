/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:29 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/24 20:23:34 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_string	g_message = {NULL, 0, 0};

static	int	ft_exit_on_fail(int err)
{
	free(g_message.data);
	exit(err);
}

static	int	ft_add_char(char c)
{
	char	*tempdata;
	size_t	i;

	if (g_message.capacity == 0)
	{
		g_message.data = ft_calloc(sizeof(char), 20);
		if (g_message.data == NULL)
			return (EXIT_FAILURE);
		g_message.capacity = 20;
	}
	else if (g_message.size >= g_message.capacity)
	{
		tempdata = ft_calloc(sizeof(char), g_message.capacity *= 2);
		if (tempdata == NULL)
			return (EXIT_FAILURE);
		i = 0;
		while (++i <= g_message.size)
			tempdata[i - 1] = g_message.data[i - 1];
		free(g_message.data);
		g_message.data = tempdata;
	}
	g_message.data[g_message.size++] = c;
	return (EXIT_SUCCESS);
}

static void	ft_handle_char(siginfo_t *info, char *c, int *count)
{
	if (ft_add_char(*c))
		ft_exit_on_fail(EXIT_FAILURE);
	if (*c == '\0')
	{
		ft_printf("%s\n", g_message.data);
		if (kill(info->si_pid, SIGUSR2))
			ft_exit_on_fail(EXIT_FAILURE);
	}
	(*count) = 0;
	(*c) = 0;
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	count = 0;
	static char	c = 0;

	if (g_message.data != NULL && g_message.size != 0
		&& g_message.data[g_message.size - 1] == '\0')
	{
		ft_bzero(g_message.data, g_message.capacity);
		g_message.size = 0;
	}
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
	free(g_message.data);
	return (EXIT_SUCCESS);
}
