/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:37:43 by ikael             #+#    #+#             */
/*   Updated: 2021/09/19 15:37:43 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		result;
	long	num;

	num = n;
	result = 0;
	if (num / 10 != 0)
		ft_putnbr_fd(num / 10, fd);
	if (num < 0)
	{
		num *= -1;
		if (num / 10 == 0)
			write(fd, "-", 1);
	}
	result = num % 10 + 48;
	write(fd, &result, 1);
}
