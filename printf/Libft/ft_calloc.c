/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:51:31 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/07 13:25:17 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	totalsize;

	totalsize = nmemb * size;
	if (nmemb != 0 && size != 0 && (totalsize / nmemb) != size)
		return (NULL);
	pointer = malloc(totalsize);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, totalsize);
	return (pointer);
}
