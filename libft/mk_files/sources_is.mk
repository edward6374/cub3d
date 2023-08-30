# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_is.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 11:21:14 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_IS		=	srcs/is/ft_isalnum.c
SRCS_IS		+=	srcs/is/ft_isalpha.c
SRCS_IS		+=	srcs/is/ft_isascii.c
SRCS_IS		+=	srcs/is/ft_isdigit.c
SRCS_IS		+=	srcs/is/ft_isprint.c

OBJS_IS		=	$(patsubst $(SRCS_DIR_IS)/%, $(OBJS_DIR_IS)/%, $(SRCS_IS:.c=.o))
DEPS_IS		=	$(patsubst $(SRCS_DIR_IS)/%, $(DEPS_DIR_IS)/%, $(SRCS_IS:.c=.d))
