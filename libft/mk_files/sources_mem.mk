# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_mem.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 11:21:38 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MEM	=	srcs/mem/ft_memchr.c
SRCS_MEM	+=	srcs/mem/ft_memcmp.c
SRCS_MEM	+=	srcs/mem/ft_memcpy.c
SRCS_MEM	+=	srcs/mem/ft_memset.c
SRCS_MEM	+=	srcs/mem/ft_memmove.c

OBJS_MEM	=	$(patsubst $(SRCS_DIR_MEM)/%, $(OBJS_DIR_MEM)/%, $(SRCS_MEM:.c=.o))
DEPS_MEM	=	$(patsubst $(SRCS_DIR_MEM)/%, $(DEPS_DIR_MEM)/%, $(SRCS_MEM:.c=.d))
