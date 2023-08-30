# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 17:13:31 by vduchi            #+#    #+#              #
#    Updated: 2023/08/29 18:41:59 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

-include mk_files/directories.mk

-include mk_files/sources_fd.mk
-include mk_files/sources_is.mk
-include mk_files/sources_to.mk
-include mk_files/sources_gnl.mk
-include mk_files/sources_lst.mk
-include mk_files/sources_mem.mk
-include mk_files/sources_mlc.mk
-include mk_files/sources_str.mk
-include mk_files/sources_dptr.mk
-include mk_files/sources_printf.mk

#=-=-=-=-=-=-=- COLORS DEFINITION =-=-=-=-=-=-=-=-=-#

DEL_LINE		=	\033[2K
ITALIC			=	\033[3m
BOLD			=	\033[1m
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

NAME = libft.a

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

CFLAGS			=	-Wall -Wextra -Werror -g -O3 $(addprefix -I , $(INCS_DIR))
DFLAGS_FD		=	-MMD -MP -MF $(DEPS_DIR_FD)/$*.d
DFLAGS_IS		=	-MMD -MP -MF $(DEPS_DIR_IS)/$*.d
DFLAGS_TO		=	-MMD -MP -MF $(DEPS_DIR_TO)/$*.d
DFLAGS_GNL		=	-MMD -MP -MF $(DEPS_DIR_GNL)/$*.d
DFLAGS_LST		=	-MMD -MP -MF $(DEPS_DIR_LST)/$*.d
DFLAGS_MEM		=	-MMD -MP -MF $(DEPS_DIR_MEM)/$*.d
DFLAGS_MLC		=	-MMD -MP -MF $(DEPS_DIR_MLC)/$*.d
DFLAGS_STR		=	-MMD -MP -MF $(DEPS_DIR_STR)/$*.d
DFLAGS_DPTR		=	-MMD -MP -MF $(DEPS_DIR_DPTR)/$*.d
DFLAGS_PRINTF	=	-MMD -MP -MF $(DEPS_DIR_PRINTF)/$*.d

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

RM		=	rm -rf
MAKE	=	make --no-print-directory
MKDIR	=	mkdir -p

$(OBJS_DIR_FD)/%.o		:	$(SRCS_DIR_FD)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_FD) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_FD)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_IS)/%.o		:	$(SRCS_DIR_IS)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_IS) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_IS)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_TO)/%.o		:	$(SRCS_DIR_TO)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_TO) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_TO)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_GNL)/%.o		:	$(SRCS_DIR_GNL)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_GNL) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_GNL)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_LST)/%.o		:	$(SRCS_DIR_LST)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_LST) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_LST)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_MEM)/%.o		:	$(SRCS_DIR_MEM)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_MEM) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_MEM)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_MLC)/%.o		:	$(SRCS_DIR_MLC)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_MLC) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_MLC)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_STR)/%.o		:	$(SRCS_DIR_STR)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_STR) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_STR)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_DPTR)/%.o	:	$(SRCS_DIR_DPTR)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_DPTR) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_DPTR)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

$(OBJS_DIR_PRINTF)/%.o	:	$(SRCS_DIR_PRINTF)/%.c
	@$(CC) -c $< $(CFLAGS) $(DFLAGS_PRINTF) -o $@
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR_PRINTF)/%,%, $<)   \tcompiled!$(DEF_COLOR)"

ALL_OBJS	=	$(OBJS_FD) $(OBJS_IS) $(OBJS_TO) $(OBJS_GNL) $(OBJS_LST) $(OBJS_MEM) $(OBJS_MLC) $(OBJS_STR) $(OBJS_DPTR) $(OBJS_PRINTF)

all			:	directories $(NAME)

$(NAME)		::
	@echo "$(MAGENTA)\nChecking libft...$(DEF_COLOR)"

$(NAME)		::	$(ALL_OBJS)
	@ar -rsc $@ $^
	@echo "$(ORANGE)Creating Libft library!$(DEF_COLOR)"

$(NAME)		::
	@echo "$(GREEN)Libft library ready!$(DEF_COLOR)"

directories	:
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(DEPS_DIR)
	@$(MKDIR) $(OBJS_DIR_FD)
	@$(MKDIR) $(DEPS_DIR_FD)
	@$(MKDIR) $(OBJS_DIR_IS)
	@$(MKDIR) $(DEPS_DIR_IS)
	@$(MKDIR) $(OBJS_DIR_TO)
	@$(MKDIR) $(DEPS_DIR_TO)
	@$(MKDIR) $(OBJS_DIR_GNL)
	@$(MKDIR) $(DEPS_DIR_GNL)
	@$(MKDIR) $(OBJS_DIR_LST)
	@$(MKDIR) $(DEPS_DIR_LST)
	@$(MKDIR) $(OBJS_DIR_MEM)
	@$(MKDIR) $(DEPS_DIR_MEM)
	@$(MKDIR) $(OBJS_DIR_MLC)
	@$(MKDIR) $(DEPS_DIR_MLC)
	@$(MKDIR) $(OBJS_DIR_STR)
	@$(MKDIR) $(DEPS_DIR_STR)
	@$(MKDIR) $(OBJS_DIR_DPTR)
	@$(MKDIR) $(DEPS_DIR_DPTR)
	@$(MKDIR) $(OBJS_DIR_PRINTF)
	@$(MKDIR) $(DEPS_DIR_PRINTF)

clean		:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(DEPS_DIR)

fclean		:	clean
	@rm -f $(NAME)
	@echo "$(BLUE)Libft cleaned!$(DEF_COLOR)"

re			:	fclean all

-include $(DEPS_FD)
-include $(DEPS_IS)
-include $(DEPS_TO)
-include $(DEPS_GNL)
-include $(DEPS_LST)
-include $(DEPS_MEM)
-include $(DEPS_MLC)
-include $(DEPS_STR)
-include $(DEPS_PRINTF)

.PHONY:	all clean fclean re

#valgrind:
#	valgrind --leak-check=yes --show-leak-kinds=all "nombre del executable" "nombre de argumentos"
#	valgrind --leak-check=yes --track-origins=yes "nombre del executable" "nombre de argumentos"
#
#	gcc $(CFLAGS) -fsanitize=address -g -O3 -fno-omit-frame-pointer $(LDFLAGS) $(SRCS) -o $@
