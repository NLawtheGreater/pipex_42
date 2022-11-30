/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:59:38 by niclaw            #+#    #+#             */
/*   Updated: 2022/09/24 13:59:53 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>


typedef struct s_stack
{
    int 			data;
    struct s_stack* next;
}					t_stack;

void	lst_check(t_stack **lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int data);
int	check_dup(t_stack **a);
void	ft_lstclear(t_stack **lst);
void	ft_lstdelfront(t_stack **lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	*ft_realloc(void *ptr, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(char c);
int		ft_isprint(int c);
size_t	ft_strlen(char const *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);
int		ft_atoi(char *str, t_stack **a);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		dot;
	int		width;
	int		pcs;
	char	type;
}			t_format;

# define F_TYPE "cspdiuxX%"

int		ft_printf(const char *str, ...);
void	reset_format(t_format *f);
int		set_format1(char c, t_format *f);
char	*set_format2(char *format, char c, int i);
char	*conversion_type(va_list ptr, t_format *f);
char	*conversion_c(char c);
char	*conversion_s(char *s);
char	*conversion_p(size_t ptr);
char	*conversion_d(int d);
char	*conversion_u(unsigned int d);
char	*conversion_x(unsigned int nb, int is_upper);
char	*hexconvert(size_t nb, int is_upper);
int		hexlen(size_t nb);

#endif
