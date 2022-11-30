/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:24:55 by niclaw            #+#    #+#             */
/*   Updated: 2022/09/30 13:24:56 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
**Synopsis:
    Returns the last node of the list.
*/
#include "libft.h"

/*1.creating ptr to node given
**2.Travel through node with node linker
**3.ptr->next = NUll for the last node, stop before ptr-> = NULL
	for address of last node.
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
