/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:43:28 by ikael             #+#    #+#             */
/*   Updated: 2021/09/19 15:43:28 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	pointer = (char *)malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (i < len - ft_strlen(s2))
	{
		pointer[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		pointer[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
