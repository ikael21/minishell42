/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:37:07 by ikael             #+#    #+#             */
/*   Updated: 2021/04/18 10:26:30 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	character;

	i = 0;
	str = (unsigned char *)b;
	character = c;
	while (len > 0)
	{
		str[i] = character;
		i++;
		len--;
	}
	return (b);
}
