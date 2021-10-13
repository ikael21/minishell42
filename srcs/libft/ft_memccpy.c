/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:19:48 by ikael             #+#    #+#             */
/*   Updated: 2021/04/19 21:03:45 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;
	unsigned char	chr;

	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	chr = c;
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == chr)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
