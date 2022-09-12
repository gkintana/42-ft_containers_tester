# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/09/13 00:09:39 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR		=	include
CONT_DIR1	=	../42-ft_containers/include/containers
CONT_DIR2	=	../42-ft_containers/include/utilities

SRC_DIR		=	sources
VEC_DIR1	=	vector_tests
VEC_DIR2	=	vector_performance
OBJ_DIR		=	objects
FT_DIR		=	ft_performance
STD_DIR		=	std_performance

NS_FT		=	-DNAMESPACE=ft
NS_STD		=	-DNAMESPACE=std

VEC_TEST	=	vector_01_construction.cpp \
				vector_02_element_access.cpp \
				vector_03_iterators.cpp \
				vector_04_capacity.cpp \
				vector_05_modifiers.cpp \
				vector_06_non_member.cpp \
				vector_07_mix.cpp
VEC_OBJ	=	$(addprefix $(OBJ_DIR)/$(VEC_DIR1)/, $(VEC_TEST:%cpp=%o))

VEC_TIME	=	vector_01_construction.cpp
FT_OBJ		=	$(addprefix $(OBJ_DIR)/$(FT_DIR)/, $(VEC_TIME:%cpp=%o))
STD_OBJ		=	$(addprefix $(OBJ_DIR)/$(STD_DIR)/, $(VEC_TIME:%cpp=%o))

CXX			=	c++
CPPFLAGS1	=	-std=c++98 -g3 -Wall -Wextra -Werror
CPPFLAGS2	=	-std=c++11 -g3 -Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
CYAN		=	"\033[3;36m"
PURPLE		=	"\033[0;35m"

# Vector Tests
$(OBJ_DIR)/$(VEC_DIR1)/%.o : $(SRC_DIR)/$(VEC_DIR1)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(VEC_DIR1)
			@echo $(YELLOW)"Compiling..."$(DEFAULT)
			@$(CXX) $(CPPFLAGS1) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
			@printf "\033[A\033[2K\r"

# Vector Performance, ft Namespace
$(OBJ_DIR)/$(FT_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR2)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(FT_DIR)
			@echo $(YELLOW)"Compiling..."$(DEFAULT)
			@$(CXX) $(CPPFLAGS2) $(NS_FT) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
			@printf "\033[A\033[2K\r"
# Vector Performance, std Namespace
$(OBJ_DIR)/$(STD_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR2)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(STD_DIR)
			@echo $(YELLOW)"Compiling..."$(DEFAULT)
			@$(CXX) $(CPPFLAGS2) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
			@printf "\033[A\033[2K\r"


vector:		$(VEC_OBJ) $(FT_OBJ) $(STD_OBJ)
			@echo $(DEFAULT)$(GREEN)"Test Files Ready"$(DEFAULT)

clean:
			@$(RM) $(OBJ_DIR)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
