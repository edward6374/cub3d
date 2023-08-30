# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_gnl.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 11:21:07 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_GNL	=	srcs/gnl/get_next_line.c
SRCS_GNL	+=	srcs/gnl/get_next_line_utils.c

OBJS_GNL	=	$(patsubst $(SRCS_DIR_GNL)/%, $(OBJS_DIR_GNL)/%, $(SRCS_GNL:.c=.o))
DEPS_GNL	=	$(patsubst $(SRCS_DIR_GNL)/%, $(DEPS_DIR_GNL)/%, $(SRCS_GNL:.c=.d))
