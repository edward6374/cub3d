# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:09:13 by vduchi            #+#    #+#              #
#    Updated: 2023/07/03 19:15:20 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

-include files_mk/sources.mk
-include files_mk/directories.mk

#=-=-=-=-=-=-=- COLORS DEFINITION =-=-=-=-=-=-=-=-=-#

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

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

NAME			=	cub3d

MLX				=	mlx/libmlx.a
LIBFT			=	libft/libft.a
PRINTF			=	ft_printf/libftprintf.a

MLX_PATH		=	mlx
LIBFT_PATH		=	libft
PRINTF_PATH		=	ft_printf

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#a

MLX_PATH		=	mlx
LIBFT_PATH		=	libft


CFLAGS			+= 	-Wall -Werror -Wextra -g -O3 $(addprefix -I , $(INC_DIR)) #-fsanitize=address
LDFLAGS			= 	-L $(MLX_PATH) -L $(LIBFT_PATH) -L $(PRINTF_PATH) -lft -lftprintf #-lmlx -framework OpenGL -framework AppKit
DEPFLAGS		=	-MMD -MP -MF $(DEPS_DIR)/$*.d

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

CC				=	gcc
RM				=	rm -rf
MKDIR			=	mkdir -p
MAKE			=	make --no-print-directory

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

all				:	directories $(LIBFT) $(PRINTF)
	@$(MAKE) $(NAME)

$(NAME)		::
	@echo "$(MAGENTA)\nChecking cub3d...$(DEF_COLOR)"

$(NAME)		::	$(OBJS_DIR) $(DEPS_DIR) $(OBJS)
	@echo "$(ORANGE)Compiling cub3d exec...$(DEF_COLOR)"
	@$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

$(NAME)		::
	@echo "$(GREEN)Cub3d executable ready!$(DEF_COLOR)"

directories	:
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(DEPS_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_PATH)

clean		:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(DEPS_DIR)

fclean		:	clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(MLX_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@echo "$(BLUE)\nCub3d cleaned!$(DEF_COLOR)"

re			:	fclean all

-include $(DEPS)

.PHONY: all clean fclean re

#
#valgrind:
#	valgrind --leak-check=yes --show-leak-kinds=all "nombre del executable" "nombre de argumentos"
#	valgrind --leak-check=yes --track-origins=yes "nombre del executable" "nombre de argumentos"
#
#	gcc $(CFLAGS) -fsanitize=address -g -O3 -fno-omit-frame-pointer $(LDFLAGS) $(SRCS) -o $@
