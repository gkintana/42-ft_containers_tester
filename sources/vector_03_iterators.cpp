/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_03_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:26:11 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/08 10:23:04 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

// #define BEGIN     1
// #define END       2
// #define RBEGIN    3
// #define REND      4

static void beginTests();
static void endTests();
static void iteratorLoopTests();
static void rbeginTests();
static void rendTests();
static void reverseIteratorLoopTests();

/**
** @REMINDER: add const iterator tests
*/
int main() {
	std::srand(time(NULL));

	std::cout << PURPLE "Iterator Tests" DEFAULT << std::endl;
	beginTests();
	endTests();
	iteratorLoopTests();

	// std::cout << PURPLE "Const Iterator Tests" DEFAULT << std::endl;

	std::cout << PURPLE "Reverse Iterator Tests" DEFAULT << std::endl;
	rbeginTests();
	rendTests();
	reverseIteratorLoopTests();

	// std::cout << PURPLE "Const Reverse Iterator Tests" DEFAULT << std::endl;

	return 0;
}

/*----------------------------------------------------------------------------*/

static void beginTests() {
	vectorTester test;

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	test.pushLoop(ft_vec, std_vec, 42);

	test.compareIterToStd(ft_vec, std_vec, 0, BEGIN);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size() / 2, BEGIN);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size() - 1, BEGIN);

	test.printTestResults("Begin       ");
}

static void endTests() {
	vectorTester test;

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	test.pushLoop(ft_vec, std_vec, 42);

	test.compareIterToStd(ft_vec, std_vec, 1, END);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size() / 2, END);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size(), END);

	test.printTestResults("End         ");
}

static void iteratorLoopTests() {
	vectorTester test;

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	test.pushLoop(ft_vec, std_vec, 42);

	test.iterLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end());
	test.iterLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 2), ft_vec.end());
	test.iterLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() - 1), ft_vec.end());
	test.iterLoop(ft_vec, std_vec, ft_vec.begin() + ft_vec.size(), ft_vec.end());
	test.iterLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - (ft_vec.size() / 4));
	test.iterLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - (ft_vec.size() / 2));
	test.iterLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - (ft_vec.size() - 1));
	test.iterLoop(ft_vec, std_vec, ft_vec.begin(), ft_vec.end() - ft_vec.size());
	test.iterLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 4), ft_vec.end() - (ft_vec.size() / 2));
	test.iterLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 3), ft_vec.end() - (ft_vec.size() / 3));
	test.iterLoop(ft_vec, std_vec, ft_vec.begin() + (ft_vec.size() / 2), ft_vec.end() - (ft_vec.size() / 4));
	test.iterLoop(ft_vec, std_vec, ft_vec.end(), ft_vec.end());
	test.iterLoop(ft_vec, std_vec, ft_vec.end() - ft_vec.size(), ft_vec.end());
	test.iterLoop(ft_vec, std_vec, ft_vec.end() - (ft_vec.size() / 2), ft_vec.end());
	test.iterLoop(ft_vec, std_vec, ft_vec.end() - (ft_vec.size() / 2), ft_vec.end() - (ft_vec.size() / 4));

	test.printTestResults("Iterator Loop");
}

static void rbeginTests() {
	vectorTester test;

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	test.pushLoop(ft_vec, std_vec, 42);

	test.compareIterToStd(ft_vec, std_vec, 0, RBEGIN);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size() / 2, RBEGIN);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size() - 1, RBEGIN);

	test.printTestResults("Rbegin      ");
}

static void rendTests() {
	vectorTester test;

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	test.pushLoop(ft_vec, std_vec, 42);

	test.compareIterToStd(ft_vec, std_vec, 1, REND);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size() / 2, REND);
	test.compareIterToStd(ft_vec, std_vec, ft_vec.size() - 1, REND);

	test.printTestResults("Rend        ");
}

static void reverseIteratorLoopTests() {
	vectorTester test;

	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	test.pushLoop(ft_vec, std_vec, 42);

	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin());
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 2), ft_vec.rbegin());
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() - 1), ft_vec.rbegin());
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - ft_vec.size(), ft_vec.rbegin());
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + (ft_vec.size() / 4));
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + (ft_vec.size() / 3));
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + (ft_vec.size() / 2));
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - 1, ft_vec.rbegin() + ft_vec.size() - 1);
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 4), ft_vec.rbegin() + (ft_vec.size() / 2));
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 3), ft_vec.rbegin() + (ft_vec.size() / 3));
	test.revIterLoop(ft_vec, std_vec, ft_vec.rend() - (ft_vec.size() / 2), ft_vec.rbegin() + (ft_vec.size() / 4));
	test.revIterLoop(ft_vec, std_vec, ft_vec.rbegin() + 1, ft_vec.rbegin());
	test.revIterLoop(ft_vec, std_vec, ft_vec.rbegin() + (ft_vec.size() - 1), ft_vec.rbegin());
	test.revIterLoop(ft_vec, std_vec, ft_vec.rbegin() + (ft_vec.size() / 2), ft_vec.rbegin());
	test.revIterLoop(ft_vec, std_vec, ft_vec.rbegin() + (ft_vec.size() / 2), ft_vec.rbegin() + (ft_vec.size() / 4));

	test.printTestResults("Reverse Iter Loop");
}
