# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 17:01:53 by gkintana          #+#    #+#              #
#    Updated: 2022/12/11 15:34:57 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR		=	include
CONT_DIR1	=	../42-ft_containers/include/containers
CONT_DIR2	=	../42-ft_containers/include/utilities
# CONT_DIR1	=	../ft_containers/includes

SRC_DIR		=	sources
OBJ_DIR		=	test_reports
LOG			=	compilation.log

NS_FT		=	-D NAMESPACE=ft
NS_STD		=	-D NAMESPACE=std

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

MAP_DIR		=	map_tests
STD_MAP_DIR =	std_map
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

CXX			=	c++
CPPFLAGS_98	=	-std=c++98 -g3 -Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
CYAN		=	"\033[3;36m"
PURPLE		=	"\033[0;35m"

# STD VECTOR
$(OBJ_DIR)/$(STD_VEC_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(STD_VEC_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# FT VECTOR
$(OBJ_DIR)/$(FT_VEC_DIR)/%.o : $(SRC_DIR)/$(VEC_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(FT_VEC_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# STD MAP
$(OBJ_DIR)/$(STD_MAP_DIR)/%.o : $(SRC_DIR)/$(MAP_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(STD_MAP_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_STD) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

# FT MAP
$(OBJ_DIR)/$(FT_MAP_DIR)/%.o : $(SRC_DIR)/$(MAP_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(FT_MAP_DIR)
			@$(CXX) $(CPPFLAGS_98) $(NS_FT) -I$(INC_DIR) -I$(CONT_DIR1) -I$(CONT_DIR2) -c $< -o $@

vector:		$(STD_VEC_OBJ) $(FT_VEC_OBJ)

map:		$(STD_MAP_OBJ) $(FT_MAP_OBJ)

clean:
			@$(RM) $(OBJ_DIR) $(LOG)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
