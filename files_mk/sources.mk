# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:10:18 by vduchi            #+#    #+#              #
#    Updated: 2023/07/03 18:10:18 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/main.c
OBJS		=	$(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.c=.o))
DEPS		=	$(patsubst $(SRCS_DIR)/%, $(DEPS_DIR)/%, $(SRCS:.c=.d))
