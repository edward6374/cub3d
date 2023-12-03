# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    directories.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:10:09 by vduchi            #+#    #+#              #
#    Updated: 2023/11/28 12:36:20 by nmota-bu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR			=	mlx
INC_DIR			+=	incs
INC_DIR			+=	libft/incs
SRCS_DIR		=	srcs
OBJS_DIR		=	.objs
DEPS_DIR		=	.deps
LIBS_DIR		=	mlx
LIBS_DIR		+=	libft
SRCS_DIR_MAP	=	$(SRCS_DIR)/map
OBJS_DIR_MAP	=	$(OBJS_DIR)/map
DEPS_DIR_MAP	=	$(DEPS_DIR)/map
SRCS_DIR_WND	=	$(SRCS_DIR)/window
OBJS_DIR_WND	=	$(OBJS_DIR)/window
DEPS_DIR_WND	=	$(DEPS_DIR)/window
SRCS_DIR_GEN	=	$(SRCS_DIR)/general
OBJS_DIR_GEN	=	$(OBJS_DIR)/general
DEPS_DIR_GEN	=	$(DEPS_DIR)/general
SRCS_DIR_CALCS	=	$(SRCS_DIR)/calcs
OBJS_DIR_CALCS	=	$(OBJS_DIR)/calcs
DEPS_DIR_CALCS	=	$(DEPS_DIR)/calcs
SRCS_DIR_TEXTURES	=	$(SRCS_DIR)/textures
OBJS_DIR_TEXTURES	=	$(OBJS_DIR)/textures
DEPS_DIR_TEXTURES	=	$(DEPS_DIR)/textures
