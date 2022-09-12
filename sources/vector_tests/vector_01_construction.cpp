/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_01_construction.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/12 23:09:23 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

static void defaultTests();
static void fillTests();
static void rangeTests();
static void copyTests();
static void getAllocTests();

int main() {
	srand(time(NULL));

	std::cout << PURPLE "Default Constructor Tests" DEFAULT << std::endl;
	defaultTests();

	std::cout << PURPLE "Fill Constructor Tests" DEFAULT << std::endl;
	fillTests();

	std::cout << PURPLE "Range Constructor Tests" DEFAULT << std::endl;
	rangeTests();

	std::cout << PURPLE "Copy Constructor Tests" DEFAULT << std::endl;
	copyTests();

	std::cout << PURPLE "Get Allocator Tests" DEFAULT << std::endl;
	getAllocTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void defaultTests() {
	vectorTester test;

	// Empty Character Vector Tests
	{
		ft::vector<char> ft;
		std::vector<char> std;
		test.compareVectors(ft, std);
		test.printTestResults("Empty Char Vector");
	}

	// Empty Int Vector Tests
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.compareVectors(ft, std);
		test.printTestResults("Empty Int Vector");
	}

	// Empty Long Vector Tests
	{
		ft::vector<long> ft;
		std::vector<long> std;
		test.compareVectors(ft, std);
		test.printTestResults("Empty Long Vector");
	}

	// Empty Size_t Vector Tests
	{
		ft::vector<size_t> ft;
		std::vector<size_t> std;
		test.compareVectors(ft, std);
		test.printTestResults("Empty Size_t Vector");
	}

	// Empty Float Vector Tests
	{
		ft::vector<float> ft;
		std::vector<float> std;
		test.compareVectors(ft, std);
		test.printTestResults("Empty Float Vector");
	}

	// Empty Double Vector Tests
	{
		ft::vector<double> ft;
		std::vector<double> std;
		test.compareVectors(ft, std);
		test.printTestResults("Empty Double Vector");
	}

	// Empty String Vector Tests
	{
		ft::vector<std::string> ft;
		std::vector<std::string> std;
		test.compareVectors(ft, std);
		test.printTestResults("Empty String Vector");
	}
}

