# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niclaw <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:59:17 by niclaw            #+#    #+#              #
#    Updated: 2022/09/24 13:59:27 by niclaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCLIST	= list_f.c ft_realloc.c\
		ft_tolower.c ft_toupper.c ft_isalpha.c ft_isdigit.c\
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_calloc.c\
		 ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c\
		  ft_memcpy.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strjoin.c ft_substr.c\
		  ft_strtrim.c ft_atoi.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		  ft_split.c ft_strncmp.c ft_strchr.c  ft_putchar_fd.c\
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strdup.c\
		  ft_strlcat.c ft_strlcpy.c ft_strrchr.c ft_strnstr.c\
			printf_format.c ft_printf.c  printf_conversion_x.c printf_conversion_u.c \
			printf_conversion_type.c printf_conversion_s.c printf_conversion_p.c \
			printf_conversion_d.c printf_conversion_c.c
SRCDIR	= 
BONUS_SRC	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstiter_bonus.c ft_lstclear_bonus.c\
			ft_lstmap_bonus.c 
SRCS	= ${addprefix ${SRCDIR}, ${SRCLIST}}

OBJS	= ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRC:.c=.o}
INCH	= libft.h
INCHB	= libft_bonus.h

CC	= gcc

CFLAGS	= -g -Wall -Wextra -Werror

RM	= rm -f

NAME	= libft.a

%.o: %.c ${INCH}
	${CC} ${CFLAGS} -include ${INCH} -c $< -o ${<:.c=.o}

%bonus.o:	%bonus.c ${INCHB}
	${CC} ${CFLAGS} -include ${INCHB} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -crs ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} 

re:	fclean all

.PHONY:	all clean fclean re  

bonus: ${BONUS_OBJS}
	ar -crs ${NAME} ${BONUS_OBJS}