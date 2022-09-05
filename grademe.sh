#!/bin/bash

#######################################
#             Definitions             #
#######################################

DEFAULT='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[0;33m'
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

make re

mkdir -p $EXEC_DIR
for file in $OBJ_DIR/*.o; do
	$CC $CFLAGS "$file" -o "${file%%.o}"
	mv -- "${file%%.o}" $EXEC_DIR
done


#######################################
#               Testing               #
#######################################

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


#######################################
#               Cleanup               #
#######################################

if [[ "$OSTYPE" =~ ^linux ]]; then
	printf "\033[A"
fi

$RM $EXEC_DIR
make fclean
