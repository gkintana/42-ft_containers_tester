/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_06_non_member.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:58:35 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/11 22:02:40 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

static void relationalOperatorTests();
static void swapTests();

int main() {
	std::srand(time(NULL));

	std::cout << PURPLE "Relational Operator Tests" DEFAULT << std::endl;
	relationalOperatorTests();

	std::cout << PURPLE "Swap Tests" DEFAULT << std::endl;
	swapTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void relationalOperatorTests() {
	vectorTester test;
	{
		ft::vector<int> ft1;
		std::vector<int> std1;
		test.pushLoop(ft1, std1, 10);

		ft::vector<int> ft2;
		std::vector<int> std2;
		test.pushLoop(ft2, std2, 20);

		test.relationalOper(ft1, std1, ft2, std2, EQUAL);
		test.printTestResults("Int Vector (==)");

		test.relationalOper(ft1, std1, ft2, std2, NOT_EQUAL);
		test.printTestResults("Int Vector (!=)");

		test.relationalOper(ft1, std1, ft2, std2, LESS);
		test.printTestResults("Int Vector (<)");

		test.relationalOper(ft1, std1, ft2, std2, LESS_EQUAL);
		test.printTestResults("Int Vector (<=)");

		test.relationalOper(ft1, std1, ft2, std2, GREATER);
		test.printTestResults("Int Vector (>)");

		test.relationalOper(ft1, std1, ft2, std2, GREATER_EQUAL);
		test.printTestResults("Int Vector (>=)");
	}

	{
		ft::vector<std::string> ft1(5, "Hello");
		std::vector<std::string> std1(5, "Hello");
		
		ft::vector<std::string> ft2(10, "World!");
		std::vector<std::string> std2(10, "World!");

		test.relationalOper(ft1, std1, ft2, std2, EQUAL);
		test.printTestResults("String Vector (==)");

		test.relationalOper(ft1, std1, ft2, std2, NOT_EQUAL);
		test.printTestResults("String Vector (!=)");

		test.relationalOper(ft1, std1, ft2, std2, LESS);
		test.printTestResults("String Vector (<)");

		test.relationalOper(ft1, std1, ft2, std2, LESS_EQUAL);
		test.printTestResults("String Vector (<=)");

		test.relationalOper(ft1, std1, ft2, std2, GREATER);
		test.printTestResults("String Vector (>)");

		test.relationalOper(ft1, std1, ft2, std2, GREATER_EQUAL);
		test.printTestResults("String Vector (>=)");
	}
}

static void swapTests() {
	vectorTester test;
	{
		ft::vector<int> ft1;
		std::vector<int> std1;
		test.pushLoop(ft1, std1, 5);
		ft::vector<int> ft2;
		std::vector<int> std2;
		test.pushLoop(ft2, std2, 10);

		ft::swap(ft1, ft2);
		std::swap(std1, std2);

		test.compareVectors(ft1, std1);
		test.compareVectors(ft2, std2);

		test.printTestResults("Int Vector   ");
	}

	{
		ft::vector<std::string> ft1;
		std::vector<std::string> std1;
		test.pushLoop(ft1, std1, 24, "42 Abu Dhabi is Awesome!");
		ft::vector<std::string> ft2;
		std::vector<std::string> std2;
		test.pushLoop(ft1, std1, 42, "Hello World!");

		ft::swap(ft1, ft2);
		std::swap(std1, std2);

		test.compareVectors(ft1, std1);
		test.compareVectors(ft2, std2);

		test.printTestResults("String Vector");
	}
}
