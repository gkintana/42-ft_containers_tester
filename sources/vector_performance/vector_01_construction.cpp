/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_01_construction.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:24:17 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/12 23:41:56 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>
#include <chrono>

// https://stackoverflow.com/questions/876901/calculating-execution-time-in-c
// https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
int main() {
	using std::chrono::high_resolution_clock;
    using std::chrono::duration;
	auto start = high_resolution_clock::now();


	std::srand(time(NULL));
	// Default Constructor Tests
	{
		NAMESPACE::vector<char> vec_char;
		NAMESPACE::vector<int> vec_int;
		NAMESPACE::vector<long> vec_long;
		NAMESPACE::vector<size_t> vec_sizet;
		NAMESPACE::vector<float> vec_float;
		NAMESPACE::vector<double> vec_double;
		NAMESPACE::vector<std::string> vec_string;
	}


	// Fill Constructor Tests
	{
		NAMESPACE::vector<char> vec_char_1(0, 97);
		NAMESPACE::vector<char> vec_char_2(10, CHAR_MIN);
		NAMESPACE::vector<char> vec_char_3(10, 0);
		NAMESPACE::vector<char> vec_char_4(10, CHAR_MAX);
		try {
			NAMESPACE::vector<int> vec_char(-5, 42);
		} catch (std::exception &e) {}

		NAMESPACE::vector<int> vec_int_1(0, 42);
		NAMESPACE::vector<int> vec_int_2(10, INT_MIN);
		NAMESPACE::vector<int> vec_int_3(10, 0);
		NAMESPACE::vector<int> vec_int_4(10, INT_MAX);
		try {
			NAMESPACE::vector<int> vec_int(-5, 42);
		} catch (std::exception &e) {}

		NAMESPACE::vector<long> vec_long_1(0, 42);
		NAMESPACE::vector<long> vec_long_2(10, LONG_MIN);
		NAMESPACE::vector<long> vec_long_3(10, 0);
		NAMESPACE::vector<long> vec_long_4(10, LONG_MAX);
		try {
			NAMESPACE::vector<long> vec_long(-5, 42);
		} catch (std::exception &e) {}

		NAMESPACE::vector<size_t> vec_sizet_1(0, 42);
		NAMESPACE::vector<size_t> vec_sizet_2(10, 0);
		#if __APPLE__
			NAMESPACE::vector<size_t> vec_sizet_3(10, SIZE_MAX);
		#endif
		try {
			NAMESPACE::vector<size_t> vec_sizet(-5, 42);
		} catch (std::exception &e) {}

		NAMESPACE::vector<float> vec_float_1(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		NAMESPACE::vector<float> vec_float_2(10, FLT_MIN);
		NAMESPACE::vector<float> vec_float_3(10, 0);
		NAMESPACE::vector<float> vec_float_4(10, FLT_MAX);
		try {
			NAMESPACE::vector<float> vec_float(-5, 42.123123123f);
		} catch (std::exception &e) {}

		NAMESPACE::vector<double> vec_double_1(0, 42424242424242424242.123123123123123123123123123123123123123123123123);
		NAMESPACE::vector<double> vec_double_2(10, DBL_MIN);
		NAMESPACE::vector<double> vec_double_3(10, 0);
		NAMESPACE::vector<double> vec_double_4(10, DBL_MAX);
		try {
			NAMESPACE::vector<double> vec_double(-5, 42.123123123);
		} catch (std::exception &e) {}
	}


	// Range Constructor Tests
	{
		size_t size = 21, value = 42;
		NAMESPACE::vector<int> vec(size, value);

		NAMESPACE::vector<int> vec_range_1(vec.begin(), vec.end());
		NAMESPACE::vector<int> vec_range_2(vec.begin() + (vec.size() / 4), vec.end() - (vec.size() / 4));
		try {
			NAMESPACE::vector<int> vec_range(vec.begin() + (size * 42), vec.end() - (size * 42));
		} catch (std::exception &e) {}
		try {
			NAMESPACE::vector<int> vec_range(vec.rend(), vec.rbegin());
		} catch (std::exception &e) {}
	}
	{
		char array[] = { 0, 32, 48, 57, 97, 122 };
		NAMESPACE::vector<char> vec_char(array, array + (sizeof(array) / sizeof(char)));
	}
	{
		int array[] = { 12, 34, 56, 78, 90, 123, 456, 789, 12345, 67890 };
		NAMESPACE::vector<int> vec_int(array, array + (sizeof(array) / sizeof(int)));
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		NAMESPACE::vector<std::string> vec_str(array, array + (sizeof(array) / sizeof(std::string)));
	}


	// Copy Constructor Tests
	{
		NAMESPACE::vector<int> vec(10, 42);
		NAMESPACE::vector<int> vec_copy_1(vec);
		NAMESPACE::vector<int> vec_copy_2 = vec;
		NAMESPACE::vector<int> vec_copy_3;
		vec_copy_3 = vec;

		NAMESPACE::vector<int> vec_2(10, INT_MAX);
		NAMESPACE::vector<int> vec_copy(vec_2);
		vec_2 = vec_copy;
	}


	// Get Allocator Tests
	{
		size_t vector_size = 42;
		NAMESPACE::vector<int> vec;

		int *ptr = vec.get_allocator().allocate(vector_size);
		for (size_t i = 0; i < vector_size; i++) {
			vec.get_allocator().construct(ptr + i, RNG);
		}
		for (size_t i = 0; i < vector_size; i++) {
			vec.get_allocator().destroy(ptr + i);
		}
		vec.get_allocator().deallocate(ptr, vector_size);
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		size_t vector_size = sizeof(array) / sizeof(std::string);
		NAMESPACE::vector<std::string> vec;

		std::string *ptr = vec.get_allocator().allocate(vector_size);
		for (size_t i = 0; i < vector_size; i++) {
			vec.get_allocator().construct(ptr + i, *(array + i));
		}
		for (size_t i = 0; i < vector_size; i++) {
			vec.get_allocator().destroy(ptr + i);
		}
		vec.get_allocator().deallocate(ptr, vector_size);
	}


	auto end = high_resolution_clock::now();
	duration<double, std::milli> ms_double = end - start;
	std::cout << std::setprecision(3) << ms_double.count() << " ms" << std::endl;
}
