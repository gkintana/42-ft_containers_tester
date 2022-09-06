/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_templates.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:11:55 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/06 22:30:09 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEMPLATES_HPP
#define VECTOR_TEMPLATES_HPP

// C++ Library
#include <iostream>
#include <sstream>
#include <cfloat>
// #include <cstring>
#include <iterator>
#include <vector>
// #include <fstream>

// C Library
#include <limits.h>

// Project Library
#include <vector.hpp>
#include <stack.hpp>


#define DEFAULT    "\033[0m"
#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[1;33m"
#define PURPLE     "\033[1;35m"
#define CYAN       "\033[3;36m"

#define OK         1
#define WARNING    2
#define KO         3

size_t test_no = 1;

// class vectorTester {
// 	private:
// 		size_t OK;
// 		size_t WARNING;
// 		size_t KO;
// 		size_t test_no;
// 		std::ofstream report;

// 	public:
// 		tester() : OK(0), WARNING(0), KO(0), test_no(1) {}
// 		~tester() {}
// 		void addOK() { this->OK++; }
// 		void addWarning() { this->WARNING++; }
// 		void addKO() { this->KO++; }
// };

/*----------------------------------------------------------------------------*/

void resetTestCount(std::string test_type) {
	test_no = 1;
	std::cout << test_type;
}

void printTestResult(int result) {
	result == OK ? std::cout << test_no++ << "." GREEN "OK " DEFAULT:
	result == WARNING ? std::cout << test_no++ << "." YELLOW "WARNING " DEFAULT:
	std::cout << test_no++ << "." RED "KO " DEFAULT;
}

/*----------------------------------------------------------------------------*/

template <typename T>
void checkEmpty(ft::vector<T> &ft, std::vector<T> &std) { ft.empty() == std.empty() ? printTestResult(OK) : printTestResult(KO); }

template <typename T>
void checkEmpty(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.empty() == rhs.empty() ? printTestResult(OK) : printTestResult(KO); }

/*----------------------------------------------------------------------------*/

template <typename T>
void checkSize(ft::vector<T> &ft, std::vector<T> &std) { ft.size() == std.size() ? printTestResult(OK) : printTestResult(KO); }

template <typename T>
void checkSize(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.size() == rhs.size() ? printTestResult(OK) : printTestResult(KO); }

/*----------------------------------------------------------------------------*/

template <typename T>
void checkCapacity(ft::vector<T> &ft, std::vector<T> &std) { ft.capacity() == std.capacity() ? printTestResult(OK) : printTestResult(WARNING); }

template <typename T>
void checkCapacity(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.capacity() == rhs.capacity() ? printTestResult(OK) : printTestResult(WARNING); }

/*----------------------------------------------------------------------------*/

#if __APPLE__
template < class T >
void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.max_size() == ULONG_MAX && std.max_size() == LONG_MAX) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else if (ft.max_size() == std.max_size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}

template < class T >
void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	if (lhs.max_size() == ULONG_MAX && rhs.max_size() == LONG_MAX) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else if (lhs.max_size() == rhs.max_size()) {
		std::cout << test_no++ << "." GREEN "OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "KO " DEFAULT;
	}
}
#endif

#if __linux__
template <typename T>
void checkMaxSize(ft::vector<T> &ft, std::vector<T> &std) { ft.max_size() == std.max_size() ? printTestResult(OK) : printTestResult(KO); }

template <typename T>
void checkMaxSize(ft::vector<T> &lhs, ft::vector<T> &rhs) { lhs.max_size() == rhs.max_size() ? printTestResult(OK) : printTestResult(KO); }
#endif

/*----------------------------------------------------------------------------*/

template <typename T>
void checkContent(ft::vector<T> &ft, std::vector<T> &std) {
	std::stringstream ft_ss, std_ss;

	for (size_t i = 0; i < ft.size(); i++) {
		ft_ss << ft[i] << " ";
	}
	for (size_t i = 0; i < std.size(); i++) {
		std_ss << std[i] << " ";
	}

	ft_ss.str() == std_ss.str() ? printTestResult(OK) : printTestResult(KO);
}

template <typename T>
void checkContent(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	std::stringstream lhs_ss, rhs_ss;
	for (size_t i = 0; i < lhs.size(); i++) {
		lhs_ss << lhs[i] << " ";
	}
	for (size_t i = 0; i < rhs.size(); i++) {
		rhs_ss << rhs[i] << " ";
	}

	lhs_ss.str() == rhs_ss.str() ? printTestResult(OK) : printTestResult(KO);
}

/*----------------------------------------------------------------------------*/

template <typename T>
void compareVectors(ft::vector<T> &ft, std::vector<T> &std, bool add_newline) {
	checkContent(ft, std);
	checkEmpty(ft, std);
	checkSize(ft, std);
	checkCapacity(ft, std);
	checkMaxSize(ft, std);

	if (add_newline) {
		std::cout << std::endl;
	}
}

template <typename T>
void compareVectors(ft::vector<T> &lhs, ft::vector<T> &rhs, bool add_newline) {
	checkContent(lhs, rhs);
	checkEmpty(lhs, rhs);
	checkSize(lhs, rhs);
	checkCapacity(lhs, rhs);
	checkMaxSize(lhs, rhs);

	if (add_newline) {
		std::cout << std::endl;
	}
}

/*----------------------------------------------------------------------------*/

/**
** @brief    pushes random values to both ft and std containers
**
** @param ft             address of container with ft namespace
** @param std            address of container with std namespace
** @param len            desired vector size
** @param compare_vec    determines if the ft and std vector will be compared once
**                       the push_back loop ends
** @param add_newline    checks if the function should print a newline after testing
*/
template <typename T>
void vectorPushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len,
                    bool compare_vec, bool add_newline) {
	for (size_t i = 0; i < len; i++) {
		size_t random_value = std::rand() % 123456789;
		ft.push_back(random_value);
		std.push_back(random_value);
	}

	if (compare_vec) {
		compareVectors(ft, std, add_newline);
	}
}

/**
** @brief    pushes the exact same string to both ft and std containers according to
**           the size of len
**
** @param str    std::string to be pushed to the ft and std vectors
*/
template <typename T>
void vectorPushLoop(ft::vector<T> &ft, std::vector<T> &std, size_t len,
                    std::string str, bool compare_vec, bool add_newline) {
	for (size_t i = 0; i < len; i++) {
		ft.push_back(str);
		std.push_back(str);
	}

	if (compare_vec) {
		compareVectors(ft, std, add_newline);
	}
}

/*----------------------------------------------------------------------------*/

template <typename T>
void compareAtOutput(ft::vector<T> &ft, std::vector<T> &std) {
	if (ft.size() != std.size()) {
		for (size_t i = 0; i < std::max(ft.size(), std.size()); i++) {
			printTestResult(KO);
		}
	} else {
		for (size_t i = 0; i < ft.size(); i++) {
			ft.at(i) == std.at(i) ? printTestResult(OK) : printTestResult(KO);
		}
	}
	std::cout << std::endl;
}

#endif
