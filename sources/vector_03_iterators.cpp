/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_03_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:26:11 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 10:27:18 by gkintana         ###   ########.fr       */
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

	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	test.compareIterToStd(ft, std, 0, BEGIN);
	test.compareIterToStd(ft, std, ft.size() / 2, BEGIN);
	test.compareIterToStd(ft, std, ft.size() - 1, BEGIN);

	test.printTestResults("Begin       ");
}

static void endTests() {
	vectorTester test;

	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	test.compareIterToStd(ft, std, 1, END);
	test.compareIterToStd(ft, std, ft.size() / 2, END);
	test.compareIterToStd(ft, std, ft.size(), END);

	test.printTestResults("End         ");
}

static void iteratorLoopTests() {
	vectorTester test;

	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	test.iterLoop(ft, std, ft.begin(), ft.end());
	test.iterLoop(ft, std, ft.begin() + (ft.size() / 2), ft.end());
	test.iterLoop(ft, std, ft.begin() + (ft.size() - 1), ft.end());
	test.iterLoop(ft, std, ft.begin() + ft.size(), ft.end());
	test.iterLoop(ft, std, ft.begin(), ft.end() - (ft.size() / 4));
	test.iterLoop(ft, std, ft.begin(), ft.end() - (ft.size() / 2));
	test.iterLoop(ft, std, ft.begin(), ft.end() - (ft.size() - 1));
	test.iterLoop(ft, std, ft.begin(), ft.end() - ft.size());
	test.iterLoop(ft, std, ft.begin() + (ft.size() / 4), ft.end() - (ft.size() / 2));
	test.iterLoop(ft, std, ft.begin() + (ft.size() / 3), ft.end() - (ft.size() / 3));
	test.iterLoop(ft, std, ft.begin() + (ft.size() / 2), ft.end() - (ft.size() / 4));
	test.iterLoop(ft, std, ft.end(), ft.end());
	test.iterLoop(ft, std, ft.end() - ft.size(), ft.end());
	test.iterLoop(ft, std, ft.end() - (ft.size() / 2), ft.end());
	test.iterLoop(ft, std, ft.end() - (ft.size() / 2), ft.end() - (ft.size() / 4));

	test.printTestResults("Iterator Loop");
}

static void rbeginTests() {
	vectorTester test;

	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	test.compareIterToStd(ft, std, 0, RBEGIN);
	test.compareIterToStd(ft, std, ft.size() / 2, RBEGIN);
	test.compareIterToStd(ft, std, ft.size() - 1, RBEGIN);

	test.printTestResults("Rbegin      ");
}

static void rendTests() {
	vectorTester test;

	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	test.compareIterToStd(ft, std, 1, REND);
	test.compareIterToStd(ft, std, ft.size() / 2, REND);
	test.compareIterToStd(ft, std, ft.size() - 1, REND);

	test.printTestResults("Rend        ");
}

static void reverseIteratorLoopTests() {
	vectorTester test;

	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	test.revIterLoop(ft, std, ft.rend() - 1, ft.rbegin());
	test.revIterLoop(ft, std, ft.rend() - (ft.size() / 2), ft.rbegin());
	test.revIterLoop(ft, std, ft.rend() - (ft.size() - 1), ft.rbegin());
	test.revIterLoop(ft, std, ft.rend() - ft.size(), ft.rbegin());
	test.revIterLoop(ft, std, ft.rend() - 1, ft.rbegin() + (ft.size() / 4));
	test.revIterLoop(ft, std, ft.rend() - 1, ft.rbegin() + (ft.size() / 3));
	test.revIterLoop(ft, std, ft.rend() - 1, ft.rbegin() + (ft.size() / 2));
	test.revIterLoop(ft, std, ft.rend() - 1, ft.rbegin() + ft.size() - 1);
	test.revIterLoop(ft, std, ft.rend() - (ft.size() / 4), ft.rbegin() + (ft.size() / 2));
	test.revIterLoop(ft, std, ft.rend() - (ft.size() / 3), ft.rbegin() + (ft.size() / 3));
	test.revIterLoop(ft, std, ft.rend() - (ft.size() / 2), ft.rbegin() + (ft.size() / 4));
	test.revIterLoop(ft, std, ft.rbegin() + 1, ft.rbegin());
	test.revIterLoop(ft, std, ft.rbegin() + (ft.size() - 1), ft.rbegin());
	test.revIterLoop(ft, std, ft.rbegin() + (ft.size() / 2), ft.rbegin());
	test.revIterLoop(ft, std, ft.rbegin() + (ft.size() / 2), ft.rbegin() + (ft.size() / 4));

	test.printTestResults("Reverse Iter Loop");
}
