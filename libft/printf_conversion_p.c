/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:21:23 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 21:39:53 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*1.allocate prtr size of 3 to place '0''x'
**2.Hex convert size_t casted pointer address and place in hex string
**3.return NULL if allocation fails
**4.Join 2 strings with strjoin into pstr (function allocates)
**5.free prestring and hes
**6.Return pstr*/
char	*conversion_p(size_t ptr)
{
	char	*hex;
	char	*prestr;
	char	*pstr;

	prestr = ft_calloc(sizeof(char), 3);
	if (!prestr)
		return (NULL);
	prestr[0] = '0';
	prestr[1] = 'x';
	hex = hexconvert(ptr, 0);
	if (!hex)
		return (NULL);
	pstr = ft_strjoin(prestr, hex);
	free(prestr);
	if (hex)
		free(hex);
	if (!pstr)
		return (NULL);
	return (pstr);
}
