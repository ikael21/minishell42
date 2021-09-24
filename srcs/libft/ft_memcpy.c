/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:35:45 by ikael             #+#    #+#             */
/*   Updated: 2021/09/19 15:35:45 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
