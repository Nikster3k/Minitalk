/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:53:32 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/13 11:35:36 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_cnt(char *s)
{
	int	count;

	if (s == NULL)
		return (ft_putstr_cnt("(null)"));
	count = 0;
	while (s[count])
		ft_putchar_fd(s[count++], 1);
	return (count);
}
