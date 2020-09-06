# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnarazak <mnarazak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 07:43:58 by mnarazak          #+#    #+#              #
#    Updated: 2020/07/21 16:55:01 by mnarazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CFLAGS := -Wall -Wextra -Werror
CC := gcc
AR := ar rc
SRCS :=	Libc/ft_atoi.c \
	Libc/ft_bzero.c \
	Libc/ft_calloc.c \
	Libc/ft_isalnum.c \
	Libc/ft_isalpha.c \
	Libc/ft_isascii.c \
	Libc/ft_isdigit.c \
	Libc/ft_isprint.c \
	Libc/ft_memccpy.c \
	Libc/ft_memchr.c \
	Libc/ft_memcmp.c \
	Libc/ft_memcpy.c \
	Libc/ft_memmove.c \
	Libc/ft_memset.c \
	Libc/ft_strchr.c \
	Libc/ft_strdup.c \
	Libc/ft_strlcat.c \
	Libc/ft_strlcpy.c \
	Libc/ft_strlen.c \
	Libc/ft_strncmp.c \
	Libc/ft_strnstr.c \
	Libc/ft_strrchr.c \
	Libc/ft_tolower.c \
	Libc/ft_toupper.c \
	Additional/ft_itoa.c \
	Additional/ft_putchar_fd.c \
	Additional/ft_putendl_fd.c \
	Additional/ft_putnbr_fd.c \
	Additional/ft_putstr_fd.c \
	Additional/ft_strjoin.c \
	Additional/ft_substr.c \
	Additional/ft_strtrim.c \
	Additional/ft_strmapi.c \
	Additional/ft_split.c 
OBJS := $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
