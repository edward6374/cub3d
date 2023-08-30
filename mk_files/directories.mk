# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    directories.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:10:09 by vduchi            #+#    #+#              #
#    Updated: 2023/08/30 14:12:34 by vduchi           ###   ########.fr        #
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
SRCS_DIR_GEN	=	$(SRCS_DIR)/general
SRCS_DIR_WND	=	$(SRCS_DIR)/window
OBJS_DIR_GEN	=	$(OBJS_DIR)/general
OBJS_DIR_WND	=	$(OBJS_DIR)/window
DEPS_DIR_GEN	=	$(DEPS_DIR)/general
DEPS_DIR_WND	=	$(DEPS_DIR)/window
