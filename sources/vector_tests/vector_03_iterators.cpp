/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_03_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:26:11 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/13 12:40:52 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

static void beginTests();
static void endTests();
static void iteratorLoopTests();

static void constBeginTests();
static void constEndTests();
static void constIterLoopTests();

static void rbeginTests();
static void rendTests();
static void reverseIteratorLoopTests();

static void constRbeginTests();
static void constRendTests();
static void constRevIterLoopTests();

int main() {
	std::srand(time(NULL));

	std::cout << PURPLE "Iterator Tests" DEFAULT << std::endl;
	beginTests();
	endTests();
	iteratorLoopTests();

	std::cout << PURPLE "Const Iterator Tests" DEFAULT << std::endl;
	constBeginTests();
	constEndTests();
	constIterLoopTests();

	std::cout << PURPLE "Reverse Iterator Tests" DEFAULT << std::endl;
	rbeginTests();
	rendTests();
	reverseIteratorLoopTests();

	std::cout << PURPLE "Const Reverse Iterator Tests" DEFAULT << std::endl;
	constRbeginTests();
	constRendTests();
	constRevIterLoopTests();

	return 0;
}

/*----------------------------------------------------------------------------*/
/**
** @brief    There are multiple double declarations on the templates listed below.
**           I'm aware that the tester compiles all cases even if I were to take
**           away all the templates that don't contain the const keyword. However,
**           I needed to declare them explicitly because if I don't, then all the
**           iterators that will be used during the tests are constant; which
**           opens up the possibility of an error going unnoticed
*/

template <typename T>
static void beginTestSet(vectorTester test, ft::vector<T> &ft, std::vector<T> &std) {
	test.compareIterToStd(ft, std, 0, BEGIN);
	test.compareIterToStd(ft, std, ft.size() / 2, BEGIN);
	test.compareIterToStd(ft, std, ft.size() - 1, BEGIN);
}
template <typename T>
static void beginTestSet(vectorTester test, const ft::vector<T> &ft, const std::vector<T> &std) {
	test.compareIterToStd(ft, std, 0, BEGIN);
	test.compareIterToStd(ft, std, ft.size() / 2, BEGIN);
	test.compareIterToStd(ft, std, ft.size() - 1, BEGIN);
}


template <typename T>
static void endTestSet(vectorTester test, ft::vector<T> &ft, std::vector<T> &std) {
	test.compareIterToStd(ft, std, 1, END);
	test.compareIterToStd(ft, std, ft.size() / 2, END);
	test.compareIterToStd(ft, std, ft.size(), END);
}
template <typename T>
static void endTestSet(vectorTester test, const ft::vector<T> &ft, const std::vector<T> &std) {
	test.compareIterToStd(ft, std, 1, END);
	test.compareIterToStd(ft, std, ft.size() / 2, END);
	test.compareIterToStd(ft, std, ft.size(), END);
}


template <typename T>
static void iterLoopTestSet(vectorTester test, ft::vector<T> &ft, std::vector<T> &std) {
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
}
template <typename T>
static void iterLoopTestSet(vectorTester test, const ft::vector<T> &ft, const std::vector<T> &std) {
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
}


template <typename T>
static void rbeginTestSet(vectorTester test, ft::vector<T> &ft, std::vector<T> &std) {
	test.compareIterToStd(ft, std, 0, RBEGIN);
	test.compareIterToStd(ft, std, ft.size() / 2, RBEGIN);
	test.compareIterToStd(ft, std, ft.size() - 1, RBEGIN);
}
template <typename T>
static void rbeginTestSet(vectorTester test, const ft::vector<T> &ft, const std::vector<T> &std) {
	test.compareIterToStd(ft, std, 0, RBEGIN);
	test.compareIterToStd(ft, std, ft.size() / 2, RBEGIN);
	test.compareIterToStd(ft, std, ft.size() - 1, RBEGIN);
}


