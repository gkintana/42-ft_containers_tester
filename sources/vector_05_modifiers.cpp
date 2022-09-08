/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_05_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/08 17:51:23 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

static void clearTests();
static void singleEraseTests();
static void rangedEraseTests();
static void pushBackTests();
// static void popBackTests();
static void swapTests();

int main() {
	std::srand(time(NULL));

	std::cout << PURPLE "Clear Tests" DEFAULT << std::endl;
	clearTests();

	std::cout << PURPLE "Single Erase Tests" DEFAULT << std::endl;
	singleEraseTests();

	std::cout << PURPLE "Ranged Erase Tests" DEFAULT << std::endl;
	rangedEraseTests();

	std::cout << PURPLE "Push Back Tests" DEFAULT << std::endl;
	pushBackTests();

	std::cout << PURPLE "Swap Tests" DEFAULT << std::endl;
	swapTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void clearTests() {
	vectorTester test;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		test.clearVectors(ft_vec, std_vec);

		test.printTestResults("Empty Int Vector");
	}

	{
		ft::vector<char> ft_vec(42, 'A');
		std::vector<char> std_vec(42, 'A');
		test.clearVectors(ft_vec, std_vec);

		test.printTestResults("Char Vector   ");
	}

	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		test.pushLoop(ft_vec, std_vec, 42);
		test.clearVectors(ft_vec, std_vec);

		test.printTestResults("Int Vector    ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft_str(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_str(array, array + (sizeof(array) / sizeof(std::string)));
		test.clearVectors(ft_str, std_str);

		test.printTestResults("String Vector");
	}
}

static void singleEraseTests() {
	vectorTester test;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		test.pushLoop(ft_vec, std_vec, 42);

		test.singleErase(ft_vec, std_vec, BEGIN, 0);
		test.singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() / 2);
		test.singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() - 1);
		test.singleErase(ft_vec, std_vec, END, 1);
		test.singleErase(ft_vec, std_vec, END, ft_vec.size() / 2);
		test.singleErase(ft_vec, std_vec, END, ft_vec.size());

		test.printTestResults("Int Vector   ");
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft_vec(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_vec(array, array + (sizeof(array) / sizeof(std::string)));

		test.singleErase(ft_vec, std_vec, BEGIN, 0);
		test.singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() / 2);
		test.singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() - 1);
		test.singleErase(ft_vec, std_vec, END, 1);
		test.singleErase(ft_vec, std_vec, END, ft_vec.size() / 2);
		test.singleErase(ft_vec, std_vec, END, ft_vec.size());

		test.printTestResults("String Vector   ");
	}
}

static void rangedEraseTests() {
	vectorTester test;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		test.pushLoop(ft_vec, std_vec, 256);

		test.rangedErase(ft_vec, std_vec, BEGIN, 0, BEGIN, 0);
		test.rangedErase(ft_vec, std_vec, BEGIN, 0, BEGIN, ft_vec.size());
		test.rangedErase(ft_vec, std_vec, BEGIN, 0, END, 0);
		test.rangedErase(ft_vec, std_vec, BEGIN, ft_vec.size() / 2, END, 0);
		test.rangedErase(ft_vec, std_vec, BEGIN, ft_vec.size() - 1, END, 0);
		test.rangedErase(ft_vec, std_vec, BEGIN, ft_vec.size(), END, 0);
		test.rangedErase(ft_vec, std_vec, END, 1, BEGIN, ft_vec.size());
		test.rangedErase(ft_vec, std_vec, END, 1, END, 1);

		test.printTestResults("Int Vector   ");
	}
}

static void pushBackTests() {
	vectorTester test;
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		test.pushLoop(ft_vec, std_vec, 42);
		test.printTestResults("Char Vector   ");
	}
	// {
	// 	ft::vector<size_t> ft_vec;
	// 	std::vector<size_t> std_vec;
	// 	test.pushLoop(ft_vec, std_vec, 999999);
	// 	test.printTestResults("SIZE_MAX    ");
	// }
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		test.pushLoop(ft_vec, std_vec, 42);
		test.printTestResults("Int Vector   ");
	}

	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		test.pushLoop(ft_vec, std_vec, 42, "Hello World!");
		test.printTestResults("String Vector");
	}
}

// // static void popBackTests() {
	
// // }

static void swapTests() {
	vectorTester test;
	{
		ft::vector<int> ft_vec1;
		std::vector<int> std_vec1;
		test.pushLoop(ft_vec1, std_vec1, 24);
		ft::vector<int> ft_vec2;
		std::vector<int> std_vec2;
		test.pushLoop(ft_vec2, std_vec2, ft_vec1.size() * 3);

		ft_vec1.swap(ft_vec2);
		std_vec1.swap(std_vec2);

		test.compareVectors(ft_vec1, std_vec1);
		test.compareVectors(ft_vec2, std_vec2);

		test.printTestResults("Int Vector   ");
	}

	{
		ft::vector<std::string> ft_vec1;
		std::vector<std::string> std_vec1;
		test.pushLoop(ft_vec1, std_vec1, 24, "42 Abu Dhabi is Awesome!");
		ft::vector<std::string> ft_vec2;
		std::vector<std::string> std_vec2;
		test.pushLoop(ft_vec1, std_vec1, 42, "Hello World!");

		ft_vec1.swap(ft_vec2);
		std_vec1.swap(std_vec2);

		test.compareVectors(ft_vec1, std_vec1);
		test.compareVectors(ft_vec2, std_vec2);

		test.printTestResults("String Vector");
	}
}
