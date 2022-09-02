/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_03_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:26:11 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/02 23:50:24 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

/**
** @param ft             address of container with ft namespace
** @param std            address of container with std namespace
** @param offset         integer which represents a value to be added or subtracted
**                       to the iterator's position
** @param option         integer that indicates which type of iterator or reverse
**                       iterator will be compared with the std equivalent
** @param add_newline    boolean to check if a newline should be printed after
**                       the test result 
*/
template < class T >
static void compareWithStd(ft::vector<T> &ft, std::vector<T> &std, int offset,
                           int option, bool add_newline) {
	if (option == 1) {
		if (*(ft.begin() + offset) == *(std.begin() + offset)) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT;
		} else {
			std::cout << test_no++ << "." RED "KO " DEFAULT;
		}
	} else if (option == 2) {
		if (*(ft.end() - offset) == *(std.end() - offset)) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT;
		} else {
			std::cout << test_no++ << "." RED "KO " DEFAULT;
		}
	} else if (option == 3) {
		if (*(ft.rbegin() + offset) == *(std.rbegin() + offset)) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT;
		} else {
			std::cout << test_no++ << "." RED "KO " DEFAULT;
		}
	} else if (option == 4) {
		if (*(ft.rend() - offset) == *(std.rend() - offset)) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT;
		} else {
			std::cout << test_no++ << "." RED "KO " DEFAULT;
		}
	}

	if (add_newline) { std::cout << std::endl; }
}

/**
**
*/
template < class T >
static void iteratorLoop(std::vector<T> &std, typename ft::vector<T>::iterator start,
                         typename ft::vector<T>::iterator end, bool add_newline) {
	std::vector<int>::iterator std_iter = std.begin();
	for (ft::vector<int>::iterator ft_iter = start; ft_iter != end; ft_iter++) {
		if (*ft_iter == *std_iter++) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT;
		} else {
			std::cout << test_no++ << "." RED "KO " DEFAULT;
		}
	}

	if (add_newline) { std::cout << std::endl; }
}

/*----------------------------------------------------------------------------*/

#define BEGIN     1
#define END       2
#define RBEGIN    3
#define REND      4

static void beginTests();
static void endTests();
static void iteratorLoopTests();

static void rendTests();

int main() {
	std::cout << PURPLE "Iterator Tests" DEFAULT << std::endl;
	beginTests();
	endTests();
	iteratorLoopTests();

	std::cout << PURPLE "Reverse Iterator Tests" DEFAULT << std::endl;
	rendTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void beginTests() {
	resetTestCount();
	std::cout << "Begin: ";

	size_t size = 21,
	       value = 42;
	ft::vector<int> ft_vec(size, value);
	std::vector<int> std_vec(size, value);

	compareWithStd(ft_vec, std_vec, 0, BEGIN, false);
	compareWithStd(ft_vec, std_vec, size / 2, BEGIN, false);
	compareWithStd(ft_vec, std_vec, size - 1, BEGIN, true);
}

static void endTests() {
	resetTestCount();
	std::cout << "End: ";

	size_t size = 21,
	       value = 42;
	ft::vector<int> ft_vec(size, value);
	std::vector<int> std_vec(size, value);

	compareWithStd(ft_vec, std_vec, 1, END, false);
	compareWithStd(ft_vec, std_vec, size / 2, END, false);
	compareWithStd(ft_vec, std_vec, size, END, true);
}

static void iteratorLoopTests() {
	resetTestCount();
	std::cout << "Iterator Loop: ";

	size_t size = 16,
	       value = 42;
	ft::vector<int> ft_vec(size, value);
	std::vector<int> std_vec(size, value);

	iteratorLoop(std_vec, ft_vec.begin(), ft_vec.end(), false);
	iteratorLoop(std_vec, ft_vec.begin() + (size / 2), ft_vec.end() - (size / 4), false);
	iteratorLoop(std_vec, ft_vec.end() - size, ft_vec.end(), false);
	iteratorLoop(std_vec, ft_vec.end() - (size / 2), ft_vec.end() - (size / 4), true);
}

static void rendTests() {
	resetTestCount();
	std::cout << "Rend: ";

	size_t size = 21,
	       value = 42;
	ft::vector<int> ft_vec(size, value);
	std::vector<int> std_vec(size, value);

	compareWithStd(ft_vec, std_vec, 1, REND, false);
	compareWithStd(ft_vec, std_vec, size / 2, REND, false);
	compareWithStd(ft_vec, std_vec, size - 1, REND, true);
}
