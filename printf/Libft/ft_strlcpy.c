/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:05:56 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/06 19:44:26 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = ft_strlen(src);
	if (size == 0)
		return (length);
	if (size <= 1)
	{
		*dst = 0;
		return (length);
	}
	while ((size-- - 1) && *src)
	{
		*dst++ = *src++;
	}
	*dst = 0;
	return (length);
}
