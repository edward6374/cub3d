# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:10:18 by vduchi            #+#    #+#              #
#    Updated: 2023/12/09 17:11:28 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_GEN		=	srcs/general/main.c

SRCS_WND		=	srcs/window/hooks.c
SRCS_WND		+=	srcs/window/utils.c
SRCS_WND		+=	srcs/window/window.c

SRCS_MAP		=	srcs/map/check_file.c
SRCS_MAP		+=	srcs/map/check_params.c
SRCS_MAP		+=	srcs/map/init_map.c
SRCS_MAP		+=	srcs/map/ctrl.c
SRCS_MAP		+=	srcs/map/check_rgb.c

SRCS_CALCS		=	srcs/calcs/rays.c
SRCS_CALCS		+=	srcs/calcs/print.c
SRCS_CALCS		+=	srcs/calcs/utils.c

SRCS_TEXTURES	= srcs/textures/init_img.c
SRCS_TEXTURES	+= srcs/textures/init_colors.c
SRCS_TEXTURES	+= srcs/textures/hex_to_rgb.c
SRCS_TEXTURES	+= srcs/textures/find_char.c

OBJS_GEN		=	$(patsubst $(SRCS_DIR_GEN)/%, $(OBJS_DIR_GEN)/%, $(SRCS_GEN:.c=.o))
DEPS_GEN		=	$(patsubst $(SRCS_DIR_GEN)/%, $(DEPS_DIR_GEN)/%, $(SRCS_GEN:.c=.d))
OBJS_WND		=	$(patsubst $(SRCS_DIR_WND)/%, $(OBJS_DIR_WND)/%, $(SRCS_WND:.c=.o))
DEPS_WND		=	$(patsubst $(SRCS_DIR_WND)/%, $(DEPS_DIR_WND)/%, $(SRCS_WND:.c=.d))
OBJS_MAP		=	$(patsubst $(SRCS_DIR_MAP)/%, $(OBJS_DIR_MAP)/%, $(SRCS_MAP:.c=.o))
DEPS_MAP		=	$(patsubst $(SRCS_DIR_MAP)/%, $(DEPS_DIR_MAP)/%, $(SRCS_MAP:.c=.d))
OBJS_CALCS		=	$(patsubst $(SRCS_DIR_CALCS)/%, $(OBJS_DIR_CALCS)/%, $(SRCS_CALCS:.c=.o))
DEPS_CALCS		=	$(patsubst $(SRCS_DIR_CALCS)/%, $(DEPS_DIR_CALCS)/%, $(SRCS_CALCS:.c=.d))
OBJS_TEXTURES	=	$(patsubst $(SRCS_DIR_TEXTURES)/%, $(OBJS_DIR_TEXTURES)/%, $(SRCS_TEXTURES:.c=.o))
DEPS_TEXTURES	=	$(patsubst $(SRCS_DIR_TEXTURES)/%, $(DEPS_DIR_TEXTURES)/%, $(SRCS_TEXTURES:.c=.d))
