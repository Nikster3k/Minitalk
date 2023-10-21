/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:44:10 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/13 15:28:49 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_special(char sign, va_list args, int *count)
{
	const char	small_hex[] = "0123456789abcdef";
	const char	big_hex[] = "0123456789ABCDEF";

	if (sign == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
	}
	else if (sign == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	else if (sign == 's')
		*count += ft_putstr_cnt(va_arg(args, char *));
	else if (sign == 'p')
		*count += ft_printptr_cnt((size_t)va_arg(args, void *), small_hex);
	else if (sign == 'd' || sign == 'i')
		*count += ft_putnbr_cnt(va_arg(args, int), 1);
	else if (sign == 'x')
		*count += ft_putnbr_base(va_arg(args, int), small_hex);
	else if (sign == 'X')
		*count += ft_putnbr_base(va_arg(args, int), big_hex);
	else if (sign == 'u')
		*count += ft_putunbr_cnt(va_arg(args, int), 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	if (s == NULL)
		return (-1);
	while (*s)
	{
		if (*s == '%')
			ft_print_special(*++s, args, &count);
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}
