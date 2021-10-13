/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:28:24 by ikael             #+#    #+#             */
/*   Updated: 2021/04/23 15:15:39 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			num++;
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			if (num == 1)
				return ((char *)s + i);
			num--;
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
