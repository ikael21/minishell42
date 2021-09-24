/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:45:53 by ikael             #+#    #+#             */
/*   Updated: 2021/09/19 15:45:53 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	is_there(char const *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pointer;
	size_t	len;

	while (is_there(set, *s1) == 1)
	{
		s1++;
		if (*s1 == '\0')
		{
			pointer = (char *)malloc(sizeof(char));
			pointer[0] = '\0';
			return (pointer);
		}
	}
	len = ft_strlen(s1);
	while (is_there(set, s1[len - 1]) == 1)
		len--;
	pointer = ft_substr(s1, 0, len);
	if (pointer == NULL)
		return (NULL);
	return (pointer);
}
