/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_01_construction.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/03 22:55:00 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

static void defaultTests();
static void fillTests();
static void rangeTests();
static void copyTests();

int main() {
	std::cout << PURPLE "Default Constructor Tests" DEFAULT << std::endl;
	defaultTests();

	std::cout << PURPLE "Fill Constructor Tests" DEFAULT << std::endl;
	fillTests();

	std::cout << PURPLE "Range Constructor Tests" DEFAULT << std::endl;
	rangeTests();

	std::cout << PURPLE "Copy Constructor Tests" DEFAULT << std::endl;
	copyTests();

	return 0;
}

static void defaultTests() {
	resetTestCount();
	std::cout << "Empty Char Vector: ";
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "Empty Int Vector: ";
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "Empty Long Vector: ";
	{
		ft::vector<long> ft_vec;
		std::vector<long> std_vec;
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "Empty Size_t Vector: ";
	{
		ft::vector<size_t> ft_vec;
		std::vector<size_t> std_vec;
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "Empty Float Vector: ";
	{
		ft::vector<float> ft_vec;
		std::vector<float> std_vec;
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "Empty Double Vector: ";
	{
		ft::vector<double> ft_vec;
		std::vector<double> std_vec;
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "Empty String Vector: ";
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		testVectors(ft_vec, std_vec, true);
	}
}

static void fillTests() {
	resetTestCount();
	std::cout << "Char Vector: ";
	{
		ft::vector<char> ft_vec(0, 97);
		std::vector<char> std_vec(0, 97);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<char> ft_vec(21, 97);
		std::vector<char> std_vec(21, 97);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<char> ft_vec(-5, 97);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<char> std_vec(-5, 97);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	resetTestCount();
	std::cout << "Int Vector: ";
	{
		ft::vector<int> ft_vec(0, 42);
		std::vector<int> std_vec(0, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<int> ft_vec(10, INT_MIN);
		std::vector<int> std_vec(10, INT_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<int> ft_vec(10, 0);
		std::vector<int> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<int> ft_vec(10, INT_MAX);
		std::vector<int> std_vec(10, INT_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<int> ft_vec(-5, 42);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<int> std_vec(-5, 42);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	resetTestCount();
	std::cout << "Long Vector: ";
	{
		ft::vector<long> ft_vec(0, 42);
		std::vector<long> std_vec(0, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MIN);
		std::vector<long> std_vec(10, LONG_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<long> ft_vec(10, 0);
		std::vector<long> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MAX);
		std::vector<long> std_vec(10, LONG_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<long> ft_vec(-5, 42);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<long> std_vec(-5, 42);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	resetTestCount();
	std::cout << "Size_t Vector: ";
	{
		ft::vector<size_t> ft_vec(0, 42);
		std::vector<size_t> std_vec(0, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<size_t> ft_vec(21, 42);
		std::vector<size_t> std_vec(21, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<size_t> ft_vec(-5, 42);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<size_t> std_vec(-5, 42);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	resetTestCount();
	std::cout << "Float Vector: ";
	{
		ft::vector<float> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		std::vector<float> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MIN);
		std::vector<float> std_vec(10, FLT_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<float> ft_vec(10, 0);
		std::vector<float> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MAX);
		std::vector<float> std_vec(10, FLT_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<float> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<float> std_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	resetTestCount();
	std::cout << "Double Vector: ";
	{
		ft::vector<double> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		std::vector<double> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MIN);
		std::vector<double> std_vec(10, DBL_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<double> ft_vec(10, 0);
		std::vector<double> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MAX);
		std::vector<double> std_vec(10, DBL_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<double> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<double> std_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}
}

static void rangeTests() {
	resetTestCount();
	std::cout << "Begin to End: ";

	size_t size = 21,
	       value = 42;

	ft::vector<int> ft_vec(size, value);
	std::vector<int> std_vec(size, value);
	{
		ft::vector<int> ft_range(ft_vec.begin(), ft_vec.end());
		testVectors(ft_vec, ft_range, false);

		std::vector<int> std_range(std_vec.begin(), std_vec.end());
		testVectors(ft_range, std_range, false);
	}
	{
		ft::vector<int> ft_range(ft_vec.begin() + 3, ft_vec.end() - 3);
		std::vector<int> std_range(std_vec.begin() + 3, std_vec.end() - 3);
		testVectors(ft_range, std_range, true);
	}

	resetTestCount();
	std::cout << "Error Cases: ";
	{
		/**
		** the following cases will cause a lot of invalid reads but do
		** not throw errors nor lead to a segmentation fault
		**
		** REMINDER: try to create a separate tester for these cases:
		**
		** ft::vector<int> ft_range(ft_vec.begin(), ft_vec.end() + 42);
		** ft::vector<int> ft_range(ft_vec.begin() - (size * 42), ft_vec.end() + (size * 42));
		*/

		try {
			ft::vector<int> ft_range(ft_vec.begin() + (size * 42), ft_vec.end() - (size * 42));
			std::cout << test_no++ << "." RED "KO " DEFAULT;
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT;
		}
	
		try {
			ft::vector<int> ft_range(ft_vec.rend(), ft_vec.rbegin());
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
		// testVectors(ft_vec, ft_range, false);
		// ft::vector<int> ft_range(ft_vec.rbegin(), ft_vec.rend());

		// std::vector<int> std_range(std_vec.rbegin(), std_vec.rend());
		// std::vector<int> std_range(std_vec.rend(), std_vec.rbegin());
		// testVectors(ft_range, std_range, true);
	}

	resetTestCount();
	std::cout << "Character Array to Vector: ";
	{
		char array[] = { 0, 32, 48, 57, 97, 122 };

		ft::vector<char> ft_vec(array, array + (sizeof(array) / sizeof(char)));
		std::vector<char> std_vec(array, array + (sizeof(array) / sizeof(char)));
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "Int Array to Vector: ";
	{
		int array[] = { 12, 34, 56, 78, 90, 123, 456, 789, 12345, 67890 };

		ft::vector<int> ft_vec(array, array + (sizeof(array) / sizeof(int)));
		std::vector<int> std_vec(array, array + (sizeof(array) / sizeof(int)));
		testVectors(ft_vec, std_vec, true);
	}

	resetTestCount();
	std::cout << "String Array to Vector: ";
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

		ft::vector<std::string> ft_vec(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_vec(array, array + (sizeof(array) / sizeof(std::string)));
		testVectors(ft_vec, std_vec, true);
	}
}

static void copyTests() {
	resetTestCount();
	std::cout << "Copy Constructor: ";
	{
		ft::vector<int> ft_vec(10, 42);
		std::vector<int> std_vec(10, 42);

		ft::vector<int> ft_copy1(ft_vec);
		std::vector<int> std_copy1(std_vec);
		testVectors(ft_copy1, std_copy1, false);

		ft::vector<int> ft_copy2 = ft_vec;
		std::vector<int> std_copy2 = std_vec;
		testVectors(ft_copy2, std_copy2, true);
	}

	resetTestCount();
	std::cout << "Copy Assignment: ";
	{
		ft::vector<int> ft_vec(10, 42);
		std::vector<int> std_vec(10, 42);

		ft::vector<int> ft_copy;
		ft_copy = ft_vec;
		std::vector<int> std_copy;
		std_copy = std_vec;
		testVectors(ft_copy, std_copy, true);
	}

	resetTestCount();
	std::cout << "Self-Assignment: ";
	{
		ft::vector<int> ft_vec(10, INT_MAX);
		ft::vector<int> ft_copy(ft_vec);
		testVectors(ft_vec, ft_copy, false);
		ft_vec = ft_copy;
		testVectors(ft_vec, ft_copy, false);

		std::vector<int> std_vec(10, INT_MAX);
		std::vector<int> std_copy(std_vec);
		std_vec = std_copy;
		testVectors(ft_vec, std_vec, true);
	}
}
