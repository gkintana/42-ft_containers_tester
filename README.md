# 42 - FT_CONTAINERS TESTER

This repository is a work in progress. Currently tests a few functions in vectors.

Will automatically run with valgrind if the system being used is Linux.

## Usage
1. Clone this repository inside your ft_containers project

2. Modify the Makefile's CONT_DIR1 path to the directory where your \<container>\.hpp files are located

3. Remove CONT_DIR2 on `line 17` and -I$(CONT_DIR2) on `line 41`

4. Run the tester with bash grademe.sh
