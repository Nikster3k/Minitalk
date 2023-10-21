/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:14:24 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/18 12:33:47 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_has_dupes(char *str, int length)
{
	int	i;
	int	n;

	i = 0;
	while (i < length)
	{
		n = i + 1;
		while (n < length)
		{
			if (str[i] == str[n])
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

static void	ft_putnbr_base_rec(size_t nbr, char *base, size_t len, int *count)
{
	if (nbr >= len)
		ft_putnbr_base_rec(nbr / len, base, len, count);
	ft_putchar_fd(base[nbr % len], 1);
	(*count)++;
}

int	ft_putnbr_base(unsigned int nbr, const char *base)
{
	unsigned int	baselen;
	int				count;

	count = 0;
	baselen = ft_strlen(base);
	if (baselen < 2)
		return (count);
	if (ft_has_dupes((char *)base, baselen))
		return (count);
	ft_putnbr_base_rec(nbr, (char *)base, baselen, &count);
	return (count);
}

int	ft_printptr_cnt(size_t adress, const char *base)
{
	int	count;
	int	baselen;

	if (adress == 0)
		return (ft_putstr_cnt("(nil)"));
	count = 0;
	count += ft_putstr_cnt("0x");
	baselen = ft_strlen(base);
	ft_putnbr_base_rec(adress, (char *)base, baselen, &count);
	return (count);
}
