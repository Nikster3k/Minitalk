/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:27:38 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/16 16:31:07 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_cnt(long n, int fd)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		count += ft_putnbr_cnt(n, fd);
		return (count + 1);
	}
	else if (n > 9)
		count += ft_putnbr_cnt(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (count + 1);
}
