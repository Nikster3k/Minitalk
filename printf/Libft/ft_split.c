/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:43:44 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/12 15:03:45 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_next_seperator(char const *str, char c)
{
	while (*str && !(*str == c))
		str++;
	return ((char *)str);
}

static int	ft_count_strings(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != c && *str)
				str++;
		}
		else
		{
			while (*str == c && *str)
				str++;
		}
	}
	return (count);
}

static char	**ft_fill_strings(char **out, char const *s, char c, size_t count)
{
	int		i;
	char	*next;

	i = 0;
	while (count--)
	{
		next = find_next_seperator(s, c);
		out[i] = ft_substr(s, 0, next - s);
		if (out[i] == NULL)
		{
			while (i > 0)
			{
				free(out[--i]);
			}
			free(out);
			return (NULL);
		}
		s = next;
		while (*s == c)
			s++;
		i++;
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**out;

	count = ft_count_strings(s, c);
	out = ft_calloc(sizeof(char *), count + 1);
	if (out == NULL)
		return (NULL);
	out[count] = NULL;
	while (*s == c)
		s++;
	out = ft_fill_strings(out, s, c, count);
	return (out);
}
