/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_01_construction.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/07 19:25:46 by gkintana         ###   ########.fr       */
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
	vectorTester test;

	// Empty Character Vector Tests
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Empty Char Vector");
	}

	// Empty Int Vector Tests
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Empty Int Vector");
	}

	// Empty Long Vector Tests
	{
		ft::vector<long> ft_vec;
		std::vector<long> std_vec;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Empty Long Vector");
	}

	// Empty Size_t Vector Tests
	{
		ft::vector<size_t> ft_vec;
		std::vector<size_t> std_vec;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Empty Size_t Vector");
	}

	// Empty Float Vector Tests
	{
		ft::vector<float> ft_vec;
		std::vector<float> std_vec;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Empty Float Vector");
	}

	// Empty Double Vector Tests
	{
		ft::vector<double> ft_vec;
		std::vector<double> std_vec;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Empty Double Vector");
	}

	// Empty String Vector Tests
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Empty String Vector");
	}
}

static void fillTests() {
	vectorTester test;

	// Char Vector Fill Constructor Tests
	{
		ft::vector<char> ft_vec(0, 97);
		std::vector<char> std_vec(0, 97);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<char> ft_vec(10, CHAR_MIN);
		std::vector<char> std_vec(10, CHAR_MIN);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<char> ft_vec(10, 0);
		std::vector<char> std_vec(10, 0);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<char> ft_vec(10, CHAR_MAX);
		std::vector<char> std_vec(10, CHAR_MAX);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<char> ft_vec(-5, 97);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Char Vector ");
	}

	// Int Vector Fill Constructor Tests
	{
		ft::vector<int> ft_vec(0, 42);
		std::vector<int> std_vec(0, 42);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(10, INT_MIN);
		std::vector<int> std_vec(10, INT_MIN);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(10, 0);
		std::vector<int> std_vec(10, 0);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(10, INT_MAX);
		std::vector<int> std_vec(10, INT_MAX);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<int> ft_vec(-5, 42);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Int Vector  ");
	}

	// Long Vector Fill Constructor Tests
	{
		ft::vector<long> ft_vec(0, 42);
		std::vector<long> std_vec(0, 42);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MIN);
		std::vector<long> std_vec(10, LONG_MIN);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<long> ft_vec(10, 0);
		std::vector<long> std_vec(10, 0);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MAX);
		std::vector<long> std_vec(10, LONG_MAX);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<long> ft_vec(-5, 42);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Long Vector ");
	}

	// Size_t Vector Fill Constructor Tests
	{
		ft::vector<size_t> ft_vec(0, 42);
		std::vector<size_t> std_vec(0, 42);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<size_t> ft_vec(21, 0);
		std::vector<size_t> std_vec(21, 0);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<size_t> ft_vec(21, SIZE_MAX);
		std::vector<size_t> std_vec(21, SIZE_MAX);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<size_t> ft_vec(-5, 42);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Size_t Vector");
	}

	// Float Vector Fill Constructor Tests
	{
		ft::vector<float> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		std::vector<float> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MIN);
		std::vector<float> std_vec(10, FLT_MIN);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<float> ft_vec(10, 0);
		std::vector<float> std_vec(10, 0);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MAX);
		std::vector<float> std_vec(10, FLT_MAX);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<float> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Float Vector");
	}

	// Double Vector Fill Constructor Tests
	{
		ft::vector<double> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		std::vector<double> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MIN);
		std::vector<double> std_vec(10, DBL_MIN);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<double> ft_vec(10, 0);
		std::vector<double> std_vec(10, 0);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MAX);
		std::vector<double> std_vec(10, DBL_MAX);
		test.compareVectors(ft_vec, std_vec);
	}
	{
		try {
			ft::vector<double> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("String Vector");
	}
}

static void rangeTests() {
	vectorTester test;

	size_t size = 21,
			value = 42;
	ft::vector<int> ft_vec(size, value);
	std::vector<int> std_vec(size, value);

	{
		ft::vector<int> ft_range(ft_vec.begin(), ft_vec.end());
		test.compareVectors(ft_vec, ft_range);
		std::vector<int> std_range(std_vec.begin(), std_vec.end());
		test.compareVectors(ft_range, std_range);
	}
	{
		ft::vector<int> ft_range(ft_vec.begin() + (ft_vec.size() / 4), ft_vec.end() - (ft_vec.size() / 4));
		std::vector<int> std_range(std_vec.begin() + (std_vec.size() / 4), std_vec.end() - (std_vec.size() / 4));
		test.compareVectors(ft_range, std_range);
		test.printTestResults("Begin to End");
	}

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
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}

		try {
			ft::vector<int> ft_range(ft_vec.rend(), ft_vec.rbegin());
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Error Cases ");
		// compareVectors(ft_vec, ft_range, false);
		// ft::vector<int> ft_range(ft_vec.rbegin(), ft_vec.rend());

		// std::vector<int> std_range(std_vec.rbegin(), std_vec.rend());
		// std::vector<int> std_range(std_vec.rend(), std_vec.rbegin());
		// compareVectors(ft_range, std_range, true);
	}

	{
		char array[] = { 0, 32, 48, 57, 97, 122 };

		ft::vector<char> ft_vec(array, array + (sizeof(array) / sizeof(char)));
		std::vector<char> std_vec(array, array + (sizeof(array) / sizeof(char)));
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Character Array");
	}

	{
		int array[] = { 12, 34, 56, 78, 90, 123, 456, 789, 12345, 67890 };

		ft::vector<int> ft_vec(array, array + (sizeof(array) / sizeof(int)));
		std::vector<int> std_vec(array, array + (sizeof(array) / sizeof(int)));
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Int Array    ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

		ft::vector<std::string> ft_vec(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_vec(array, array + (sizeof(array) / sizeof(std::string)));
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("String Array");
	}
}

static void copyTests() {
	vectorTester test;

	test.resetTestCount();
	{
		ft::vector<int> ft_vec(10, 42);
		std::vector<int> std_vec(10, 42);

		ft::vector<int> ft_copy1(ft_vec);
		std::vector<int> std_copy1(std_vec);
		test.compareVectors(ft_copy1, std_copy1);

		ft::vector<int> ft_copy2 = ft_vec;
		std::vector<int> std_copy2 = std_vec;
		test.compareVectors(ft_copy2, std_copy2);
		test.printTestResults("Copy Constructor");
	}

	test.resetTestCount();
	{
		ft::vector<int> ft_vec(10, 42);
		std::vector<int> std_vec(10, 42);

		ft::vector<int> ft_copy;
		ft_copy = ft_vec;
		std::vector<int> std_copy;
		std_copy = std_vec;
		test.compareVectors(ft_copy, std_copy);
		test.printTestResults("Copy Assignment");
	}

	test.resetTestCount();
	{
		ft::vector<int> ft_vec(10, INT_MAX);
		ft::vector<int> ft_copy(ft_vec);
		test.compareVectors(ft_vec, ft_copy);
		ft_vec = ft_copy;
		test.compareVectors(ft_vec, ft_copy);

		std::vector<int> std_vec(10, INT_MAX);
		std::vector<int> std_copy(std_vec);
		std_vec = std_copy;
		test.compareVectors(ft_vec, std_vec);
		test.printTestResults("Self Assignment");
	}
}
