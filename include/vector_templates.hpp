/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_templates.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:11:55 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/03 21:32:44 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <sstream>
#include <cfloat>
// #include <cstring>
#include <vector>
#include <iterator>

#include <vector.hpp>
#include <limits.h>

#define DEFAULT    "\033[0m"
#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[0;33m"
#define PURPLE     "\033[1;35m"
#define CYAN       "\033[3;36m"

size_t test_no = 1;

void resetTestCount() { test_no = 1; }

/*----------------------------------------------------------------------------*/

template < class T >
void checkEmpty(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.empty() == std.empty()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

template < class T >
void checkEmpty(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	if (lhs.empty() == rhs.empty()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

/*----------------------------------------------------------------------------*/

template < class T >
void checkSize(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.size() == std.size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

template < class T >
void checkSize(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	if (lhs.size() == rhs.size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

/*----------------------------------------------------------------------------*/

template < class T >
void checkCapacity(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.capacity() == std.capacity()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." YELLOW "WARNING " DEFAULT;
	}
}

template < class T >
void checkCapacity(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	if (lhs.capacity() == rhs.capacity()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." YELLOW "WARNING " DEFAULT;
	}
}

/*----------------------------------------------------------------------------*/

#if __APPLE__
template < class T >
void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.max_size() == ULONG_MAX && std.max_size() == LONG_MAX) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else if (ft.max_size() == std.max_size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." YELLOW "KO " DEFAULT;
	}
}

template < class T >
void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	if (lhs.max_size() == ULONG_MAX && rhs.max_size() == LONG_MAX) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else if (lhs.max_size() == rhs.max_size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." YELLOW "KO " DEFAULT;
	}
}
#endif

#if __linux__
template < class T >
void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.max_size() == std.max_size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

template < class T >
void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	if (lhs.max_size() == rhs.max_size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}
#endif

/*----------------------------------------------------------------------------*/

template < class T >
void checkContent(ft::vector<T> &ft, std::vector<T> &std) {
	std::stringstream ft_ss, std_ss;

	for (size_t i = 0; i < ft.size(); i++) {
		ft_ss << ft[i] << " ";
	}
	for (size_t i = 0; i < std.size(); i++) {
		std_ss << std[i] << " ";
	}

	if (ft_ss.str() == std_ss.str()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

template < class T >
void checkContent(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	std::stringstream lhs_ss, rhs_ss;
	for (size_t i = 0; i < lhs.size(); i++) {
		lhs_ss << lhs[i] << " ";
	}
	for (size_t i = 0; i < rhs.size(); i++) {
		rhs_ss << rhs[i] << " ";
	}

	if (lhs_ss.str() == rhs_ss.str()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

/*----------------------------------------------------------------------------*/

template < class T >
void testVectors(ft::vector<T> &ft, std::vector<T> &std, bool add_newline) {
	checkContent(ft, std);
	checkEmpty(ft, std);
	checkSize(ft, std);
	checkCapacity(ft, std);
	checkMaxSize(ft, std);

	if (add_newline) { std::cout << std::endl; }
}

template < class T >
void testVectors(ft::vector<T> &lhs, ft::vector<T> &rhs, bool add_newline) {
	checkContent(lhs, rhs);
	checkEmpty(lhs, rhs);
	checkSize(lhs, rhs);
	checkCapacity(lhs, rhs);
	checkMaxSize(lhs, rhs);

	if (add_newline) { std::cout << std::endl; }
}

/*----------------------------------------------------------------------------*/

/**
** @brief pushes random values to both ft and std containers
**
** @param ft     address of container with ft namespace
** @param std    address of container with std namespace
** @param len    desired vector size
*/
template < class T >
void vectorPushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len,
                    bool compare_vec, bool add_newline) {
	for (size_t i = 0; i < len; i++) {
		size_t random_value = rand() % 123456789;
		ft.push_back(random_value);
		std.push_back(random_value);
	}

	if (compare_vec) {
		testVectors(ft, std, add_newline);
	}
}

template < class T >
void vectorPushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len,
                    std::string str, bool compare_vec, bool add_newline) {
	for (size_t i = 0; i < len; i++) {
		ft.push_back(str);
		std.push_back(str);
	}

	if (compare_vec) {
		testVectors(ft, std, add_newline);
	}
}

/*----------------------------------------------------------------------------*/

template < class T >
void compareAtOutput(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.size() != std.size()) {
		for (size_t i = 0; i < std::max(ft.size(), std.size()); i++) {
			std::cout << test_no++ << "." RED "KO " DEFAULT;
		}
	} else {
		for (size_t i = 0; i < ft.size(); i++) {
			if (ft.at(i) == std.at(i)) {
				std::cout << test_no++ << "." GREEN "OK " DEFAULT;
			} else {
				std::cout << test_no++ << "." RED "KO " DEFAULT;
			}
		}
	}
	std::cout << std::endl;
}

#endif
