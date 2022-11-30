/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:24:06 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 22:25:19 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*1.Start from %, give memory allocation to format
**2.Check allocation to *format, if fail return NULL
**3.Reset formatting record in struct through pointer
**4.Go through original string starting from 2nd location
**5.Check for recognized flags and mark with set_format1,
**	If not recognized flags, then break to free and return NULL to reset
**6. reallocate size and record to *format, as more flag is found
**	with set_format2 
**7.Check for type marker for end of flag sequence, If there is a type
**	return pointer of string, if not free and return NULL.*/

static char	*get_format_str(const char *str, t_format *f)
{
	int		i;
	char	*format;

	format = set_format2(NULL, '%', 0);
	if (!format)
		return (NULL);
	i = 1;
	reset_format(f);
	while (str[i])
	{
		if (!set_format1(str[i], f))
		{
			break ;
		}
		format = set_format2(format, str[i], i);
		if (!str)
			return (NULL);
		if (f->type)
			return (format);
		i++;
	}
	free (format);
	return (NULL);
}

static int	print_format(va_list ptr, t_format *f)
{
	char	*converted;
	int		n;

	converted = conversion_type(ptr, f);
	n = ft_strlen(converted);
	if (f->type == 'c')
	{
		write(1, converted, 1);
		free(converted);
		return (1);
	}
	else
		ft_putstr_fd(converted, 1);
	free(converted);
	return (n);
}

/*1.declare va_list
**2.check if str is NULL, return null if yes
**3.va start
**4.go through str, if not % write character
**5.if % get formatting with get_format_str
**6.If format has content, print format with print function
**7. free the memory after printing*/
static void	ft_printf2(const char *str, va_list ptr, t_format *f, int *len)
{
	char		*format;

	while (*str != '\0')
	{
		if (*str == '%')
		{
			format = get_format_str(str, f);
			if (format)
			{
				*len += print_format(ptr, f);
				str += ft_strlen(format);
				free (format);
			}
			else
				str++;
		}
		else
		{
			write(1, str, 1);
			*len += 1;
			str++;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		ptr;
	int			len;
	t_format	form;

	len = 0;
	if (str == NULL)
		return (0);
	va_start(ptr, str);
	ft_printf2(str, ptr, &form, &len);
	va_end(ptr);
	return (len);
}
