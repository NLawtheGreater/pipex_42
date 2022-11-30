/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:22:32 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 21:40:46 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*1.Find length of hex, counting multiples of 16
**2.Use base 16 method*/
int	hexlen(size_t nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

/*1.calloc with count of hexlen + 1
**	and check allocation
**2.Put /0 in last position
**3.Use modulo 16 to record corresponding character of base 16
**4.Move position and repeat*/
char	*hexconvert(size_t nb, int is_upper)
{
	char	*base;
	char	*base2;
	char	*str;
	int		i;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	i = hexlen(nb) - 1;
	str = ft_calloc(sizeof(char), i + 2);
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (nb == 0)
		str[i] = '0';
	while (nb > 0)
	{
		if (is_upper)
			str[i] = base2[nb % 16];
		else
			str[i] = base[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (str);
}

/*1.use hex convert to convert int to hexadeximal number
**2.If the type is X the hexadecimal number is converted to uppercase*/
char	*conversion_x(unsigned int nb, int is_upper)
{
	char	*hex;

	hex = hexconvert(nb, is_upper);
	if (!hex)
		return (NULL);
	return (hex);
}
