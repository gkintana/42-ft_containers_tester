/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_construction.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/31 22:09:09 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cfloat>
// #include <cstring>
#include <vector>
#include <vector.hpp>
#include <limits.h>

#define DEFAULT    "\033[0m"
#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[1;33m"
#define PURPLE     "\033[0;35m"
#define CYAN       "\033[0;36m"

template < class FT, class STD >
void checkEmpty(ft::vector<FT> &ft, std::vector<STD> &std) {
	if (ft.empty() == std.empty()) {
		std::cout << GREEN "[OK] " DEFAULT;
	} else {
		std::cout << RED "[KO] " DEFAULT;
	}
}

template < class FT, class STD >
void checkSize(ft::vector<FT> &ft, std::vector<STD> &std) {
	if (ft.size() == std.size()) {
		std::cout << GREEN "[OK] " DEFAULT;
	} else {
		std::cout << RED "[KO] " DEFAULT;
	}
}

template < class FT, class STD >
void checkCapacity(ft::vector<FT> &ft, std::vector<STD> &std) {
	if (ft.capacity() == std.capacity()) {
		std::cout << GREEN "[OK] " DEFAULT;
	} else {
		std::cout << YELLOW "[WARNING] " DEFAULT;
	}
}

#if __APPLE__
template < class FT, class STD >
void checkMaxSize(ft::vector<FT> &ft, std::vector<STD> &std) {
	if (ft.max_size() == ULONG_MAX && std.max_size() == LONG_MAX) {
		std::cout << GREEN "[OK] " DEFAULT;
	} else if (ft.max_size() == std.max_size()) {
		std::cout << GREEN "[OK] " DEFAULT;
	} else {
		std::cout << YELLOW "[KO] " DEFAULT;
	}
}
#endif

#if __linux__
template < class FT, class STD >
void checkMaxSize(ft::vector<FT> &ft, std::vector<STD> &std) {
	if (ft.max_size() == std.max_size()) {
		std::cout << GREEN "[OK] " DEFAULT;
	} else {
		std::cout << RED "[KO] " DEFAULT;
	}
}
#endif

template < class T >
void checkContent(ft::vector<T> &ft, std::vector<T> &std) {
	std::stringstream ft_ss, std_ss;
	for (size_t i = 0; i < ft.size(); i++) {
		ft_ss << ft[i] << " ";
		std_ss << std[i] << " ";
	}

	if (ft_ss.str() == std_ss.str()) {
		std::cout << GREEN "[OK] " DEFAULT;
	} else {
		std::cout << RED "[KO] " DEFAULT;
	}
}

template < class T >
void testVectors(ft::vector<T> &lhs, ft::vector<T> &rhs) {
	checkContent(lhs, rhs);
	checkEmpty(lhs, rhs);
	checkSize(lhs, rhs);
	checkCapacity(lhs, rhs);
	checkMaxSize(lhs, rhs);
}

template < class T >
void testVectors(ft::vector<T> &ft, std::vector<T> &std) {
	checkContent(ft, std);
	checkEmpty(ft, std);
	checkSize(ft, std);
	checkCapacity(ft, std);
	checkMaxSize(ft, std);
}



