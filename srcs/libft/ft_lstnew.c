/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:46:52 by ikael             #+#    #+#             */
/*   Updated: 2021/04/22 18:52:29 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pointer;

	pointer = (t_list *)malloc(sizeof(t_list));
	if (pointer == NULL)
		return (NULL);
	pointer->content = content;
	pointer->next = NULL;
	return (pointer);
}
