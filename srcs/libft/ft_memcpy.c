/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:49:25 by ikael             #+#    #+#             */
/*   Updated: 2021/04/18 10:04:33 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (dst == src)
		return (dst);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n > 0)
	{
		destination[n - 1] = source[n - 1];
		n--;
	}
	return (dst);
}
