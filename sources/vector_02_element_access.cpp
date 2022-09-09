/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_02_element_access.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:12 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/09 14:22:57 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

static void atTests();
static void atExceptionTests();

int main() {
	srand(time(NULL));

	std::cout << PURPLE "At Tests" DEFAULT << std::endl;
	atTests();

	std::cout << PURPLE "At Exception Tests" DEFAULT << std::endl;
	atExceptionTests();

	return 0;
}

static void atTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);
		test.compareAt(ft, std);
		test.printTestResults("Int Vector   ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));
		test.compareAt(ft, std);
		test.printTestResults("String Vector");
	}

	{
		ft::vector<int> ft;
		std::vector<int> std;
		test.pushLoop(ft, std, 42);

		test.atModify(ft, std, 0, 0);
		test.atModify(ft, std, ft.size() - 1, 123);
		test.atModify(ft, std, ft.size() / 2, 123);
		test.atModify(ft, std, ft.size() / 3, 456);
		test.atModify(ft, std, ft.size() / 4, 789);
		test.atModify(ft, std, ft.size() / 5, 1234567890);

		test.compareAt(ft, std);
		test.printTestResults("Modified Int Vector");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std(array, array + (sizeof(array) / sizeof(std::string)));

		test.atModify(ft, std, 0, "The sun");
		test.atModify(ft, std, ft.size() - 1, "had set,");
		test.atModify(ft, std, ft.size() / 2, "and");
		test.atModify(ft, std, ft.size() / 3, "so had");
		test.atModify(ft, std, ft.size() / 4, "his");
		test.atModify(ft, std, ft.size() / 5, "grades");

		test.compareAt(ft, std);
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
