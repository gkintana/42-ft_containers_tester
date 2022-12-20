# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/12/20 11:17:36 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CONT_DIR1	=	../
CONT_DIR2	=	$CONT_DIR1

# my personal config
# CONT_DIR1	=	../42-ft_containers/include/containers
# CONT_DIR2	=	../42-ft_containers/include/utilities

INC_DIR		=	include
SRC_DIR		=	sources
OBJ_DIR		=	test_reports

CXX			=	c++
CPPFLAGS	=	-std=c++98 -g3 -Wall -Wextra -Werror
NS_STD		=	-D NAMESPACE=std
NS_FT		=	-D NAMESPACE=ft
DELETE		=	rm -rf

###################################################################################################

VEC_DIR		=	vector_tests
STD_VEC_DIR	=	std_vector
FT_VEC_DIR	=	ft_vector
VEC_TEST	=	allocator.cpp \
		        clear.cpp \
		        constructors.cpp \
		        element_access.cpp \
		        erase.cpp \
		        insert.cpp \
		        iterators.cpp \
		        multidimensional_vector.cpp \
		        push_and_pop_back.cpp \
		        relational_operators.cpp \
		        reserve.cpp \
		        resize.cpp \
		        swap.cpp
STD_VEC_OBJ	=	$(addprefix $(OBJ_DIR)/$(STD_VEC_DIR)/, $(VEC_TEST:%cpp=%o))
FT_VEC_OBJ	=	$(addprefix $(OBJ_DIR)/$(FT_VEC_DIR)/, $(VEC_TEST:%cpp=%o))

# STD VECTOR
$(OBJ_DIR)/$(STD_VEC_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(STD_VEC_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# FT VECTOR
$(OBJ_DIR)/$(FT_VEC_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(FT_VEC_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

###################################################################################################

MAP_DIR		=	map_tests
STD_MAP_DIR	=	std_map
FT_MAP_DIR	=	ft_map
MAP_TEST	=	allocator.cpp \
		        bounds_and_range.cpp \
		        compare.cpp \
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

# STD MAP
$(OBJ_DIR)/$(STD_MAP_DIR)/%.o : $(SRC_DIR)/$(MAP_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(STD_MAP_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# FT MAP
$(OBJ_DIR)/$(FT_MAP_DIR)/%.o : $(SRC_DIR)/$(MAP_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(FT_MAP_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_FT) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

###################################################################################################

STK_DIR		=	stack_tests
STD_STK_DIR	=	std_stack
FT_STK_DIR	=	ft_stack
STK_TEST	=	constructors.cpp \
		        multidimensional_stack.cpp \
		        push_and_pop.cpp \
		        relational_operators.cpp
STD_STK_OBJ	=	$(addprefix $(OBJ_DIR)/$(STD_STK_DIR)/, $(STK_TEST:%cpp=%o))
FT_STK_OBJ	=	$(addprefix $(OBJ_DIR)/$(FT_STK_DIR)/, $(STK_TEST:%cpp=%o))

# STD MAP
$(OBJ_DIR)/$(STD_STK_DIR)/%.o : $(SRC_DIR)/$(STK_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(STD_STK_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# FT MAP
$(OBJ_DIR)/$(FT_STK_DIR)/%.o : $(SRC_DIR)/$(STK_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(FT_STK_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_FT) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

###################################################################################################

vector:		$(STD_VEC_OBJ) $(FT_VEC_OBJ)

map:		$(STD_MAP_OBJ) $(FT_MAP_OBJ)

stack:		$(STD_STK_OBJ) $(FT_STK_OBJ)

clean:
			@$(DELETE) $(OBJ_DIR) *.log

fclean:		clean

re:			fclean all

.PHONY:		vector map stack clean fclean re
