# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    directories.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:10:09 by vduchi            #+#    #+#              #
#    Updated: 2023/12/22 15:11:49 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========================== LIBRARIES ========================= #
#
LIBS_DIR			=	mlx
LIBS_DIR			+=	libft

# ========================== MANDATORY ========================= #
#
INC_DIR				=	mlx
INC_DIR				+=	incs
INC_DIR				+=	libft/incs
SRCS_DIR			=	srcs
OBJS_DIR			=	.objs
DEPS_DIR			=	.deps
SRCS_DIR_MAP		=	$(SRCS_DIR)/map
OBJS_DIR_MAP		=	$(OBJS_DIR)/map
DEPS_DIR_MAP		=	$(DEPS_DIR)/map
SRCS_DIR_WND		=	$(SRCS_DIR)/window
OBJS_DIR_WND		=	$(OBJS_DIR)/window
DEPS_DIR_WND		=	$(DEPS_DIR)/window
SRCS_DIR_GEN		=	$(SRCS_DIR)/general
OBJS_DIR_GEN		=	$(OBJS_DIR)/general
DEPS_DIR_GEN		=	$(DEPS_DIR)/general
SRCS_DIR_CALCS		=	$(SRCS_DIR)/calcs
OBJS_DIR_CALCS		=	$(OBJS_DIR)/calcs
DEPS_DIR_CALCS		=	$(DEPS_DIR)/calcs
SRCS_DIR_TEXTURES	=	$(SRCS_DIR)/textures
OBJS_DIR_TEXTURES	=	$(OBJS_DIR)/textures
DEPS_DIR_TEXTURES	=	$(DEPS_DIR)/textures

# ========================== BONUS ========================= #

INC_DIR_BNS			=	mlx
INC_DIR_BNS			+=	incs_bonus
INC_DIR_BNS			+=	libft/incs
SRCS_DIR_BNS		=	srcs_bonus
OBJS_DIR_BNS		=	.objs_bonus
DEPS_DIR_BNS		=	.deps_bonus
SRCS_DIR_MAP_BNS	=	$(SRCS_DIR_BNS)/map_bonus
OBJS_DIR_MAP_BNS	=	$(OBJS_DIR_BNS)/map_bonus
DEPS_DIR_MAP_BNS	=	$(DEPS_DIR_BNS)/map_bonus
SRCS_DIR_WND_BNS	=	$(SRCS_DIR_BNS)/window_bonus
OBJS_DIR_WND_BNS	=	$(OBJS_DIR_BNS)/window_bonus
DEPS_DIR_WND_BNS	=	$(DEPS_DIR_BNS)/window_bonus
SRCS_DIR_GEN_BNS	=	$(SRCS_DIR_BNS)/general_bonus
OBJS_DIR_GEN_BNS	=	$(OBJS_DIR_BNS)/general_bonus
DEPS_DIR_GEN_BNS	=	$(DEPS_DIR_BNS)/general_bonus
SRCS_DIR_CALCS_BNS	=	$(SRCS_DIR_BNS)/calcs_bonus
OBJS_DIR_CALCS_BNS	=	$(OBJS_DIR_BNS)/calcs_bonus
DEPS_DIR_CALCS_BNS	=	$(DEPS_DIR_BNS)/calcs_bonus
SRCS_DIR_TEXTURES_BNS	=	$(SRCS_DIR_BNS)/textures_bonus
OBJS_DIR_TEXTURES_BNS	=	$(OBJS_DIR_BNS)/textures_bonus
DEPS_DIR_TEXTURES_BNS	=	$(DEPS_DIR_BNS)/textures_bonus
