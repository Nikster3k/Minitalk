/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:21:05 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/08 11:53:05 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_base(long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static size_t	ft_calc_size(long *n)
{
	size_t	len;

	len = 0;
	if (*n <= 0)
	{
		*n = -*n;
		len = 1 + ft_count_base(*n);
	}
	else
		len = ft_count_base(*n);
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nstr;
	int		numlen;
	long	temp;

	temp = n;
	numlen = ft_calc_size(&temp);
	nstr = malloc(numlen + 1);
	if (nstr == NULL)
		return (NULL);
	if (n < 0)
		*nstr = '-';
	nstr[numlen] = '\0';
	while (numlen-- && temp > 0)
	{
		nstr[numlen] = (temp % 10) + 48;
		temp /= 10;
	}
	if (n == 0)
		nstr[numlen] = '0';
	return (nstr);
}
