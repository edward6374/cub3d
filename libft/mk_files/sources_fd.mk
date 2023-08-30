# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_fd.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 18:16:33 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FD		=	srcs/fd/ft_putnbr_fd.c
SRCS_FD		+=	srcs/fd/ft_putstr_fd.c
SRCS_FD		+=	srcs/fd/ft_putchar_fd.c
SRCS_FD		+=	srcs/fd/ft_putendl_fd.c
SRCS_FD		+=	srcs/fd/ft_putstr_error.c

OBJS_FD		=	$(patsubst $(SRCS_DIR_FD)/%, $(OBJS_DIR_FD)/%, $(SRCS_FD:.c=.o))
DEPS_FD		=	$(patsubst $(SRCS_DIR_FD)/%, $(DEPS_DIR_FD)/%, $(SRCS_FD:.c=.d))
