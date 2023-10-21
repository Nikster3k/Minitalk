/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:12:19 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/08 13:36:24 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	char_dest = dest;
	char_src = src;
	if (char_src < char_dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			*char_dest++ = *char_src++;
	}
	return (dest);
}
