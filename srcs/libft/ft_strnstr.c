/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:45:34 by ikael             #+#    #+#             */
/*   Updated: 2021/09/19 15:45:34 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == *needle)
		{
			if (len < ft_strlen(needle))
				return (NULL);
			if (ft_memcmp(&haystack[i], needle, len_needle) == 0)
			{
				if (i + len_needle <= len)
					return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
