# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:09:13 by vduchi            #+#    #+#              #
#    Updated: 2023/12/22 15:24:03 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

-include mk_files/sources.mk
-include mk_files/sources_bonus.mk
-include mk_files/directories.mk

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
NAME_BNS		=	cub3d_bonus

MLX				=	mlx/libmlx.a
LIBFT			=	libft/libft.a
MLX_PATH		=	mlx
LIBFT_PATH		=	libft

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

LDFLAGS				= 	-L $(MLX_PATH) -L $(LIBFT_PATH)
LDFLAGS				+= 	-lft -lmlx -framework OpenGL -framework AppKit

CFLAGS				+= 	-Wall -Werror -Wextra -g3 -O3 $(addprefix -I , $(INC_DIR)) #-fsanitize=address
DEPFLAGS_GEN		=	-MMD -MP -MF $(DEPS_DIR_GEN)/$*.d
DEPFLAGS_WND		=	-MMD -MP -MF $(DEPS_DIR_WND)/$*.d
DEPFLAGS_MAP		=	-MMD -MP -MF $(DEPS_DIR_MAP)/$*.d
DEPFLAGS_CALCS		=	-MMD -MP -MF $(DEPS_DIR_CALCS)/$*.d

CFLAGS_BNS			+= 	-Wall -Werror -Wextra -g3 -O3 $(addprefix -I , $(INC_DIR_BNS)) #-fsanitize=address
DEPFLAGS_GEN_BNS	=	-MMD -MP -MF $(DEPS_DIR_GEN_BNS)/$*.d
DEPFLAGS_WND_BNS	=	-MMD -MP -MF $(DEPS_DIR_WND_BNS)/$*.d
DEPFLAGS_MAP_BNS	=	-MMD -MP -MF $(DEPS_DIR_MAP_BNS)/$*.d
DEPFLAGS_CALCS_BNS	=	-MMD -MP -MF $(DEPS_DIR_CALCS_BNS)/$*.d

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

CC				=	gcc
RM				=	rm -rf
MKDIR			=	mkdir -p
MAKE			=	make --no-print-directory

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

# ========================== MANDATORY ========================= #

$(OBJS_DIR_GEN)/%.o :	$(SRCS_DIR_GEN)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_GEN)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS_GEN) -c $< -o $@

$(OBJS_DIR_WND)/%.o :	$(SRCS_DIR_WND)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_WND)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS_WND) -c $< -o $@

$(OBJS_DIR_MAP)/%.o :	$(SRCS_DIR_MAP)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_MAP)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS_MAP) -c $< -o $@

$(OBJS_DIR_CALCS)/%.o :	$(SRCS_DIR_CALCS)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_CALCS)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS_CALCS) -c $< -o $@

$(OBJS_DIR_TEXTURES)/%.o :	$(SRCS_DIR_TEXTURES)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_TEXTURES)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS_CALCS) -c $< -o $@

all				:	directories
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(MLX_PATH)
	@$(MAKE) $(NAME)

$(NAME)		::
	@echo "$(MAGENTA)\nChecking cub3d...$(DEF_COLOR)"

$(NAME)		::	$(MLX) $(LIBFT) $(OBJS_GEN) $(OBJS_WND) $(OBJS_MAP) $(OBJS_CALCS) $(OBJS_TEXTURES)
	@echo "$(ORANGE)Compiling cub3d exec...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(NAME)		::
	@echo "$(GREEN)Cub3d executable ready!$(DEF_COLOR)"

directories	:
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(DEPS_DIR)
	@$(MKDIR) $(OBJS_DIR_GEN)
	@$(MKDIR) $(DEPS_DIR_GEN)
	@$(MKDIR) $(OBJS_DIR_WND)
	@$(MKDIR) $(DEPS_DIR_WND)
	@$(MKDIR) $(OBJS_DIR_MAP)
	@$(MKDIR) $(DEPS_DIR_MAP)
	@$(MKDIR) $(OBJS_DIR_CALCS)
	@$(MKDIR) $(DEPS_DIR_CALCS)
	@$(MKDIR) $(OBJS_DIR_TEXTURES)
	@$(MKDIR) $(DEPS_DIR_TEXTURES)

