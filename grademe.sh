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

DEFAULT=$(tput sgr0)
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
PURPLE='\033[1;35m'
CYAN='\033[1;36m'

CC=c++
CFLAGS='-Wall -Wextra -Werror'
VALGRIND=valgrind
VFLAGS='--leak-check=full --show-leak-kinds=all'
RM='rm -rf'


TEST_DIR=test_reports

VEC_DIR=vector_tests
FT_VEC=ft_performance
STD_VEC=std_performance
EXEC_DIR=executables

MAP_DIR=map_tests
STD_MAP=std_map
FT_MAP=ft_map
FT_MAP_LEAKS=ft_map_leak_summary


#######################################
#              Functions              #
#######################################
compile_vector_tests() {
	for file in $TEST_DIR/$VEC_DIR/*.o; do
		$CC $CFLAGS "$file" -o "${file%%.o}"
		mv -- "${file%%.o}" $EXEC_DIR/$VEC_DIR
	done

	for file in $TEST_DIR/$FT_VEC/*.o; do
		$CC $CFLAGS "$file" -o "${file%%.o}_ft"
		mv -- "${file%%.o}_ft" $EXEC_DIR/$VEC_DIR
	done

	for file in $TEST_DIR/$STD_VEC/*.o; do
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

map_valgrind_report() {
	if [[ "$OSTYPE" =~ ^linux ]]; then
		if grep -q "All heap blocks were freed -- no leaks are possible" $TEST_DIR/$FT_MAP_LEAKS/${file##*/}; then
			echo -ne " |  Leaks:$GREEN OK $DEFAULT |  "
		else
			echo -ne " |  Leaks:$RED KO $DEFAULT |  "
		fi

		if grep -q "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" $TEST_DIR/$FT_MAP_LEAKS/${file##*/}; then
			echo -ne "Error Summary:$GREEN OK $DEFAULT"
		else
			echo -ne "Error Summary:$RED KO $DEFAULT"
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

	# use Makefile to create object files of tests case
	make fclean && make map

	# (if OS is linux) create an extra folder to store leak reports
	if [[ "$OSTYPE" =~ ^linux ]]; then
		mkdir -p $TEST_DIR/$FT_MAP_LEAKS
	fi

	for file in $TEST_DIR/$FT_MAP/*.o; do
		# compile object files then run and redirect output to a text file
		$CC $CFLAGS $file -o ${file%%.o}
		./${file%%.o} > ${file%%.o}.txt

		# (if OS is linux) run with valgrind and redirect output to a text file located in a different directory
		if [[ "$OSTYPE" =~ ^linux ]]; then
			$VALGRIND $VFLAGS ./${file%%.o} > $TEST_DIR/$FT_MAP_LEAKS/$(basename -- $file .o).txt 2>&1
		fi

		# delete object and executable file
		rm $file ${file%%.o}
	done

	for file in $TEST_DIR/$STD_MAP/*.o; do
		# compile object files then run and redirect output to a text file
		$CC $CFLAGS $file -o ${file%%.o}
		./${file%%.o} > ${file%%.o}.txt

		# delete object and executable file
		rm $file ${file%%.o}
	done

	for file in $TEST_DIR/$STD_MAP/*.txt; do
		printf $PURPLE'%-25s' " • $(basename -- $file .txt)$DEFAULT"
		if [ -f $TEST_DIR/$FT_MAP/${file##*/} ]; then
			echo -ne "Compiled:$GREEN OK $DEFAULT |  "
			diff <(head -n -1 $file) <(head -n -1 $TEST_DIR/$FT_MAP/${file##*/}) > diff
			if [ -s diff ]; then
				echo -ne "Result:$RED KO $DEFAULT"
			else
				echo -ne "Result:$GREEN OK $DEFAULT |  "
				echo -ne "FT Time:$GREEN" $(tail -n 1 $TEST_DIR/$FT_MAP/${file##*/}) "$DEFAULT |  "
				echo -ne "STD Time:$GREEN" $(tail -n 1 $file)" $DEFAULT"
			fi
			map_valgrind_report
			rm diff
		else
			echo -e "Compiled:$RED KO $DEFAULT |  Result:$RED KO $DEFAULT"
		fi
		echo
	done

elif [ $1 == "set" ]; then
	echo -e $CYAN"Set Tester"$DEFAULT
	echo -e $YELLOW"Will be available in the future"$DEFAULT
	exit 1

else
	echo -e $RED"Error: Unknown Container Type"$DEFAULT
	exit 1
fi
