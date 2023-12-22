# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_bonus.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:10:18 by vduchi            #+#    #+#              #
#    Updated: 2023/12/22 15:23:15 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_GEN_BNS		=	srcs_bonus/general_bonus/main_bonus.c

SRCS_WND_BNS		=	srcs_bonus/window_bonus/hooks_bonus.c
SRCS_WND_BNS		+=	srcs_bonus/window_bonus/utils_bonus.c
SRCS_WND_BNS		+=	srcs_bonus/window_bonus/window_bonus.c

SRCS_MAP_BNS		=	srcs_bonus/map_bonus/ctrl_bonus.c
SRCS_MAP_BNS		+=	srcs_bonus/map_bonus/init_map_bonus.c
SRCS_MAP_BNS		+=	srcs_bonus/map_bonus/check_rgb_bonus.c
SRCS_MAP_BNS		+=	srcs_bonus/map_bonus/check_file_bonus.c
SRCS_MAP_BNS		+=	srcs_bonus/map_bonus/check_params_bonus.c

SRCS_CALCS_BNS		=	srcs_bonus/calcs_bonus/rays_bonus.c
SRCS_CALCS_BNS		+=	srcs_bonus/calcs_bonus/print_bonus.c
SRCS_CALCS_BNS		+=	srcs_bonus/calcs_bonus/utils_bonus.c

SRCS_TEXTURES_BNS	=	srcs_bonus/textures_bonus/init_img_bonus.c
SRCS_TEXTURES_BNS	+=	srcs_bonus/textures_bonus/find_char_bonus.c
SRCS_TEXTURES_BNS	+=	srcs_bonus/textures_bonus/hex_to_rgb_bonus.c
SRCS_TEXTURES_BNS	+=	srcs_bonus/textures_bonus/init_colors_bonus.c

OBJS_GEN_BNS		=	$(patsubst $(SRCS_DIR_GEN_BNS)/%, $(OBJS_DIR_GEN_BNS)/%, $(SRCS_GEN_BNS:.c=.o))
DEPS_GEN_BNS		=	$(patsubst $(SRCS_DIR_GEN_BNS)/%, $(DEPS_DIR_GEN_BNS)/%, $(SRCS_GEN_BNS:.c=.d))
OBJS_WND_BNS		=	$(patsubst $(SRCS_DIR_WND_BNS)/%, $(OBJS_DIR_WND_BNS)/%, $(SRCS_WND_BNS:.c=.o))
DEPS_WND_BNS		=	$(patsubst $(SRCS_DIR_WND_BNS)/%, $(DEPS_DIR_WND_BNS)/%, $(SRCS_WND_BNS:.c=.d))
OBJS_MAP_BNS		=	$(patsubst $(SRCS_DIR_MAP_BNS)/%, $(OBJS_DIR_MAP_BNS)/%, $(SRCS_MAP_BNS:.c=.o))
DEPS_MAP_BNS		=	$(patsubst $(SRCS_DIR_MAP_BNS)/%, $(DEPS_DIR_MAP_BNS)/%, $(SRCS_MAP_BNS:.c=.d))
OBJS_CALCS_BNS		=	$(patsubst $(SRCS_DIR_CALCS_BNS)/%, $(OBJS_DIR_CALCS_BNS)/%, $(SRCS_CALCS_BNS:.c=.o))
DEPS_CALCS_BNS		=	$(patsubst $(SRCS_DIR_CALCS_BNS)/%, $(DEPS_DIR_CALCS_BNS)/%, $(SRCS_CALCS_BNS:.c=.d))
OBJS_TEXTURES_BNS	=	$(patsubst $(SRCS_DIR_TEXTURES_BNS)/%, $(OBJS_DIR_TEXTURES_BNS)/%, $(SRCS_TEXTURES_BNS:.c=.o))
DEPS_TEXTURES_BNS	=	$(patsubst $(SRCS_DIR_TEXTURES_BNS)/%, $(DEPS_DIR_TEXTURES_BNS)/%, $(SRCS_TEXTURES_BNS:.c=.d))
