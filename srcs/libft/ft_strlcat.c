/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:28:03 by ikael             #+#    #+#             */
/*   Updated: 2021/04/23 15:11:51 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	while (dst[len_dst] != 0 && len_dst < dstsize)
		len_dst++;
	i = 0;
	if (dstsize)
	{
		while (src[i] != 0 && len_dst + i < dstsize - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
	}
	if (len_dst + i < dstsize)
		dst[len_dst + i] = '\0';
	return (ft_strlen(src) + len_dst);
}
