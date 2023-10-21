/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:21:59 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/08 12:24:12 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_matchesset(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;
	int		strlen;
	int		size;

	strlen = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_matchesset(s1[start], set))
	{
		start++;
	}
	end = strlen;
	while (s1[end - 1] && ft_matchesset(s1[end - 1], set))
	{
		end--;
	}
	size = end - start;
	if (size < 0)
		size = 0;
	new_str = ft_substr(s1, start, size);
	return (new_str);
}
