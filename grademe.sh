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
LOG=compilation.log


TEST_DIR=test_reports

VEC_DIR=vector
STD_VEC=std_vector
STD_VEC_LEAKS=std_vector_leak_summary
FT_VEC=ft_vector
FT_VEC_LEAKS=ft_vector_leak_summary

MAP_DIR=map_tests
STD_MAP=std_map
STD_MAP_LEAKS=std_map_leak_summary
FT_MAP=ft_map
FT_MAP_LEAKS=ft_map_leak_summary

#######################################
#              Functions              #
#######################################
check_compilation_log_file() {
	if [ -s $LOG ]; then
		echo -e $RED"Encountered some compilation errors, please check $LOG for more details"$DEFAULT
	else
		$RM $LOG
	fi
}

create_folders_for_valgrind_output() {
	if [[ "$OSTYPE" =~ ^linux ]]; then
		mkdir -p $TEST_DIR/$1
		mkdir -p $TEST_DIR/$2
	fi
}

execute_and_redirect_output() {
	for file in $TEST_DIR/$1/*.o; do
		# compile object files then run and redirect output to a text file
		$CC $CFLAGS $file -o ${file%%.o}
		./${file%%.o} > ${file%%.o}.txt

		# (if OS is linux) run with valgrind and redirect output to a text file located in a different directory
		if [[ "$OSTYPE" =~ ^linux ]]; then
			$VALGRIND $VFLAGS ./${file%%.o} > $TEST_DIR/$2/$(basename -- $file .o).txt 2>&1
		fi

		# delete object and executable file
		rm $file ${file%%.o}
	done
	printf "\033[A\033[2K\r"
}

check_valgrind_report() {
	if [[ "$OSTYPE" =~ ^linux ]]; then
		if grep -q "All heap blocks were freed -- no leaks are possible" $1; then
			echo -ne " |  Leaks:$GREEN OK $DEFAULT |  "
		else
			echo -ne " |  Leaks:$RED KO $DEFAULT |  "
		fi

		if grep -q "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" $1; then
			echo -ne "Error Summary:$GREEN OK $DEFAULT"
		else
			echo -ne "Error Summary:$RED KO $DEFAULT"
		fi
	fi
}

print_test_results() {
	for file in $TEST_DIR/$1/*.txt; do
		printf $PURPLE'%-37s' " • $(basename -- $file .txt)$DEFAULT"
		if [ -f $TEST_DIR/$2/${file##*/} ]; then
			echo -ne "Compiled:$GREEN OK $DEFAULT |  "
			diff <(sed '$d' $file) <(sed '$d' $TEST_DIR/$2/${file##*/}) > diff
			if [ -s diff ]; then
				echo -ne "Result:$RED KO $DEFAULT"
			else
				echo -ne "Result:$GREEN OK $DEFAULT |  "
				echo -ne "FT Time:$GREEN" $(tail -n 1 $TEST_DIR/$2/${file##*/}) "$DEFAULT |  "
				echo -ne "STD Time:$GREEN" $(tail -n 1 $file)" $DEFAULT"
			fi
			check_valgrind_report $TEST_DIR/$3/${file##*/}
			rm diff
		else
			printf "Compiled:$RED KO $DEFAULT |  Result:$RED KO $DEFAULT"
		fi
		echo
	done
	echo -e $YELLOW"Details about the output can be found in the test_reports directory"$DEFAULT
	check_compilation_log_file
}

start_tests() {
	printf "\033[A\033[2K\r"
	create_folders_for_valgrind_output $4 $2

	echo -e $YELLOW"Turning ft::$5 objects into executables & saving their output to a .txt file"$DEFAULT
	execute_and_redirect_output $1 $2
	echo -e $YELLOW"Turning std::$5 objects into executables & saving their output to a .txt file"$DEFAULT
	execute_and_redirect_output $3 $4

	print_test_results $3 $1 $2
}

#######################################
#             Compilation             #
#######################################
if [ $1 == "vector" ]; then
	echo -e $CYAN"Vector Tester"$DEFAULT
	echo -e $YELLOW"Compiling..."$DEFAULT

	make fclean && make -k vector 2> $LOG
	start_tests $FT_VEC $FT_VEC_LEAKS $STD_VEC $STD_VEC_LEAKS "vector"

elif [ $1 == "stack" ]; then
	echo -e $CYAN"Stack Tester"$DEFAULT
	echo -e $YELLOW"Will be available in the future"$DEFAULT
	exit 1

elif [ $1 == "map" ]; then
	echo -e $CYAN"Map Tester"$DEFAULT
	echo -e $YELLOW"Compiling..."$DEFAULT

	make fclean && make -k map 2> $LOG
	start_tests $FT_MAP $FT_MAP_LEAKS $STD_MAP $STD_MAP_LEAKS "map"

elif [ $1 == "set" ]; then
	echo -e $CYAN"Set Tester"$DEFAULT
	echo -e $YELLOW"Will be available in the future"$DEFAULT
	exit 1

else
	echo -e $RED"Error: Unknown Container Type"$DEFAULT
	exit 1
fi
