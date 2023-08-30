# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_to.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 18:18:07 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_TO		=	srcs/to/ft_atoi.c
SRCS_TO		=	srcs/to/ft_atol.c
SRCS_TO		+=	srcs/to/ft_itoa.c
SRCS_TO		+=	srcs/to/ft_tolower.c
SRCS_TO		+=	srcs/to/ft_toupper.c

OBJS_TO		=	$(patsubst $(SRCS_DIR_TO)/%, $(OBJS_DIR_TO)/%, $(SRCS_TO:.c=.o))
DEPS_TO		=	$(patsubst $(SRCS_DIR_TO)/%, $(DEPS_DIR_TO)/%, $(SRCS_TO:.c=.d))
