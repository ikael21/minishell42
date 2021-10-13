/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:18:27 by ikael             #+#    #+#             */
/*   Updated: 2021/04/22 21:39:01 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_digit(long num)
{
	size_t	result;

	result = 1;
	if (num / 10 != 0)
		result += len_digit(num / 10);
	return (result);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*pointer;
	size_t	len;
	int		basket;

	num = n;
	len = len_digit(num);
	if (n < 0)
		len++;
	pointer = (char *)malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	pointer[len] = '\0';
	while (len > 0)
	{
		basket = num % 10;
		if (basket < 0)
			basket *= -1;
		pointer[len - 1] = basket + 48;
		num = num / 10;
		len--;
	}
	if (n < 0)
		pointer[0] = '-';
	return (pointer);
}
