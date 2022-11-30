/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:22:15 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 21:22:17 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*1.Check recorded type in f->type 
**2.if 'c' use conversion_c
**3.if 's' use conversion_s
**4.if 'i' use conversion_i
**5. and so on and so forth
**7. Also check if no type matches, if so memallocate size 1 char
**	(if fail, return NULL)*/
char	*conversion_type(va_list ptr, t_format *f)
{
	char	*str;

	if (f->type == 'c')
		str = conversion_c(va_arg(ptr, int));
	else if (f->type == 's')
		str = conversion_s(va_arg(ptr, char *));
	else if (f->type == 'p')
		str = conversion_p((unsigned long long) va_arg(ptr, void *));
	else if (f->type == 'i' || f->type == 'd')
		str = conversion_d(va_arg(ptr, int));
	else if (f->type == 'u')
		str = conversion_u(va_arg(ptr, int));
	else if (f->type == 'x')
		str = conversion_x(va_arg(ptr, unsigned int), 0);
	else if (f->type == 'X')
		str = conversion_x(va_arg(ptr, unsigned int), 1);
	else if (f->type == '%')
		str = conversion_c('%');
	else
		str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	return (str);
}
