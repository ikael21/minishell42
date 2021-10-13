/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:55:11 by ikael             #+#    #+#             */
/*   Updated: 2021/04/25 19:42:36 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*pointer;
	unsigned int	i;

	pointer = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		pointer[i] = f(i, s[i]);
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