int main() {
	std::cout << "Default Constructor Tests: ";
	// empty char vector
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		testVectors(ft_vec, std_vec);
	}
	// empty int vector
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		testVectors(ft_vec, std_vec);
	}
	// empty long vector
	{
		ft::vector<long> ft_vec;
		std::vector<long> std_vec;
		testVectors(ft_vec, std_vec);
	}
	// empty size_t vector
	{
		ft::vector<size_t> ft_vec;
		std::vector<size_t> std_vec;
		testVectors(ft_vec, std_vec);
	}
	// empty float vector
	{
		ft::vector<float> ft_vec;
		std::vector<float> std_vec;
		testVectors(ft_vec, std_vec);
	}
	// empty double vector
	{
		ft::vector<double> ft_vec;
		std::vector<double> std_vec;
		testVectors(ft_vec, std_vec);
	}
	// empty string vector
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		testVectors(ft_vec, std_vec);
	}
	std::cout << std::endl;

	/*------------------------------------------------------------------------*/

	std::cout << "Fill Constructor Tests: ";
	// char vector tests
	{
		ft::vector<char> ft_vec(0, 97);
		std::vector<char> std_vec(0, 97);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<char> ft_vec(21, 97);
		std::vector<char> std_vec(21, 97);
		testVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<char> ft_vec(-5, 97);
			std::vector<char> std_vec(-5, 97);
			std::cout << RED "[KO] " DEFAULT;
		} catch (std::exception &e) {
			std::cout << GREEN "[OK] " DEFAULT;
		}
	}
	// int vector tests
	{
		ft::vector<int> ft_vec(0, 42);
		std::vector<int> std_vec(0, 42);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(10, INT_MIN);
		std::vector<int> std_vec(10, INT_MIN);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(10, 0);
		std::vector<int> std_vec(10, 0);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(10, INT_MAX);
		std::vector<int> std_vec(10, INT_MAX);
		testVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<int> ft_vec(-5, 42);
			std::vector<int> std_vec(-5, 42);
			std::cout << RED "[KO] " DEFAULT;
		} catch (std::exception &e) {
			std::cout << GREEN "[OK] " DEFAULT;
		}
	}
	// long vector tests
	{
		ft::vector<long> ft_vec(0, 42);
		std::vector<long> std_vec(0, 42);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MIN);
		std::vector<long> std_vec(10, LONG_MIN);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<long> ft_vec(10, 0);
		std::vector<long> std_vec(10, 0);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MAX);
		std::vector<long> std_vec(10, LONG_MAX);
		testVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<long> ft_vec(-5, 42);
			std::vector<long> std_vec(-5, 42);
			std::cout << RED "[KO] " DEFAULT;
		} catch (std::exception &e) {
			std::cout << GREEN "[OK] " DEFAULT;
		}
	}
	// size_t vector tests
	{
		ft::vector<size_t> ft_vec(0, 42);
		std::vector<size_t> std_vec(0, 42);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<size_t> ft_vec(21, 42);
		std::vector<size_t> std_vec(21, 42);
		testVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<size_t> ft_vec(-5, 42);
			std::vector<size_t> std_vec(-5, 42);
			std::cout << RED "[KO] " DEFAULT;
		} catch (std::exception &e) {
			std::cout << GREEN "[OK] " DEFAULT;
		}
	}
	// float vector tests
	{
		ft::vector<float> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		std::vector<float> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MIN);
		std::vector<float> std_vec(10, FLT_MIN);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<float> ft_vec(10, 0);
		std::vector<float> std_vec(10, 0);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MAX);
		std::vector<float> std_vec(10, FLT_MAX);
		testVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<float> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
			std::vector<float> std_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
			std::cout << RED "[KO] " DEFAULT;
		} catch (std::exception &e) {
			std::cout << GREEN "[OK] " DEFAULT;
		}
	}
	// double vector tests
	{
		ft::vector<double> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		std::vector<double> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MIN);
		std::vector<double> std_vec(10, DBL_MIN);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<double> ft_vec(10, 0);
		std::vector<double> std_vec(10, 0);
		testVectors(ft_vec, std_vec);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MAX);
		std::vector<double> std_vec(10, DBL_MAX);
		testVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<double> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
			std::vector<double> std_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
			std::cout << RED "[KO] " DEFAULT;
		} catch (std::exception &e) {
			std::cout << GREEN "[OK] " DEFAULT;
		}
	}
	std::cout << std::endl;
	

	/*------------------------------------------------------------------------*/

	std::cout << "Range Constructor Tests: ";
	{

	}
	std::cout << std::endl;

	/*------------------------------------------------------------------------*/

	std::cout << "Copy Constructor Tests: ";
	
	// int vector tests
	{
		// ft::vector<int> ft_vec(10, INT_MAX);
		// std::vector<int> std_vec(10, INT_MAX);

		// ft::vector<int> ft_copy1(ft_vec);
		// testVectors(ft_vec, ft_copy1);

		// ft::vector<int> ft_copy2(ft_copy1);
		// ft_copy1 = ft_copy2;		
	}
	std::cout << std::endl;

	return 0;
}
