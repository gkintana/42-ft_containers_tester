#!/bin/bash

# colors codes
DEFAULT='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[0;33m'
PURPLE='\033[0;35m'
CYAN='\033[1;4;36m'

# file definitions
FT=ft_containers
STD=std_containers
FT_EXEC=./$FT
FT_TEXT=$FT.txt
STD_EXEC=./$STD
STD_TEXT=$STD.txt
RESULT=diff_result.txt

# checks if the project has been compiled, if not, will call "re" rule
# from makefile
# if [ ! -f $FT ] && [ ! -f $STD ]; then
	make re
# fi

# redirects output of ./ft_containers to ft_containers.txt

# echo -e $PURPLE"$FT_EXEC > $FT_TEXT"$DEFAULT
# $FT_EXEC > $FT_TEXT

# redirects output of ./std_containers to std_containers.txt

# echo -e $PURPLE"$STD_EXEC > $STD_TEXT"$DEFAULT
# $STD_EXEC > $STD_TEXT

# search for any differences between the ft and std containers with the
# assistance of the diff command

# echo -e $PURPLE"diff $FT_TEXT $STD_TEXT > $RESULT"$DEFAULT
# diff $FT_TEXT $STD_TEXT > $RESULT

# checks if diff_result.txt contains any information, and if they do,
# print [KO]. But if they're empty, print [OK]

# echo -e $YELLOW"Checking contents of $RESULT"$DEFAULT
# if [ -s $RESULT ]; then
# 	echo -e "Status: "$RED"[KO]"$DEFAULT
# else
# 	echo -e "Status: "$GREEN"[OK]"$DEFAULT
# fi

COMPILER=c++
COMPILE_FLAGS='-Wall -Wextra -Werror'
VALGRIND=valgrind
VALGRIND_FLAGS='--leak-check=full --show-leak-kinds=all'
EXEC=a.out
TEXT_FILE=output.txt

for file in objects/*.o; do
    echo -e $CYAN"Testing $file"$DEFAULT
	$COMPILER $COMPILE_FLAGS "$file"; ./$EXEC

	if [[ "$OSTYPE" =~ ^linux ]]; then
		$VALGRIND $VALGRIND_FLAGS ./$EXEC > $TEXT_FILE 2>&1
		echo -e $CYAN"Valgrind report for $file"$DEFAULT
		if grep -q "All heap blocks were freed -- no leaks are possible" $TEXT_FILE; then
			echo -e "Leaks: "$GREEN"[OK]"$DEFAULT
		else
			echo -e "Leaks: "$RED"[KO]"$DEFAULT
		fi

		if grep -q "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" $TEXT_FILE; then
			echo -e "Error Summary: "$GREEN"[OK]\n"$DEFAULT
		else
			echo -e "Error Summary: "$RED"[KO]\n"$DEFAULT
		fi
	fi
# echo "Output file => ${f%.*}"
done


# deletes all text files

# echo -e $PURPLE"Deleted $FT_TEXT, $STD_TEXT, and $RESULT"$DEFAULT
# rm $FT_TEXT $STD_TEXT $RESULT
# rm a.out vector_construction.txt
if [[ "$OSTYPE" =~ ^linux ]]; then
	rm a.out *.txt
else
	rm a.out
fi
make fclean