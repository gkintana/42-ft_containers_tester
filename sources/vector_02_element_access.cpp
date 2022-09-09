/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_02_element_access.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:12 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/09 20:51:33 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

#define FRONT    true
#define BACK     false

static void operatorTests();
static void atTests();
static void atExceptionTests();
static void frontTests();
static void backTests();
static void dataTests();

int main() {
	srand(time(NULL));

	std::cout << PURPLE "Operator[] Tests" DEFAULT << std::endl;
	operatorTests();

	std::cout << PURPLE "At Tests" DEFAULT << std::endl;
	atTests();

	std::cout << PURPLE "At Exception Tests" DEFAULT << std::endl;
	atExceptionTests();

	std::cout << PURPLE "Front Tests" DEFAULT << std::endl;
	frontTests();

	std::cout << PURPLE "Back Tests" DEFAULT << std::endl;
	backTests();

	std::cout << PURPLE "Data Tests" DEFAULT << std::endl;
	dataTests();

	return 0;
}

static void operatorTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.operatorLoop(ft, std);
		test.printTestResults("Int Vector   ");

		test.operatorModify(ft, std, 0, 0);
		test.operatorModify(ft, std, ft.size() - 1, 123);
		test.operatorModify(ft, std, ft.size() / 2, 123);
		test.operatorModify(ft, std, ft.size() / 3, 456);
		test.operatorModify(ft, std, ft.size() / 4, 789);
		test.operatorModify(ft, std, ft.size() / 5, 1234567890);

		test.operatorLoop(ft, std);
		test.printTestResults("Modified Int Vector");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));

		test.operatorLoop(ft, std);
		test.printTestResults("String Vector");

		test.operatorModify(ft, std, 0, "The sun");
		test.operatorModify(ft, std, ft.size() - 1, "had set,");
		test.operatorModify(ft, std, ft.size() / 2, "and");
		test.operatorModify(ft, std, ft.size() / 3, "so had");
		test.operatorModify(ft, std, ft.size() / 4, "his");
		test.operatorModify(ft, std, ft.size() / 5, "grades");

		test.operatorLoop(ft, std);
		test.printTestResults("Modified Str Vector");
	}
}

static void atTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.atLoop(ft, std);
		test.printTestResults("Int Vector   ");

		test.atModify(ft, std, 0, 0);
		test.atModify(ft, std, ft.size() - 1, 123);
		test.atModify(ft, std, ft.size() / 2, 123);
		test.atModify(ft, std, ft.size() / 3, 456);
		test.atModify(ft, std, ft.size() / 4, 789);
		test.atModify(ft, std, ft.size() / 5, 1234567890);

		test.atLoop(ft, std);
		test.printTestResults("Modified Int Vector");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));

		test.atLoop(ft, std);
		test.printTestResults("String Vector");

		test.atModify(ft, std, 0, "The sun");
		test.atModify(ft, std, ft.size() - 1, "had set,");
		test.atModify(ft, std, ft.size() / 2, "and");
		test.atModify(ft, std, ft.size() / 3, "so had");
		test.atModify(ft, std, ft.size() / 4, "his");
		test.atModify(ft, std, ft.size() / 5, "grades");

		test.atLoop(ft, std);
		test.printTestResults("Modified Str Vector");
	}
}

static void atExceptionTests() {
	vectorTester test;

	ft::vector<long> ft;
	std::vector<long> std;
	test.pushLoop(ft, std, 100);

	test.atException(ft, std, 0);
	test.atException(ft, std, ft.size());
	test.atException(ft, std, ft.size() / 2);
	test.atException(ft, std, ft.max_size());
	test.atException(ft, std, ft.max_size() / 2);
	test.atException(ft, std, CHAR_BIT);
	test.atException(ft, std, CHAR_MIN);
	test.atException(ft, std, CHAR_MAX);
	test.atException(ft, std, SCHAR_MIN);
	test.atException(ft, std, SCHAR_MAX);
	test.atException(ft, std, INT_MIN);
	test.atException(ft, std, INT_MAX);
	test.atException(ft, std, SHRT_MIN);
	test.atException(ft, std, SHRT_MAX);
	test.atException(ft, std, USHRT_MAX);
	test.atException(ft, std, LONG_MIN);
	test.atException(ft, std, LONG_MAX);
	test.atException(ft, std, ULONG_MAX);
	test.atException(ft, std, std::rand());

	test.printTestResults("");
}

static void frontTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.compareFrontBack(ft, std, FRONT);
		test.atModify(ft, std, 0, 0);
		test.compareFrontBack(ft, std, FRONT);
		test.resizeAndCompare(ft, std, 42, 123456789);
		test.compareFrontBack(ft, std, FRONT);
		test.atModify(ft, std, 0, 24);
		test.compareFrontBack(ft, std, FRONT);

		test.printTestResults("Int Vector    ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));

		test.compareFrontBack(ft, std, FRONT);
		test.atModify(ft, std, 0, "Hello World!");
		test.compareFrontBack(ft, std, FRONT);
		test.resizeAndCompare(ft, std, 42, "Lorem ipsum dolor sit amet,");
		test.compareFrontBack(ft, std, FRONT);
		test.atModify(ft, std, 0, "The quick brown fox jumps over the lazy dog");
		test.compareFrontBack(ft, std, FRONT);

		test.printTestResults("String Vector");
	}
}

static void backTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.compareFrontBack(ft, std, BACK);
		test.atModify(ft, std, ft.size() - 1, 0);
		test.compareFrontBack(ft, std, BACK);
		test.resizeAndCompare(ft, std, 42, 123456789);
		test.compareFrontBack(ft, std, BACK);
		test.atModify(ft, std, ft.size() - 1, 24);
		test.compareFrontBack(ft, std, BACK);

		test.printTestResults("Int Vector    ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));

		test.compareFrontBack(ft, std, BACK);
		test.atModify(ft, std, ft.size() - 1, "The quick brown fox jumps over the lazy dog");
		test.compareFrontBack(ft, std, BACK);
		test.resizeAndCompare(ft, std, 42, "Lorem ipsum dolor sit amet,");
		test.compareFrontBack(ft, std, BACK);
		test.atModify(ft, std, ft.size() - 1, "Hello World!");
		test.compareFrontBack(ft, std, BACK);

		test.printTestResults("String Vector");
	}
}

static void dataTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.dataLoop(ft, std);
		test.printTestResults("Int Vector   ");

		test.dataModify(ft, std, 0, 0);
		test.dataModify(ft, std, ft.size() - 1, 123);
		test.dataModify(ft, std, ft.size() / 2, 123);
		test.dataModify(ft, std, ft.size() / 3, 456);
		test.dataModify(ft, std, ft.size() / 4, 789);
		test.dataModify(ft, std, ft.size() / 5, 1234567890);

		test.dataLoop(ft, std);
		test.printTestResults("Modified Int Vector");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));

		test.dataLoop(ft, std);
		test.printTestResults("String Vector");

		test.dataModify(ft, std, 0, "The sun");
		test.dataModify(ft, std, ft.size() - 1, "had set,");
		test.dataModify(ft, std, ft.size() / 2, "and");
		test.dataModify(ft, std, ft.size() / 3, "so had");
		test.dataModify(ft, std, ft.size() / 4, "his");
		test.dataModify(ft, std, ft.size() / 5, "grades");

		test.dataLoop(ft, std);
		test.printTestResults("Modified Str Vector");		
	}
}