template <typename T>
static void rendTestSet(vectorTester test, ft::vector<T> &ft, std::vector<T> &std) {
	test.compareIterToStd(ft, std, 1, REND);
	test.compareIterToStd(ft, std, ft.size() / 2, REND);
	test.compareIterToStd(ft, std, ft.size() - 1, REND);
}
template <typename T>
static void rendTestSet(vectorTester test, const ft::vector<T> &ft, const std::vector<T> &std) {
	test.compareIterToStd(ft, std, 1, REND);
	test.compareIterToStd(ft, std, ft.size() / 2, REND);
	test.compareIterToStd(ft, std, ft.size() - 1, REND);
}


template <typename T>
static void revIterLoopTestSet(vectorTester test, ft::vector<T> &ft, std::vector<T> &std) {
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
}
template <typename T>
static void revIterLoopTestSet(vectorTester test, const ft::vector<T> &ft, const std::vector<T> &std) {
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
}

/*----------------------------------------------------------------------------*/

int array[] = { 16801, 19817, 48952, 20130, 73915, 23176, 42669, 82132, 42510, 54383,
                81435, 2480, 46371, 64482, 89407, 5378, 46018, 33244, 16355, 88450,
                95943, 88707, 14117, 11984, 42966, 4000, 28060, 78251, 93742, 39744, };

static void beginTests() {
	vectorTester test;
	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	beginTestSet(test, ft, std);
	test.printTestResults("Begin       ");
}

static void constBeginTests() {
	vectorTester test;
	const ft::vector<int> ft(array, array + (sizeof(array) / sizeof(int)));
	const std::vector<int> std(array, array + (sizeof(array) / sizeof(int)));

	beginTestSet(test, ft, std);
	test.printTestResults("Begin       ");
}

static void endTests() {
	vectorTester test;
	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	endTestSet(test, ft, std);
	test.printTestResults("End         ");
}

static void constEndTests() {
	vectorTester test;
	const ft::vector<int> ft(array, array + (sizeof(array) / sizeof(int)));
	const std::vector<int> std(array, array + (sizeof(array) / sizeof(int)));

	endTestSet(test, ft, std);
	test.printTestResults("End         ");
}

static void iteratorLoopTests() {
	vectorTester test;
	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	iterLoopTestSet(test, ft, std);
	test.printTestResults("Iterator Loop");
}

static void constIterLoopTests() {
	vectorTester test;
	const ft::vector<int> ft(array, array + (sizeof(array) / sizeof(int)));
	const std::vector<int> std(array, array + (sizeof(array) / sizeof(int)));

	iterLoopTestSet(test, ft, std);
	test.printTestResults("Iterator Loop");
}

static void rbeginTests() {
	vectorTester test;
	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	rbeginTestSet(test, ft, std);
	test.printTestResults("Rbegin      ");
}

static void constRbeginTests() {
	vectorTester test;
	const ft::vector<int> ft(array, array + (sizeof(array) / sizeof(int)));
	const std::vector<int> std(array, array + (sizeof(array) / sizeof(int)));

	rbeginTestSet(test, ft, std);
	test.printTestResults("Rbegin      ");
}

static void rendTests() {
	vectorTester test;
	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	rendTestSet(test, ft, std);
	test.printTestResults("Rend        ");
}

static void constRendTests() {
	vectorTester test;
	const ft::vector<int> ft(array, array + (sizeof(array) / sizeof(int)));
	const std::vector<int> std(array, array + (sizeof(array) / sizeof(int)));

	rendTestSet(test, ft, std);
	test.printTestResults("Rend        ");
}

static void reverseIteratorLoopTests() {
	vectorTester test;
	ft::vector<int> ft;
	std::vector<int> std;
	test.pushLoop(ft, std, 42);

	revIterLoopTestSet(test, ft, std);
	test.printTestResults("Reverse Iter Loop");
}

static void constRevIterLoopTests() {
	vectorTester test;
	const ft::vector<int> ft(array, array + (sizeof(array) / sizeof(int)));
	const std::vector<int> std(array, array + (sizeof(array) / sizeof(int)));

	revIterLoopTestSet(test, ft, std);
	test.printTestResults("Reverse Iter Loop");
}
