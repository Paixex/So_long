# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 11:36:41 by digil-pa          #+#    #+#              #
#    Updated: 2023/09/20 17:26:52 by digil-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_memset		\
		ft_bzero		\
		ft_memcpy		\
		ft_memmove		\
		ft_memchr		\
		ft_memcmp		\
		ft_strlen		\
		ft_strlcpy		\
		ft_strlcat		\
		ft_strchr		\
		ft_strrchr		\
		ft_substr		\
		ft_putchar_fd	\
		ft_putstr_fd	\
		ft_putendl_fd	\
		ft_putnbr_fd	\
		ft_strnstr		\
		ft_strncmp		\
		ft_atoi			\
		ft_isalpha		\
		ft_isdigit		\
		ft_isalnum		\
		ft_isascii		\
		ft_isprint		\
		ft_toupper		\
		ft_tolower		\
		ft_calloc		\
		ft_strdup		\
		ft_strjoin		\
		ft_strtrim		\
		ft_strmapi		\
		ft_striteri		\
		ft_itoa			\
		ft_split		\
		ft_hexa			\
		ft_pointer		\
		ft_printf		\
		ft_putchar_len	\
		ft_putnbr_len	\
		ft_putstr		\
		ft_unsignednbr	\
		ft_printf		\
		
BONUS = ft_lstnew			\
		ft_lstadd_back		\
		ft_lstadd_front		\
		ft_lstsize			\
		ft_lstlast			\
		ft_lstdelone		\
		ft_lstclear			\
		ft_lstiter			\
		ft_lstmap			\
		
CC =gcc
RM =rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o) $(BONUS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)

bonus:	$(SRC:=.o)	$(BONUS:=.o)
		ar rc $(NAME) $(SRC:=.o)	$(BONUS:=.o)