# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/09/12 22:49:38 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME		=	containers

INC_DIR		=	include
CONT_DIR1	=	../42-ft_containers/include/containers
CONT_DIR2	=	../42-ft_containers/include/utilities

SRC_DIR		=	sources
VEC_DIR		=	vector_tests
OBJ_DIR		=	objects

VEC_SRC		=	vector_01_construction.cpp \
				vector_02_element_access.cpp \
				vector_03_iterators.cpp \
				vector_04_capacity.cpp \
				vector_05_modifiers.cpp \
				vector_06_non_member.cpp \
				vector_07_mix.cpp
VEC_OBJ		=	$(addprefix $(OBJ_DIR)/$(VEC_DIR)/, $(VEC_SRC:%cpp=%o))

TIME_DIR	=	vector_performance
VEC_TIME	=	vector_01_construction.cpp
TIME_OBJ	=	$(addprefix $(OBJ_DIR)/$(TIME_DIR)/, $(VEC_TIME:%cpp=%o))

CXX			=	c++
CPPFLAGS	=	-std=c++98 -g3 -Wall -Wextra -Werror
CPPFLAGS2	=	-std=c++11 -g3 -Wall -Wextra -Werror -DNAMESPACE=std
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
CYAN		=	"\033[3;36m"
PURPLE		=	"\033[0;35m"

$(OBJ_DIR)/$(VEC_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(VEC_DIR)
			@echo $(YELLOW)"Compiling..."$(DEFAULT)
			@$(CXX) $(CPPFLAGS) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
			@printf "\033[A\033[2K\r"

$(OBJ_DIR)/$(TIME_DIR)/%.o : $(SRC_DIR)/$(TIME_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(TIME_DIR)
			@echo $(YELLOW)"Compiling..."$(DEFAULT)
			@$(CXX) $(CPPFLAGS2) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
			@printf "\033[A\033[2K\r"

# all:		$(NAME)

vector:		$(VEC_OBJ) $(TIME_OBJ)
			@echo $(DEFAULT)$(GREEN)"Test Files Ready"$(DEFAULT)

clean:
			@$(RM) $(OBJ_DIR)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