-include $(DEPS_GEN)
-include $(DEPS_WND)
-include $(DEPS_MAP)
-include $(DEPS_CALCS)
-include $(DEPS_TEXTURES)

# ========================== BONUS ========================= #

$(OBJS_DIR_GEN_BNS)/%.o :	$(SRCS_DIR_GEN_BNS)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_GEN_BNS)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS_BNS) $(DEPFLAGS_GEN_BNS) -c $< -o $@

$(OBJS_DIR_WND_BNS)/%.o :	$(SRCS_DIR_WND_BNS)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_WND_BNS)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS_BNS) $(DEPFLAGS_WND_BNS) -c $< -o $@

$(OBJS_DIR_MAP_BNS)/%.o :	$(SRCS_DIR_MAP_BNS)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_MAP_BNS)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS_BNS) $(DEPFLAGS_MAP_BNS) -c $< -o $@

$(OBJS_DIR_CALCS_BNS)/%.o :	$(SRCS_DIR_CALCS_BNS)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_CALCS_BNS)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS_BNS) $(DEPFLAGS_CALCS_BNS) -c $< -o $@

$(OBJS_DIR_TEXTURES_BNS)/%.o :	$(SRCS_DIR_TEXTURES_BNS)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_TEXTURES_BNS)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS_BNS) $(DEPFLAGS_CALCS_BNS) -c $< -o $@

bonus		:	directories_bonus
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(MLX_PATH)
	@$(MAKE) $(NAME_BNS)

$(NAME_BNS)		::
	@echo "$(MAGENTA)\nChecking cub3d bonus...$(DEF_COLOR)"

$(NAME_BNS)		::	$(MLX) $(LIBFT) $(OBJS_GEN_BNS) $(OBJS_WND_BNS) $(OBJS_MAP_BNS) $(OBJS_CALCS_BNS) $(OBJS_TEXTURES_BNS)
	@echo "$(ORANGE)Compiling cub3d bonus exec...$(DEF_COLOR)"
	@$(CC) $(CFLAGS_BNS) $(LDFLAGS) $^ -o $@

$(NAME_BNS)		::
	@echo "$(GREEN)Cub3d bonus executable ready!$(DEF_COLOR)"

directories_bonus	:
	@$(MKDIR) $(OBJS_DIR_BNS)
	@$(MKDIR) $(DEPS_DIR_BNS)
	@$(MKDIR) $(OBJS_DIR_GEN_BNS)
	@$(MKDIR) $(DEPS_DIR_GEN_BNS)
	@$(MKDIR) $(OBJS_DIR_WND_BNS)
	@$(MKDIR) $(DEPS_DIR_WND_BNS)
	@$(MKDIR) $(OBJS_DIR_MAP_BNS)
	@$(MKDIR) $(DEPS_DIR_MAP_BNS)
	@$(MKDIR) $(OBJS_DIR_CALCS_BNS)
	@$(MKDIR) $(DEPS_DIR_CALCS_BNS)
	@$(MKDIR) $(OBJS_DIR_TEXTURES_BNS)
	@$(MKDIR) $(DEPS_DIR_TEXTURES_BNS)

-include $(DEPS_GEN_BNS)
-include $(DEPS_WND_BNS)
-include $(DEPS_MAP_BNS)
-include $(DEPS_CALCS_BNS)
-include $(DEPS_TEXTURES_BNS)

# ========================== LIBRARIES ========================= #

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# ========================== OTHERS ========================= #

clean		:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(DEPS_DIR)
	@$(RM) $(OBJS_DIR_BNS)
	@$(RM) $(DEPS_DIR_BNS)

fclean		:	clean
	@$(RM) $(NAME) $(NAME_BNS)
	@$(MAKE) -C $(MLX_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(BLUE)\nCub3d cleaned!$(DEF_COLOR)"

re			:	fclean all


.PHONY: all clean fclean re bonus

#
#valgrind:
#	valgrind --leak-check=yes --show-leak-kinds=all "nombre del executable" "nombre de argumentos"
#	valgrind --leak-check=yes --track-origins=yes "nombre del executable" "nombre de argumentos"
#
#	gcc $(CFLAGS) -fsanitize=address -g -O3 -fno-omit-frame-pointer $(LDFLAGS) $(SRCS) -o $@
