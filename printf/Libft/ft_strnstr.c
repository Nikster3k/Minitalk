/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:20:00 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/06 20:22:00 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pos;
	size_t	i;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big && len)
	{
		if (*big == *little)
		{
			pos = (char *)big;
			i = 0;
			while (*(pos + i) == *(little + i) && len - i)
			{
				i++;
				if (!*(little + i))
					return (pos);
			}
		}
		big++;
		len--;
	}
	return (NULL);
}
