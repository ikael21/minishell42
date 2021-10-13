/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:00:45 by ikael             #+#    #+#             */
/*   Updated: 2021/04/24 17:54:05 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_copy_head;
	t_list	*root;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	root = NULL;
	lst_copy_head = root;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&lst_copy_head, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_copy_head, new);
		lst = lst->next;
	}
	return (lst_copy_head);
}