static void fillTests() {
	vectorTester test;

	// Char Vector Fill Constructor Tests
	{
		ft::vector<char> ft(0, 97);
		std::vector<char> std(0, 97);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<char> ft(10, CHAR_MIN);
		std::vector<char> std(10, CHAR_MIN);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<char> ft(10, 0);
		std::vector<char> std(10, 0);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<char> ft(10, CHAR_MAX);
		std::vector<char> std(10, CHAR_MAX);
		test.compareVectors(ft, std);
	}
	{
		try {
			ft::vector<char> ft(-5, 97);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Char Vector ");
	}

	// Int Vector Fill Constructor Tests
	{
		ft::vector<int> ft(0, 42);
		std::vector<int> std(0, 42);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<int> ft(10, INT_MIN);
		std::vector<int> std(10, INT_MIN);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<int> ft(10, 0);
		std::vector<int> std(10, 0);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<int> ft(10, INT_MAX);
		std::vector<int> std(10, INT_MAX);
		test.compareVectors(ft, std);
	}
	{
		try {
			ft::vector<int> ft(-5, 42);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Int Vector  ");
	}

	// Long Vector Fill Constructor Tests
	{
		ft::vector<long> ft(0, 42);
		std::vector<long> std(0, 42);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<long> ft(10, LONG_MIN);
		std::vector<long> std(10, LONG_MIN);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<long> ft(10, 0);
		std::vector<long> std(10, 0);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<long> ft(10, LONG_MAX);
		std::vector<long> std(10, LONG_MAX);
		test.compareVectors(ft, std);
	}
	{
		try {
			ft::vector<long> ft(-5, 42);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Long Vector ");
	}

	// Size_t Vector Fill Constructor Tests
	{
		ft::vector<size_t> ft(0, 42);
		std::vector<size_t> std(0, 42);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<size_t> ft(21, 0);
		std::vector<size_t> std(21, 0);
		test.compareVectors(ft, std);
	}
	#if __APPLE__
	{
		ft::vector<size_t> ft(21, SIZE_MAX);
		std::vector<size_t> std(21, SIZE_MAX);
		test.compareVectors(ft, std);
	}
	#endif
	{
		try {
			ft::vector<size_t> ft(-5, 42);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Size_t Vector");
	}

	// Float Vector Fill Constructor Tests
	{
		ft::vector<float> ft(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		std::vector<float> std(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<float> ft(10, FLT_MIN);
		std::vector<float> std(10, FLT_MIN);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<float> ft(10, 0);
		std::vector<float> std(10, 0);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<float> ft(10, FLT_MAX);
		std::vector<float> std(10, FLT_MAX);
		test.compareVectors(ft, std);
	}
	{
		try {
			ft::vector<float> ft(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Float Vector");
	}

	// Double Vector Fill Constructor Tests
	{
		ft::vector<double> ft(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		std::vector<double> std(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<double> ft(10, DBL_MIN);
		std::vector<double> std(10, DBL_MIN);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<double> ft(10, 0);
		std::vector<double> std(10, 0);
		test.compareVectors(ft, std);
	}
	{
		ft::vector<double> ft(10, DBL_MAX);
		std::vector<double> std(10, DBL_MAX);
		test.compareVectors(ft, std);
	}
	{
		try {
			ft::vector<double> ft(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Double Vector");
	}
}

static void rangeTests() {
	vectorTester test;

	size_t size = 21,
			value = 42;
	ft::vector<int> ft(size, value);
	std::vector<int> std(size, value);

	{
		ft::vector<int> ft_range(ft.begin(), ft.end());
		test.compareVectors(ft, ft_range);
		std::vector<int> std_range(std.begin(), std.end());
		test.compareVectors(ft_range, std_range);
	}
	{
		ft::vector<int> ft_range(ft.begin() + (ft.size() / 4), ft.end() - (ft.size() / 4));
		std::vector<int> std_range(std.begin() + (std.size() / 4), std.end() - (std.size() / 4));
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
		** ft::vector<int> ft_range(ft.begin(), ft.end() + 42);
		** ft::vector<int> ft_range(ft.begin() - (size * 42), ft.end() + (size * 42));
		*/
		try {
			ft::vector<int> ft_range(ft.begin() + (size * 42), ft.end() - (size * 42));
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}

		try {
			ft::vector<int> ft_range(ft.rend(), ft.rbegin());
			test.addKO();
		} catch (std::exception &e) {
			test.addOK();
		}
		test.printTestResults("Error Cases ");
		// compareVectors(ft, ft_range, false);
		// ft::vector<int> ft_range(ft.rbegin(), ft.rend());

		// std::vector<int> std_range(std.rbegin(), std.rend());
		// std::vector<int> std_range(std.rend(), std.rbegin());
		// compareVectors(ft_range, std_range, true);
	}

	{
		char array[] = { 0, 32, 48, 57, 97, 122 };

		ft::vector<char> ft(array, array + (sizeof(array) / sizeof(char)));
		std::vector<char> std(array, array + (sizeof(array) / sizeof(char)));
		test.compareVectors(ft, std);
		test.printTestResults("Character Array");
	}

	{
		int array[] = { 12, 34, 56, 78, 90, 123, 456, 789, 12345, 67890 };

		ft::vector<int> ft(array, array + (sizeof(array) / sizeof(int)));
		std::vector<int> std(array, array + (sizeof(array) / sizeof(int)));
		test.compareVectors(ft, std);
		test.printTestResults("Int Array    ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));
		test.compareVectors(ft, std);
		test.printTestResults("String Array");
	}
}

static void copyTests() {
	vectorTester test;

	test.resetTestCount();
	{
		ft::vector<int> ft(10, 42);
		std::vector<int> std(10, 42);

		ft::vector<int> ft_copy1(ft);
		std::vector<int> std_copy1(std);
		test.compareVectors(ft_copy1, std_copy1);

		ft::vector<int> ft_copy2 = ft;
		std::vector<int> std_copy2 = std;
		test.compareVectors(ft_copy2, std_copy2);
		test.printTestResults("Copy Constructor");
	}

	test.resetTestCount();
	{
		ft::vector<int> ft(10, 42);
		std::vector<int> std(10, 42);

		ft::vector<int> ft_copy;
		ft_copy = ft;
		std::vector<int> std_copy;
		std_copy = std;
		test.compareVectors(ft_copy, std_copy);
		test.printTestResults("Copy Assignment");
	}

	test.resetTestCount();
	{
		ft::vector<int> ft(10, INT_MAX);
		ft::vector<int> ft_copy(ft);
		test.compareVectors(ft, ft_copy);
		ft = ft_copy;
		test.compareVectors(ft, ft_copy);

		std::vector<int> std(10, INT_MAX);
		std::vector<int> std_copy(std);
		std = std_copy;
		test.compareVectors(ft, std);
		test.printTestResults("Self Assignment");
	}
}

static void getAllocTests() {
	vectorTester test;
	{
		size_t vector_size = 42;
		ft::vector<int> ft;
		std::vector<int> std;

		int *ft_ptr = ft.get_allocator().allocate(vector_size);
		int *std_ptr = std.get_allocator().allocate(vector_size);
		test.compareVectors(ft, std);

		for (size_t i = 0; i < vector_size; i++) {
			size_t random_value = RNG;
			ft.get_allocator().construct(ft_ptr + i, random_value);
			std.get_allocator().construct(std_ptr + i, random_value);
			test.compareVectors(ft, std);
		}

		for (size_t i = 0; i < vector_size; i++) {
			ft.get_allocator().destroy(ft_ptr + i);
			std.get_allocator().destroy(std_ptr + i);
			test.compareVectors(ft, std);
		}

		ft.get_allocator().deallocate(ft_ptr, vector_size);
		std.get_allocator().deallocate(std_ptr, vector_size);
		test.compareVectors(ft, std);

		test.printTestResults("Int Vector   ");
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		size_t vector_size = sizeof(array) / sizeof(std::string);
		ft::vector<std::string> ft;
		std::vector<std::string> std;

		std::string *ft_ptr = ft.get_allocator().allocate(vector_size);
		std::string *std_ptr = std.get_allocator().allocate(vector_size);
		test.compareVectors(ft, std);

		for (size_t i = 0; i < vector_size; i++) {
			ft.get_allocator().construct(ft_ptr + i, *(array + i));
			std.get_allocator().construct(std_ptr + i, *(array + i));
			test.compareVectors(ft, std);
		}

		for (size_t i = 0; i < vector_size; i++) {
			ft.get_allocator().destroy(ft_ptr + i);
			std.get_allocator().destroy(std_ptr + i);
			test.compareVectors(ft, std);
		}

		ft.get_allocator().deallocate(ft_ptr, vector_size);
		std.get_allocator().deallocate(std_ptr, vector_size);
		test.compareVectors(ft, std);

		test.printTestResults("String Vector");
	}
}
