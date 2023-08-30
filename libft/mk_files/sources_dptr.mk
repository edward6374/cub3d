# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_dptr.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 18:17:09 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DPTR	=	srcs/dptr/ft_len_dptr.c
SRCS_DPTR	+=	srcs/dptr/ft_free_dptr.c
SRCS_DPTR	+=	srcs/dptr/ft_print_dptr.c

OBJS_DPTR	=	$(patsubst $(SRCS_DIR_DPTR)/%, $(OBJS_DIR_DPTR)/%, $(SRCS_DPTR:.c=.o))
DEPS_DPTR	=	$(patsubst $(SRCS_DIR_DPTR)/%, $(DEPS_DIR_DPTR)/%, $(SRCS_DPTR:.c=.d))
