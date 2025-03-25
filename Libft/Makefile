# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 10:28:19 by erbuffet          #+#    #+#              #
#    Updated: 2025/03/24 22:00:22 by erbuffet         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE
AR = ar
ARFLAGS = rcs
NAME = libft.a

SRC = ft_putnbr_fd.c get_next_line_utils.c  ft_strcpy.c ft_strcmp.c ft_strnstr.c      \
      ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_toupper.c  ft_strncmp.c     \
      ft_isalpha.c ft_isdigit.c ft_isprint.c  ft_itoa.c ft_atoi.c  ft_putendl_fd.c    \
      ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c   ft_putchar_fd.c  \
      ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c get_next_line.c \
      ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_printf.c     \
      ft_strrchr.c ft_strstr.c ft_strtrim.c ft_substr.c ft_tolower.c print_utils.c    \
      ft_atoll.c                                                                      \
            
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re