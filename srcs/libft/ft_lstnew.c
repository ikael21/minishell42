/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:33:07 by ikael             #+#    #+#             */
/*   Updated: 2021/09/19 15:33:07 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
