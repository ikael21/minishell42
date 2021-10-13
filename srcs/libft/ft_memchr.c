/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:06:00 by ikael             #+#    #+#             */
/*   Updated: 2021/04/20 12:49:17 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	character;

	character = c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str++ == character)
			return (str - 1);
		n--;
	}
	return (NULL);
}
