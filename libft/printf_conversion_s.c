/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:22:03 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 21:22:05 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*1.check if string has anything, if yes then allocate strlen character+1
**	if not allocate 7 (*check*).  Check for allocation result.
**2.If there is string copy string to *str to return.
**3.If there is no string copy NULL for 6 locations (*check*)
**4. return *str */
char	*conversion_s(char *s)
{
	char	*str;

	if (!s)
		str = ft_calloc(sizeof(char), 6 + 1);
	else
		str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	if (!s)
		str = ft_memcpy(str, "(null)", 6);
	else
		str = ft_memcpy(str, s, ft_strlen(s));
	return (str);
}
