/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:12 by gkintana          #+#    #+#             */
/*   Updated: 2023/03/06 12:52:57 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

static void operatorTests();
static void atTests();
static void atExceptionTests();
static void frontTests();
static void backTests();

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	operatorTests();
	atTests();
	atExceptionTests();
	frontTests();
	backTests();

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing",
                        "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing",
                        "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

static void operatorTests() {
	std::cout << "--------------------------------------------------" << std::endl
	          << "vector::operator[] Tests" << std::endl;
	{
		NAMESPACE::vector<int> test;
		pushRandomValues(test, 42);
		printByOperator(test);

		test[0] = 0;
		test[test.size() - 1] = 123;
		test[test.size() / 2] = 456;
		test[test.size() / 3] = 789;
		test[test.size() / 4] = 123456789;
		test[test.size() / 5] = 987654321;
		printByOperator(test);
	}

	{
		NAMESPACE::vector<std::string> test(array, array + (sizeof(array) / sizeof(std::string)));
		printByOperator(test);

		test[0] = "The sun had set and so had his grades.";
		test[test.size() - 1] = "I admire your courage but I don't admire your singing ability.";
		test[test.size() / 2] = "The quick brown fox jumps over the lazy dog";
		test[test.size() / 3] = "Tom can't remember all his passwords, so he keeps them in a list disguised as phone numbers.";
		test[test.size() / 4] = "It's fascinating that you know all the planets.";
		test[test.size() / 5] = "Your reputation as an eccentric will rapidly grow in the neighborhood if you're seen walking a pet ostrich on a leash every morning.";
		printByOperator(test);
	}
}

static void atTests() {
	std::cout << "\n--------------------------------------------------" << std::endl
	          << "vector::at Tests" << std::endl;
	{
		NAMESPACE::vector<int> test;
		pushRandomValues(test, 42);
		printByOperator(test);

		test.at(0) = 0;
		test.at(test.size() - 1) = 123;
		test.at(test.size() / 2) = 456;
		test.at(test.size() / 3) = 789;
		test.at(test.size() / 4) = 123456789;
		test.at(test.size() / 5) = 987654321;
		printByOperator(test);
	}

	{
		NAMESPACE::vector<std::string> test(array, array + (sizeof(array) / sizeof(std::string)));
		printByOperator(test);

		test.at(0) = "The sun had set and so had his grades.";
		test.at(test.size() - 1) = "I admire your courage but I don't admire your singing ability.";
		test.at(test.size() / 2) = "The quick brown fox jumps over the lazy dog";
		test.at(test.size() / 3) = "Tom can't remember all his passwords, so he keeps them in a list disguised as phone numbers.";
		test.at(test.size() / 4) = "It's fascinating that you know all the planets.";
		test.at(test.size() / 5) = "Your reputation as an eccentric will rapidly grow in the neighborhood if you're seen walking a pet ostrich on a leash every morning.";
		printByOperator(test);
	}
}

static void atExceptionTests() {
	std::cout << "\n--------------------------------------------------" << std::endl
	          << "vector::at Exception Tests" << std::endl
	          << "--------------------------------------------------" << std::endl;
	NAMESPACE::vector<int> test;
	pushRandomValues(test, 100);

	atExceptionCheck(test, 0);
	atExceptionCheck(test, test.size());
	atExceptionCheck(test, test.size() / 2);
	atExceptionCheck(test, test.max_size());
	atExceptionCheck(test, test.max_size() / 2);
	atExceptionCheck(test, CHAR_BIT);
	atExceptionCheck(test, CHAR_MIN);
	atExceptionCheck(test, CHAR_MAX);
	atExceptionCheck(test, SCHAR_MIN);
	atExceptionCheck(test, SCHAR_MAX);
	atExceptionCheck(test, INT_MIN);
	atExceptionCheck(test, INT_MAX);
	atExceptionCheck(test, UINT_MAX);
	atExceptionCheck(test, SHRT_MIN);
	atExceptionCheck(test, SHRT_MAX);
	atExceptionCheck(test, USHRT_MAX);
	atExceptionCheck(test, LONG_MIN);
	atExceptionCheck(test, LONG_MAX);
	atExceptionCheck(test, ULONG_MAX);
	atExceptionCheck(test, std::rand());
}

static void frontTests() {
	std::cout << "\n--------------------------------------------------" << std::endl
	          << "vector::front Tests" << std::endl;
	NAMESPACE::vector<int> test;
	pushRandomValues(test, 10);
	printByOperator(test);

	std::cout << "vector.front() = " << test.front() << std::endl;
	test.front() = 1234567890;
	std::cout << "vector.front() = " << test.front() << std::endl;
	test.resize(1, 0);
	std::cout << "vector.front() = " << test.front() << std::endl;
	test.front() = 42;
	std::cout << "vector.front() = " << test.front() << std::endl;
	test.resize(5, 987654321);
	std::cout << "vector.front() = " << test.front() << std::endl;
	printByOperator(test);
}

static void backTests() {
	std::cout << "\n--------------------------------------------------" << std::endl
	          << "vector::back Tests" << std::endl;
	NAMESPACE::vector<int> test;
	pushRandomValues(test, 10);
	printByOperator(test);

	std::cout << "vector.back() = " << test.back() << std::endl;
	test.back() = 1234567890;
	std::cout << "vector.back() = " << test.back() << std::endl;
	test.resize(1, 0);
	std::cout << "vector.back() = " << test.back() << std::endl;
	test.back() = 42;
	std::cout << "vector.back() = " << test.back() << std::endl;
	test.resize(5, 987654321);
	std::cout << "vector.back() = " << test.back() << std::endl;
	printByOperator(test);
}
