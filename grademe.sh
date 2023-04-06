#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Please specify the container type as follows:"
	echo "    bash grademe.sh <container_type>"
	echo -e "\nSupported container types:\n    • vector\n    • map\n    • stack"
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

PROJECT_PATH=../42-ft_containers/include/containers
PROJECT_UTILS=../42-ft_containers/include/utilities

CC=c++
CFLAGS='-std=c++98 -Wall -Wextra -Werror -g3 -pthread'
INCLUDE=include
VALGRIND=valgrind
VFLAGS='--leak-check=full --show-leak-kinds=all'
NS_FT=NAMESPACE=ft
NS_STD=NAMESPACE=std
RM='rm -rf'
LOG=compilation.log

#######################################
#           Test Directories          #
#######################################
VEC_TESTS=sources/vector_tests
MAP_TESTS=sources/map_tests
STACK_TESTS=sources/stack_tests

REPORT_DIR=test_reports
LEAKS=_leak_summary

FT_VEC=ft_vector
FT_MAP=ft_map
FT_STACK=ft_stack
STD_VEC=std_vector
STD_MAP=std_map
STD_STACK=std_stack

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

create_directories() {
	mkdir -p $REPORT_DIR/$1
	mkdir -p $REPORT_DIR/$3
	if [[ "$OSTYPE" =~ ^linux && $(dpkg -l valgrind 2>/dev/null | grep valgrind) ]]; then
		mkdir -p $REPORT_DIR/$2
		mkdir -p $REPORT_DIR/$4
	fi
}

compile_and_redirect() {
	# compile and redirect output to a text file
	$CC $CFLAGS -D $2 -D ENABLE_THREAD=true -I $INCLUDE -I $PROJECT_PATH -I $PROJECT_UTILS $1 -o ${1%%.cpp} 2>> $LOG
	if [ -f ${1%%.cpp} ]; then
		./${1%%.cpp} > $REPORT_DIR/$3/$(basename -- ${1%%.cpp}).txt
	fi

	# if the output of the command above timed out, skip this step
	if [ "$(tail -n 1 "$REPORT_DIR/$3/$(basename -- ${1%%.cpp}).txt")" != "TIMEOUT" ]; then
		# if the OS is Linux and Valgrind is installed, recompile without threads (to lessen wait time and not
		# encounter a leak caused by the pthread). Then run with Valgrind and redirect output to a text file
		# located in a different directory
		if [[ -f ${1%%.cpp} && "$OSTYPE" =~ ^linux && $(dpkg -l valgrind 2>/dev/null | grep valgrind) ]]; then
			$CC $CFLAGS -D $2 -I $INCLUDE -I $PROJECT_PATH -I $PROJECT_UTILS $1 -o ${1%%.cpp} 2>> $LOG
			$VALGRIND $VFLAGS ./${1%%.cpp} > $REPORT_DIR/$4/$(basename -- ${1%%.cpp}).txt 2>&1
		fi
	fi

	# delete executable file
	if [ -f ${1%%.cpp} ]; then
		rm ${file%%.cpp}
		rm -rf ${file%%.cpp}.dSYM
	fi
}

check_valgrind_report() {
	if [[ "$OSTYPE" =~ ^linux && $(dpkg -l valgrind 2>/dev/null | grep valgrind) ]]; then
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
	printf $PURPLE'%-37s' " • $(basename -- ${1%%.cpp})$DEFAULT"
	if [[ -f $REPORT_DIR/$2/$(basename -- ${1%%.cpp}).txt && "$(tail -n 1 "$REPORT_DIR/$2/$(basename -- ${1%%.cpp}).txt")" == "TIMEOUT" ]]; then
		printf "Compiled:$GREEN OK $DEFAULT |  Result:$RED TIMEOUT $DEFAULT"
		echo
		return
	fi

	if [ -f $REPORT_DIR/$2/$(basename -- ${1%%.cpp}).txt ]; then
		echo -ne "Compiled:$GREEN OK $DEFAULT |  "
		diff <(sed '$d' $REPORT_DIR/$2/$(basename -- ${1%%.cpp}).txt) <(sed '$d' $REPORT_DIR/$4/$(basename -- ${1%%.cpp}).txt) > diff
		if [ -s diff ]; then
			echo -ne "Result:$RED KO $DEFAULT"
		else
			echo -ne "Result:$GREEN OK $DEFAULT |  "
			echo -ne "FT Time:$GREEN" $(tail -n 1 $REPORT_DIR/$2/$(basename -- ${1%%.cpp}).txt) "$DEFAULT |  "
			echo -ne "STD Time:$GREEN" $(tail -n 1 $REPORT_DIR/$4/$(basename -- ${1%%.cpp}).txt)" $DEFAULT"
		fi
		check_valgrind_report $REPORT_DIR/$3/$(basename -- ${1%%.cpp}).txt
		rm diff
	else
		printf "Compiled:$RED KO $DEFAULT |  Result:$RED KO $DEFAULT"
	fi
	echo
}

execute_and_compare() {
	for file in $1/*.cpp; do
		compile_and_redirect $file $2 $3 $4    # ft container
		compile_and_redirect $file $5 $6 $7    # std container
		print_test_results $file $3 $4 $6
	done
	echo -e $YELLOW"Details about the output can be found in the test_reports directory"$DEFAULT
	check_compilation_log_file
}

start_tests() {
	create_directories $2 $3 $4 $5
	execute_and_compare $1 $NS_FT $2 $3 $NS_STD $4 $5
}

#######################################
#             Compilation             #
#######################################
rm -rf compilation.log test_reports
if [ $1 == "vector" ]; then
	echo -e $CYAN"Vector Tester"$DEFAULT
	start_tests $VEC_TESTS $FT_VEC $FT_VEC$LEAKS $STD_VEC $STD_VEC$LEAKS "vector"
elif [ $1 == "map" ]; then
	echo -e $CYAN"Map Tester"$DEFAULT
	start_tests $MAP_TESTS $FT_MAP $FT_MAP$LEAKS $STD_MAP $STD_MAP$LEAKS "map"
elif [ $1 == "stack" ]; then
	echo -e $CYAN"Stack Tester"$DEFAULT
	start_tests $STACK_TESTS $FT_STACK $FT_STACK$LEAKS $STD_STACK $STD_STACK$LEAKS "stack"
else
	echo -e $RED"ERROR: Unknown Container Type"$DEFAULT
	exit 1
fi
