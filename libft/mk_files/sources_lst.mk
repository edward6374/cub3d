# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources_lst.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 17:59:25 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 11:21:23 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_LST		=	srcs/lst/ft_lstmap_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstnew_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstsize_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstiter_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstlast_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstclear_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstdelone_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstadd_back_bonus.c
SRCS_LST		+=	srcs/lst/ft_lstadd_front_bonus.c

OBJS_LST		=	$(patsubst $(SRCS_DIR_LST)/%, $(OBJS_DIR_LST)/%, $(SRCS_LST:.c=.o))
DEPS_LST		=	$(patsubst $(SRCS_DIR_LST)/%, $(DEPS_DIR_LST)/%, $(SRCS_LST:.c=.d))
