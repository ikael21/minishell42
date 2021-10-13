/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:19:31 by ikael             #+#    #+#             */
/*   Updated: 2021/04/24 18:46:24 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	segment_length(char const *s, char end)
{
	size_t	len;

	len = 0;
	while (s[len] != end && s[len] != '\0')
		len++;
	return (len);
}

static size_t	how_many_strings(char const *s, char c)
{
	size_t	num;

	num = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			num++;
			s += segment_length(s, c) - 1;
		}
		s++;
	}
	return (num);
}

static char	**in_case_of_fail(char **ptr, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**pointer;
	size_t	num_str;
	size_t	i;

	num_str = how_many_strings(s, c);
	pointer = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (pointer == NULL)
		return (NULL);
	pointer[num_str] = NULL;
	i = 0;
	while (i < num_str)
	{
		if (*s == c)
			s++;
		if (*s != c)
		{
			pointer[i] = ft_substr(s, 0, segment_length(s, c));
			if (pointer[i] == NULL)
				return (in_case_of_fail(pointer, i));
			s += segment_length(s, c);
			i++;
		}
	}
	return (pointer);
}
