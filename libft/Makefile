# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 17:13:31 by vduchi            #+#    #+#              #
#    Updated: 2023/07/03 18:34:21 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEL_LINE	=	\033[2K
ITALIC		=	\033[3m
BOLD		=	\033[1m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
BLACK		=	\033[0;99m
ORANGE		=	\033[38;5;209m
BROWN		=	\033[38;2;184;143;29m
DARK_GRAY	=	\033[38;5;234m
MID_GRAY	=	\033[38;5;245m
DARK_GREEN	=	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

NAME = libft.a

SRCS 		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_atoi.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c

CFLAGS		=	-Wall -Wextra -Werror
DEP_FLAGS	=	-MMD -MP

OBJS		=	$(SRCS:.c=.o)
DEPS		=	$(SRCS:.c=.d)

%.o		:	%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR)/%,%, $<)\tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEP_FLAGS) -c $< -o $@

all		:	$(NAME)

$(NAME)	::
	@echo "$(MAGENTA)\nChecking libft...$(DEF_COLOR)"

$(NAME)	::	$(OBJS)
	@echo "$(ORANGE)Creating libft archive...$(DEF_COLOR)"
	@ar -rsc $@ $(OBJS)

$(NAME)	::
	@echo "$(GREEN)Libft archive ready!$(DEF_COLOR)"

clean	:
	@rm -f $(OBJS)
	@rm -f $(DEPS)

fclean	:	clean
	@rm -f $(NAME)
	@echo "$(BLUE)\nLibft cleaned!$(DEF_COLOR)"

re		:	fclean all

-include $(DEPS)

.PHONY: all clean fclean re
