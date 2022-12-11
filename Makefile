# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/12/11 11:33:03 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR		=	include
CONT_DIR1	=	../42-ft_containers/include/containers
CONT_DIR2	=	../42-ft_containers/include/utilities
# CONT_DIR1	=	../ft_containers/includes

SRC_DIR		=	sources
OBJ_DIR		=	test_reports
LOG			=	compilation.log

VEC_DIR1	=	vector_tests
VEC_DIR2	=	vector_performance
FT_DIR		=	ft_performance
STD_DIR		=	std_performance

NS_FT		=	-DNAMESPACE=ft
NS_STD		=	-DNAMESPACE=std

# VEC_TEST	=	vector_01_construction.cpp \
# 				vector_02_element_access.cpp \
# 				vector_03_iterators.cpp \
# 				vector_04_capacity.cpp \
# 				vector_05_modifiers.cpp \
# 				vector_06_non_member.cpp \
# 				vector_07_mix.cpp
VEC_OBJ		=	$(addprefix $(OBJ_DIR)/$(VEC_DIR1)/, $(VEC_TEST:%cpp=%o))

VEC_TIME	=	vector_01_construction.cpp \
				vector_02_element_access.cpp \
				vector_03_iterators.cpp \
				vector_04_capacity.cpp \
				vector_05_modifiers.cpp \
				vector_06_non_member.cpp
FT_OBJ		=	$(addprefix $(OBJ_DIR)/$(FT_DIR)/, $(VEC_TIME:%cpp=%o))
STD_OBJ		=	$(addprefix $(OBJ_DIR)/$(STD_DIR)/, $(VEC_TIME:%cpp=%o))

VEC_DIR		=	vector
STD_VEC_DIR	=	std_vector
FT_VEC_DIR	=	ft_vector

VEC_TEST	=	allocator.cpp \
		        clear.cpp \
		        constructors.cpp \
		        element_access.cpp \
		        erase.cpp \
		        insert.cpp \
		        iterators.cpp \
		        push_and_pop_back.cpp \
		        relational_operators.cpp \
		        reserve.cpp \
		        resize.cpp \
		        swap.cpp

STD_VEC_OBJ	=	$(addprefix $(OBJ_DIR)/$(STD_VEC_DIR)/, $(VEC_TEST:%cpp=%o))
FT_VEC_OBJ	=	$(addprefix $(OBJ_DIR)/$(FT_VEC_DIR)/, $(VEC_TEST:%cpp=%o))

MAP_DIR		=	map_tests
STD_MAP_DIR =	std_map
FT_MAP_DIR	=	ft_map

MAP_TEST	=	allocator.cpp \
				bounds_and_range.cpp \
				constructors.cpp \
				count.cpp \
				element_access.cpp \
				erase.cpp \
				find.cpp \
				insert.cpp \
				iterators.cpp \
				map_of_maps.cpp \
				relational_operators.cpp \
				swap.cpp

STD_MAP_OBJ	=	$(addprefix $(OBJ_DIR)/$(STD_MAP_DIR)/, $(MAP_TEST:%cpp=%o))
FT_MAP_OBJ	=	$(addprefix $(OBJ_DIR)/$(FT_MAP_DIR)/, $(MAP_TEST:%cpp=%o))

CXX			=	c++
CPPFLAGS_98	=	-std=c++98 -g3 -Wall -Wextra -Werror
CPPFLAGS_11	=	-std=c++11 -g3 -Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
CYAN		=	"\033[3;36m"
PURPLE		=	"\033[0;35m"

# Vector Tests
# $(OBJ_DIR)/$(VEC_DIR1)/%.o : $(SRC_DIR)/$(VEC_DIR1)/%.cpp
# 			@mkdir -p $(OBJ_DIR)
# 			@mkdir -p $(OBJ_DIR)/$(VEC_DIR1)
# 			@echo $(YELLOW)"Compiling..."$(DEFAULT)
# 			@$(CXX) $(CPPFLAGS_98) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
# 			@printf "\033[A\033[2K\r"

# # Vector Performance, ft Namespace
# $(OBJ_DIR)/$(FT_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR2)/%.cpp
# 			@mkdir -p $(OBJ_DIR)
# 			@mkdir -p $(OBJ_DIR)/$(FT_DIR)
# 			@echo $(YELLOW)"Compiling..."$(DEFAULT)
# 			@$(CXX) $(CPPFLAGS_11) $(NS_FT) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
# 			@printf "\033[A\033[2K\r"

# # Vector Performance, std Namespace
# $(OBJ_DIR)/$(STD_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR2)/%.cpp
# 			@mkdir -p $(OBJ_DIR)
# 			@mkdir -p $(OBJ_DIR)/$(STD_DIR)
# 			@echo $(YELLOW)"Compiling..."$(DEFAULT)
# 			@$(CXX) $(CPPFLAGS_11) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@
# 			@printf "\033[A\033[2K\r"

# STD VECTOR
$(OBJ_DIR)/$(STD_VEC_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(STD_VEC_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# FT VECTOR
$(OBJ_DIR)/$(FT_VEC_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(FT_VEC_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# STD MAP
$(OBJ_DIR)/$(STD_MAP_DIR)/%.o : $(SRC_DIR)/$(MAP_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(STD_MAP_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# FT MAP
$(OBJ_DIR)/$(FT_MAP_DIR)/%.o : $(SRC_DIR)/$(MAP_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/$(FT_MAP_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_FT) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# vector:		$(VEC_OBJ) $(FT_OBJ) $(STD_OBJ)
# 			@echo $(DEFAULT)$(GREEN)"Vector Test Cases Ready"$(DEFAULT)
vector:		$(STD_VEC_OBJ) $(FT_VEC_OBJ)

map:		$(STD_MAP_OBJ) $(FT_MAP_OBJ)

clean:
			@$(RM) $(OBJ_DIR) $(LOG)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
