/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/09 17:46:29 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sys/time.h>
#include <vector>
#include "vector.hpp"

template <typename T>
void printVectorInfo(NAMESPACE::vector<T> &vector) {
	std::cout << "--------------------------------------------------" << std::endl << std::boolalpha
	          << "vector::empty() = " << vector.empty() << std::endl
	          << "vector::size() = " << vector.size() << std::endl
	          << "vector::max_size() = " << vector.max_size() << std::endl
	          << "Contents:" << std::endl;
	for (size_t i = 0; i < vector.size(); i++) {
		std::cout << vector[i] << std::endl;
	}
}

static void defaultConstructor();
static void fillConstructor();

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	defaultConstructor();
	fillConstructor();

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

static void defaultConstructor() {
	NAMESPACE::vector<int> test_char;
	printVectorInfo(test_char);
	NAMESPACE::vector<int> test_int;
	printVectorInfo(test_int);
	NAMESPACE::vector<double> test_double;
	printVectorInfo(test_double);
	NAMESPACE::vector<std::string> test_string;
	printVectorInfo(test_string);
}

static void fillConstructor() {
	NAMESPACE::vector<char> test_char_1(0, 97);
	printVectorInfo(test_char_1);
	NAMESPACE::vector<char> test_char_2(10, CHAR_MAX);
	printVectorInfo(test_char_2);
	NAMESPACE::vector<char> test_char_3(10, 0);
	printVectorInfo(test_char_3);
	try {
		NAMESPACE::vector<char> test_char_4(-5, 97);
		printVectorInfo(test_char_4);
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}

	NAMESPACE::vector<double> test_double_1(0, 97.9797);
	printVectorInfo(test_double_1);
	NAMESPACE::vector<double> test_double_2(10, DBL_MIN);
	printVectorInfo(test_double_2);
	NAMESPACE::vector<double> test_double_3(10, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
	printVectorInfo(test_double_3);
	try {
		NAMESPACE::vector<double> test_double_4(-5, DBL_MAX);
		printVectorInfo(test_double_4);
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}

	NAMESPACE::vector<std::string> test_string_1(0, "Hello World!");
	printVectorInfo(test_string_1);
	NAMESPACE::vector<std::string> test_string_2(10, "Hello World!");
	printVectorInfo(test_string_2);
	try {
		NAMESPACE::vector<std::string> test_string_3(-42, "Hello World!");
		printVectorInfo(test_string_3);
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}
}
