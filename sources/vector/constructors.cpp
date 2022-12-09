/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/10 00:34:54 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

static void defaultConstructor();
static void fillConstructor();
static void rangeConstructor();
static void copyTests();

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	defaultConstructor();
	fillConstructor();
	rangeConstructor();
	copyTests();

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

static void defaultConstructor() {
	NAMESPACE::vector<int> test_char;
	printByOperator(test_char);

	NAMESPACE::vector<int> test_int;
	printByOperator(test_int);

	NAMESPACE::vector<double> test_double;
	printByOperator(test_double);

	NAMESPACE::vector<std::string> test_string;
	printByOperator(test_string);
}

static void fillConstructor() {
	NAMESPACE::vector<char> test_char_1(0, 97);
	printByOperator(test_char_1);
	NAMESPACE::vector<char> test_char_2(10, CHAR_MAX);
	printByOperator(test_char_2);
	NAMESPACE::vector<char> test_char_3(10, 0);
	printByOperator(test_char_3);
	try {
		NAMESPACE::vector<char> test_char_4(-5, 97);
		printByOperator(test_char_4);
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}

	NAMESPACE::vector<double> test_double_1(0, 97.9797);
	printByOperator(test_double_1);
	NAMESPACE::vector<double> test_double_2(10, DBL_MIN);
	printByOperator(test_double_2);
	NAMESPACE::vector<double> test_double_3(10, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
	printByOperator(test_double_3);
	try {
		NAMESPACE::vector<double> test_double_4(-5, DBL_MAX);
		printByOperator(test_double_4);
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}

	NAMESPACE::vector<std::string> test_string_1(0, "Hello World!");
	printByOperator(test_string_1);
	NAMESPACE::vector<std::string> test_string_2(10, "Hello World!");
	printByOperator(test_string_2);
	try {
		NAMESPACE::vector<std::string> test_string_3(-42, "Hello World!");
		printByOperator(test_string_3);
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}
}

static void rangeConstructor() {
	size_t size = 30,
	       value = 42;
	NAMESPACE::vector<int> test(size, value);
	printByOperator(test);

	{
		NAMESPACE::vector<int> range(test.begin(), test.end());
		printByOperator(range);
	}
	{
		NAMESPACE::vector<int> range(test.begin() + (test.size() / 4), test.end() - (test.size() / 4));
		printByOperator(range);
	}

	try {
		NAMESPACE::vector<int> range(test.begin() + (test.size() * 42), test.end() - (test.size() * 42));
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}
	try {
		NAMESPACE::vector<int> range(test.rend(), test.rbegin());
	} catch (std::exception &e) {
		std::cout << "Exception Caught" << std::endl;
	}

	{
		char array[] = { 0, 32, 48, 57, 97, 122 };
		NAMESPACE::vector<char> char_array(array, array + (sizeof(array) / sizeof(char)));
		printByOperator(char_array);
	}
	{
		int array[] = { 12, 34, 56, 78, 90, 123, 456, 789, 12345, 67890 };
		NAMESPACE::vector<int> int_array(array, array + (sizeof(array) / sizeof(int)));
		printByOperator(int_array);
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		NAMESPACE::vector<std::string> str_array(array, array + (sizeof(array) / sizeof(std::string)));
		printByOperator(str_array);
	}
}

static void copyTests() {
	size_t size = 30,
	       value = 42;

	// Copy Constructor
	NAMESPACE::vector<int> test(size, value);
	printByOperator(test);
	NAMESPACE::vector<int> copy_1(test);
	printByOperator(copy_1);
	NAMESPACE::vector<int> copy_2 = test;
	printByOperator(copy_2);

	// Copy Assignment
	NAMESPACE::vector<int> copy_3;
	copy_3 = test;
	printByOperator(copy_3);

	// Self Assignment
	size = 10;
	value = INT_MAX;
	NAMESPACE::vector<int> self(size, value);
	NAMESPACE::vector<int> copy(self);
	printByOperator(self);
	printByOperator(copy);
	self = copy;
	printByOperator(self);
}
