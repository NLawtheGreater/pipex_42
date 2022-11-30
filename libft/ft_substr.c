/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:19:24 by niclaw            #+#    #+#             */
/*   Updated: 2022/09/02 17:19:25 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Description:
	Allocates (with malloc(3)) and returns a substring
	from the string ’s’.
	The substring begins at index ’start’ and is of
	maximum size ’len’.
*/
#include "libft.h"
#include <stdio.h>

/*  1.allocates with malloc
				2.NULL if allocation fails
				3.copying to pointer using start as the index and 
				stopping by the end of s or maximum len
				4.add NULL to end substring
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	len2;
	size_t	len3;
	char	*ptr;

	if (!s)
		return (NULL);
	len2 = ft_strlen(s);
	if (len2 > start)
		len3 = len2 - start;
	else
		len3 = 0;
	if (len >= len3)
		ptr = malloc((len3 + 1) * sizeof(char));
	else
	{
		ptr = malloc((len + 1) * sizeof(char));
	}
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (j < len && start < len2)
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}
