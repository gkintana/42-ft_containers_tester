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
EXEC_DIR=executables

CC=c++
CFLAGS='-Wall -Wextra -Werror'
VALGRIND=valgrind
VFLAGS='--leak-check=full --show-leak-kinds=all'
RM='rm -rf'


#######################################
#             Compilation             #
#######################################

if [ $1 == "vector" ]; then
	echo -e $CYAN"Vector Tester"$DEFAULT
	$RM $EXEC_DIR
	make re

	mkdir -p $EXEC_DIR
	for file in $OBJ_DIR/*.o; do
		$CC $CFLAGS "$file" -o "${file%%.o}"
		mv -- "${file%%.o}" $EXEC_DIR
	done

	for file in $EXEC_DIR/*; do
		echo -e $CYAN"Testing $file"$DEFAULT
		./$file
		if [[ "$OSTYPE" =~ ^linux ]]; then
			$VALGRIND $VFLAGS ./$file > $file.txt 2>&1
			echo -e $CYAN"Valgrind report for $file"$DEFAULT
			if grep -q "All heap blocks were freed -- no leaks are possible" $file.txt; then
				echo -e "Leaks: "$GREEN"OK"$DEFAULT
			else
				echo -e "Leaks: "$RED"KO"$DEFAULT
			fi

			if grep -q "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" $file.txt; then
				echo -e "Error Summary: "$GREEN"OK\n"$DEFAULT
			else
				echo -e "Error Summary: "$RED"KO\n"$DEFAULT
			fi
		fi
	done

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

if [[ "$OSTYPE" =~ ^linux ]]; then
	printf "\033[A"
fi
$RM $EXEC_DIR
make fclean
