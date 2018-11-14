#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 18:06:04 by pihouvie          #+#    #+#              #
#    Updated: 2018/01/22 18:31:18 by pihouvie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a

SRCS	=	ft_atoi.c       ft_memcmp.c     ft_putstr.c     ft_striteri.c  \
			ft_strnstr.c	ft_bzero.c      ft_memcpy.c     ft_putstr_fd.c  \
			ft_strjoin.c    ft_strrchr.c	ft_isalnum.c    ft_memdel.c     \
			ft_strcat.c     ft_strlcat.c    ft_strsplit.c	ft_isalpha.c   \
			ft_memmove.c    ft_strchr.c     ft_strlen.c     ft_strstr.c		\
			ft_isascii.c    ft_memset.c     ft_strclr.c     ft_strmap.c     \
			ft_strsub.c		ft_isdigit.c    ft_putchar.c    ft_strcmp.c     \
			ft_strmapi.c    ft_strtrim.c	ft_isprint.c    ft_putchar_fd.c \
			ft_strcpy.c     ft_strncat.c    ft_tolower.c	ft_itoa.c       \
			ft_putendl.c    ft_strdel.c     ft_strncmp.c    ft_toupper.c	\
			ft_memalloc.c   ft_putendl_fd.c ft_strdup.c     ft_strncpy.c	\
			ft_memccpy.c    ft_putnbr.c     ft_strequ.c     ft_strnequ.c	\
			ft_memchr.c     ft_putnbr_fd.c  ft_striter.c    ft_strnew.c		\
			ft_strtrim.c	ft_swap.c		ft_strrevaloc.c	ft_ismin.c		\
			ft_ismaj.c		ft_strcapital.c	ft_foreach.c	ft_strndup.c	\
			ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_strrev.c		\
			ft_lstadd.c		ft_lstiter.c	ft_lstmap.c		ft_lstlen.c		\
			ft_printlst.c	ft_strlowcase.c	ft_strupcase.c					\
			ft_print_words_tables.c	ft_splitcharset.c	ft_convert_base.c	\
			ft_freedoubletab.c	get_next_line.c	ft_absolute.c	ft_exit.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
