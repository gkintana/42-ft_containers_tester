/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:28:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/10 00:35:07 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

static void basicTests();
static void exceptionTests();

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	basicTests();
	exceptionTests();

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

static void basicTests() {
	size_t size = 10,
	       value = 12345;
	NAMESPACE::vector<int> test(size, value);
	printByOperator(test);

	test.reserve(42);
	printByOperator(test);
	test.reserve('a');
	printByOperator(test);
	test.reserve(0);
	printByOperator(test);
	test.reserve(999999999);
	printByOperator(test);
	test.reserve(test.capacity());
	printByOperator(test);
	test.reserve(123456789);
	printByOperator(test);
	test.reserve('Z' + 98765 - 12345);
	printByOperator(test);
	test.reserve(*test.begin() + (test.size() / 2));
	printByOperator(test);
}

static void exceptionTests() {
	NAMESPACE::vector<int> test;
	capacityExceptionCheck(test, test.max_size(), false);
	capacityExceptionCheck(test, 0, false);
	capacityExceptionCheck(test, CHAR_BIT, false);
	capacityExceptionCheck(test, CHAR_MIN, false);
	capacityExceptionCheck(test, CHAR_MAX, false);
	capacityExceptionCheck(test, SCHAR_MIN, false);
	capacityExceptionCheck(test, SCHAR_MAX, false);
	capacityExceptionCheck(test, INT_MIN, false);
	capacityExceptionCheck(test, INT_MAX, false);
	capacityExceptionCheck(test, UINT_MAX, false);
	capacityExceptionCheck(test, SHRT_MIN, false);
	capacityExceptionCheck(test, SHRT_MAX, false);
	capacityExceptionCheck(test, USHRT_MAX, false);
	capacityExceptionCheck(test, LONG_MIN, false);
	capacityExceptionCheck(test, LONG_MAX, false);
	capacityExceptionCheck(test, ULONG_MAX, false);
}
