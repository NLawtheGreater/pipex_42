/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:22:24 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 21:41:40 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	uilen(unsigned int d);

/*1.allocate memory equal to length of digits + 1
**	and check allocation
**2.assign '\0' to last position
**3.use modulo of 10 to get digit, store as character
**4.move position and repeat til finish
*/
static char	*uits(unsigned int d)
{
	char	*str;
	int		i;

	i = uilen(d) - 1;
	str = (char *) ft_calloc(sizeof(char), i + 2);
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (d == 0)
		str[i] = '0';
	while (d > 0)
	{
		str[i] = (d % 10) + '0';
		d = d / 10;
		i--;
	}
	return (str);
}

/*1.if 0 return 1
**2.if more than 0, find length with decimal base method*/
static int	uilen(unsigned int d)
{
	int		i;

	i = 0;
	if (d == 0)
		return (1);
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

/*1.Use u into s function
**2.Check if allocation fails
***/
char	*conversion_u(unsigned int d)
{
	char	*str;

	str = uits(d);
	if (!str)
		return (NULL);
	return (str);
}
