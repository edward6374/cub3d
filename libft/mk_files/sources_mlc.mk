# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_malloc.mk                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 11:21:29 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MLC		=	srcs/mlc/ft_bzero.c
SRCS_MLC		+=	srcs/mlc/ft_calloc.c

OBJS_MLC		=	$(patsubst $(SRCS_DIR_MLC)/%, $(OBJS_DIR_MLC)/%, $(SRCS_MLC:.c=.o))
DEPS_MLC		=	$(patsubst $(SRCS_DIR_MLC)/%, $(DEPS_DIR_MLC)/%, $(SRCS_MLC:.c=.d))
