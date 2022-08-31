# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/08/31 22:49:31 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	containers

INC_DIR		=	include
CONT_DIR1	=	../42-ft_containers/include/containers
CONT_DIR2	=	../42-ft_containers/include/utilities
SRC_DIR		=	sources
OBJ_DIR		=	objects

SRCS		=	vector_construction.cpp
OBJS_FT		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%cpp=%o))

CXX			=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[3;36m"
PURPLE		=	"\033[0;35m"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@printf $(CYAN)
			@printf "\033[A\033[2K\r"
			$(CXX) $(CPPFLAGS) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS_FT)
# @$(CXX) $(CPPFLAGS) $(OBJ_DIR)/$(OBJ_FT)/main.o -o $@
			@echo $(DEFAULT)$(GREEN)"ft_containers Ready"$(DEFAULT)

clean:
			@$(RM) $(OBJ_DIR)
# @echo $(RED)"Deleted object files"$(DEFAULT)

fclean:		clean
# @$(RM) $(FT) $(STD)
# @echo $(RED)"Deleted executable file"$(DEFAULT)

re:			fclean all

.PHONY:		all clean fclean re
