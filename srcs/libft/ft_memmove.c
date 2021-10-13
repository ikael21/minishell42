/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:26:10 by ikael             #+#    #+#             */
/*   Updated: 2021/04/19 20:08:20 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (src > dst)
	{
		while (len > 0)
		{
			*destination++ = *source++;
			len--;
		}
		return (dst);
	}
	while (len > 0)
	{
		destination[len - 1] = source[len - 1];
		len--;
	}
	return (dst);
}
