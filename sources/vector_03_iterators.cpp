/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_03_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:26:11 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/03 21:42:12 by gkintana         ###   ########.fr       */
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
static void iteratorLoop(ft::vector<T> &ft, std::vector<T> &std,
                         typename ft::vector<T>::iterator start,
                         typename ft::vector<T>::iterator end,
					     bool add_newline) {
	typedef typename std::vector<T>::iterator STD_ITERATOR;
	typedef typename ft::vector<T>::iterator FT_ITERATOR;

	size_t pos = 0;
	for (FT_ITERATOR temp = ft.begin(); temp != start; temp++) {
		pos++;
	}

	STD_ITERATOR std_iter = std.begin() + pos;
	for (FT_ITERATOR ft_iter = start; ft_iter != end; ft_iter++) {
		if (*ft_iter == *std_iter++) {
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
static void reverseIteratorLoop(ft::vector<T> &ft, std::vector<T> &std,
                                typename ft::vector<T>::reverse_iterator start,
                                typename ft::vector<T>::reverse_iterator end,
								bool add_newline) {
	typedef typename std::vector<T>::reverse_iterator STD_REVERSE;
	typedef typename ft::vector<T>::reverse_iterator FT_REVERSE;

	size_t pos = 0;
	for (FT_REVERSE temp = ft.rend(); temp != start; temp--) {
		pos++;
	}

	STD_REVERSE std_iter = std.rend() - pos;
	for (FT_REVERSE ft_iter = start; ft_iter != end; ft_iter--) {
		if (*ft_iter == *std_iter--) {
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
static void rbeginTests();
static void rendTests();
static void reverseIteratorLoopTests();

int main() {
	std::srand(time(NULL));

	std::cout << PURPLE "Iterator Tests" DEFAULT << std::endl;
	beginTests();
	endTests();
	iteratorLoopTests();

	std::cout << PURPLE "Reverse Iterator Tests" DEFAULT << std::endl;
	rbeginTests();
	rendTests();
	reverseIteratorLoopTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void beginTests() {
	resetTestCount();
	std::cout << "Begin: ";

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	vectorPushLoop(ft_vec, std_vec, 10, false, false);

	// test no. 1
	compareWithStd(ft_vec, std_vec, 0, BEGIN, false);
	// test no. 2
	compareWithStd(ft_vec, std_vec, ft_vec.size() / 2, BEGIN, false);
	// test no. 3
	compareWithStd(ft_vec, std_vec, ft_vec.size() - 1, BEGIN, true);
}

static void endTests() {
	resetTestCount();
	std::cout << "End: ";

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	vectorPushLoop(ft_vec, std_vec, 10, false, false);

	// test no. 1
	compareWithStd(ft_vec, std_vec, 1, END, false);
	// test no. 2
	compareWithStd(ft_vec, std_vec, ft_vec.size() / 2, END, false);
	// test no. 3
	compareWithStd(ft_vec, std_vec, ft_vec.size(), END, true);
}

static void iteratorLoopTests() {
	resetTestCount();
	std::cout << "Iterator Loop: ";

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	vectorPushLoop(ft_vec, std_vec, 10, false, false);

	// test no. 1 - 10
	iteratorLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end(), false);
	// test no. 11 - 15
	iteratorLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 2), ft_vec.end(), false);
	// test no. 16
	iteratorLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() - 1), ft_vec.end(), false);
	// just checking for any valgrind errors
	iteratorLoop(ft_vec, std_vec, ft_vec.begin() + ft_vec.size(), ft_vec.end(), false);
	// test no. 17 - 24
	iteratorLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - (ft_vec.size() / 4), false);
	// test no. 25 - 29
	iteratorLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - (ft_vec.size() / 2), false);
	// test no. 30
	iteratorLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - (ft_vec.size() - 1), false);
	// just checking for any valgrind errors
	iteratorLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - ft_vec.size(), false);
	// test no. 31 - 33
	iteratorLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 4), ft_vec.end() - (ft_vec.size() / 2), false);
	// test no. 34 - 37
	iteratorLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 3), ft_vec.end() - (ft_vec.size() / 3), false);
	// test no. 38 - 40
	iteratorLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 2), ft_vec.end() - (ft_vec.size() / 4), false);
	// just checking for any valgrind errors
	iteratorLoop(ft_vec, std_vec, ft_vec.end(), ft_vec.end(), false);
	// test no. 41 - 50
	iteratorLoop(ft_vec, std_vec, ft_vec.end() - ft_vec.size(), ft_vec.end(), false);
	// test no. 51 - 55
	iteratorLoop(ft_vec, std_vec, ft_vec.end() - (ft_vec.size() / 2), ft_vec.end(), false);
	// test no. 56 - 58
	iteratorLoop(ft_vec, std_vec, ft_vec.end() - (ft_vec.size() / 2), ft_vec.end() - (ft_vec.size() / 4), true);
}

static void rbeginTests() {
	resetTestCount();
	std::cout << "Rbegin: ";

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	vectorPushLoop(ft_vec, std_vec, 10, false, false);

	// test no. 1
	compareWithStd(ft_vec, std_vec, 0, RBEGIN, false);
	// test no. 2
	compareWithStd(ft_vec, std_vec, ft_vec.size() / 2, RBEGIN, false);
	// test no. 3
	compareWithStd(ft_vec, std_vec, ft_vec.size() - 1, RBEGIN, true);
}

static void rendTests() {
	resetTestCount();
	std::cout << "Rend: ";

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	vectorPushLoop(ft_vec, std_vec, 10, false, false);

	// test no. 1
	compareWithStd(ft_vec, std_vec, 1, REND, false);
	// test no. 2
	compareWithStd(ft_vec, std_vec, ft_vec.size() / 2, REND, false);
	// test no. 3
	compareWithStd(ft_vec, std_vec, ft_vec.size() - 1, REND, true);
}

static void reverseIteratorLoopTests() {
	resetTestCount();
	std::cout << "Reverse Iterator Loop: ";

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	vectorPushLoop(ft_vec, std_vec, 10, false, false);

	// test no. 1 - 9
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin(), false);
	// test no. 10 - 14
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 2), ft_vec.rbegin(), false);
	// test no. 15
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() - 1), ft_vec.rbegin(), false);
	// just checking for any valgrind errors
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - ft_vec.size(), ft_vec.rbegin(), false);
	// test no. 16 - 22
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + (ft_vec.size() / 4), false);
	// test no. 23 - 28
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + (ft_vec.size() / 3), false);
	// test no. 29 - 32
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + (ft_vec.size() / 2), false);
	// just checking for any valgrind errors
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + ft_vec.size() - 1, false);
	// test no. 33 - 35
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 4), ft_vec.rbegin() + (ft_vec.size() / 2), false);
	// test no. 36 - 39
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 3), ft_vec.rbegin() + (ft_vec.size() / 3), false);
	// test no. 40 - 42
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 2), ft_vec.rbegin() + (ft_vec.size() / 4), false);
	// test no. 43
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rbegin() + 1, ft_vec.rbegin(), false);
	// test no. 44 - 52
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rbegin() + (ft_vec.size() - 1), ft_vec.rbegin(), false);
	// test no. 53 - 57
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rbegin() + (ft_vec.size() / 2), ft_vec.rbegin(), false);
	// test no. 58 - 60
	reverseIteratorLoop(ft_vec, std_vec, ft_vec.rbegin() + (ft_vec.size() / 2), ft_vec.rbegin() + (ft_vec.size() / 4), true);
}
