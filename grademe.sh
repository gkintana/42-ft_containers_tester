#!/bin/bash

if [ $# -ne 1 ]; then
	echo -e "Please specify container type\nFormat:"
	echo -e "    bash grademe.sh <container_type>"
	echo "Container Types: vector, stack, map, set"
	exit 1
fi

#######################################
#             Definitions             #
#######################################

DEFAULT='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
PURPLE='\033[0;35m'
CYAN='\033[1;36m'

OBJ_DIR=objects
VEC_DIR=vector_tests
FT_VEC=ft_performance
STD_VEC=std_performance
EXEC_DIR=executables

CC=c++
CFLAGS='-Wall -Wextra -Werror'
VALGRIND=valgrind
VFLAGS='--leak-check=full --show-leak-kinds=all'
RM='rm -rf'


#######################################
#              Functions              #
#######################################
compile_vector_tests() {
	for file in $OBJ_DIR/$VEC_DIR/*.o; do
		$CC $CFLAGS "$file" -o "${file%%.o}"
		mv -- "${file%%.o}" $EXEC_DIR/$VEC_DIR
	done

	for file in $OBJ_DIR/$FT_VEC/*.o; do
		$CC $CFLAGS "$file" -o "${file%%.o}_ft"
		mv -- "${file%%.o}_ft" $EXEC_DIR/$VEC_DIR
	done

	for file in $OBJ_DIR/$STD_VEC/*.o; do
		$CC $CFLAGS "$file" -o "${file%%.o}_std"
		mv -- "${file%%.o}_std" $EXEC_DIR/$VEC_DIR
	done
}

print_vector_test_type() {
	if [[ "${file: -3}" != "_ft" && "${file: -4}" != "_std" ]]; then
		echo -e $CYAN"\nTesting $file"$DEFAULT
	elif [[ "${file: -3}" == "_ft" ]]; then
		echo -ne $YELLOW"ft::vector Time:\t\t"$DEFAULT
	elif [[ "${file: -4}" == "_std" ]]; then
		echo -ne $YELLOW"std::vector Time:\t\t"$DEFAULT
	fi
}

print_vector_test_results() {
	for file in $EXEC_DIR/$VEC_DIR/*; do
		print_vector_test_type
		./$file
		check_valgrind_report
	done
}

check_valgrind_report() {
	if [[ "$OSTYPE" =~ ^linux && "${file: -3}" != "_ft" && "${file: -4}" != "_std" ]]; then
		$VALGRIND $VFLAGS ./$file > $file.txt 2>&1
		echo -e $CYAN"Valgrind report for $file"$DEFAULT
		if grep -q "All heap blocks were freed -- no leaks are possible" $file.txt; then
			echo -e "Leaks: "$GREEN"OK"$DEFAULT
		else
			echo -e "Leaks: "$RED"KO"$DEFAULT
		fi

		if grep -q "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" $file.txt; then
			echo -e "Error Summary: "$GREEN"OK"$DEFAULT
		else
			echo -e "Error Summary: "$RED"KO"$DEFAULT
		fi
	fi
}


#######################################
#             Compilation             #
#######################################

$RM $EXEC_DIR

if [ $1 == "vector" ]; then
	echo -e $CYAN"Vector Tester"$DEFAULT

	make fclean && make vector
	mkdir -p $EXEC_DIR
	mkdir -p $EXEC_DIR/$VEC_DIR

	compile_vector_tests
	print_vector_test_results

elif [ $1 == "stack" ]; then
	echo -e $CYAN"Stack Tester"$DEFAULT
	echo -e $YELLOW"Will be available in the future"$DEFAULT
	exit 1

elif [ $1 == "map" ]; then
	echo -e $CYAN"Map Tester"$DEFAULT
	echo -e $YELLOW"Will be available in the future"$DEFAULT
	exit 1

elif [ $1 == "set" ]; then
	echo -e $CYAN"Set Tester"$DEFAULT
	echo -e $YELLOW"Will be available in the future"$DEFAULT
	exit 1

else
	echo -e $RED"Error: Unknown Container Type"$DEFAULT
	exit 1
fi


#######################################
#               Cleanup               #
#######################################

# if [[ "$OSTYPE" =~ ^linux ]]; then
# 	printf "\033[A"
# fi
$RM $EXEC_DIR
make fclean
