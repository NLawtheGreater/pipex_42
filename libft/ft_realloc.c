/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:29:41 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 21:29:44 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdint.h>

/*1.using malloc to allocate memory
**2.check memory allocation, returns NULL if fail
**3.using bzero to make zero*/
void	*ft_realloc(void *ptr, size_t size)
{
	void	*ptr_new;

	if (size == SIZE_MAX)
		return (NULL);
	if (!ptr)
		return (malloc(size));
	ptr_new = malloc(size);
	if (ptr_new == NULL)
		return (NULL);
	size = ft_strlen(ptr);
	ft_memcpy(ptr_new, ptr, size);
	free(ptr);
	return (ptr_new);
}
