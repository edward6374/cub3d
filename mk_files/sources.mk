# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:10:18 by vduchi            #+#    #+#              #
#    Updated: 2023/08/28 08:17:00 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_GEN		=	srcs/general/main.c

SRCS_WND		+=	srcs/window/hooks.c
SRCS_WND		+=	srcs/window/window.c

OBJS_GEN		=	$(patsubst $(SRCS_DIR_GEN)/%, $(OBJS_DIR_GEN)/%, $(SRCS_GEN:.c=.o))
DEPS_GEN		=	$(patsubst $(SRCS_DIR_GEN)/%, $(DEPS_DIR_GEN)/%, $(SRCS_GEN:.c=.d))
OBJS_WND		=	$(patsubst $(SRCS_DIR_WND)/%, $(OBJS_DIR_WND)/%, $(SRCS_WND:.c=.o))
DEPS_WND		=	$(patsubst $(SRCS_DIR_WND)/%, $(DEPS_DIR_WND)/%, $(SRCS_WND:.c=.d))