/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:58:35 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/10 11:50:38 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

#define EQUAL               1
#define NOT_EQUAL           2
#define LESS                3
#define LESS_OR_EQUAL       4
#define GREATER             5
#define GREATER_OR_EQUAL    6

template <typename T>
void doRelationalTests(NAMESPACE::vector<T> &lhs, NAMESPACE::vector<T> &rhs);

template <typename T>
void getComparison(NAMESPACE::vector<T> &lhs, NAMESPACE::vector<T> &rhs, int type);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::vector<int> test;
	pushRandomValues(test, 30);

	NAMESPACE::vector<int> clone(test);
	doRelationalTests(test, clone);

	clone.pop_back();
	clone.erase(clone.begin() + (clone.size() / 2));
	clone.push_back(123456789);
	clone.insert(clone.begin() + (clone.size() / 4), 42);
	doRelationalTests(test, clone);

	pushRandomValues(clone, 10);
	doRelationalTests(test, clone);

	test.clear();
	doRelationalTests(test, clone);

	clone.clear();
	doRelationalTests(test, clone);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename T>
void doRelationalTests(NAMESPACE::vector<T> &lhs, NAMESPACE::vector<T> &rhs) {
	std::cout << "--------------------------------------------------" << std::endl;
	getComparison(lhs, rhs, EQUAL);
	getComparison(lhs, rhs, NOT_EQUAL);
	getComparison(lhs, rhs, LESS);
	getComparison(lhs, rhs, LESS_OR_EQUAL);
	getComparison(lhs, rhs, GREATER);
	getComparison(lhs, rhs, GREATER_OR_EQUAL);
}

template <typename T>
void getComparison(NAMESPACE::vector<T> &lhs, NAMESPACE::vector<T> &rhs, int type) {
	std::cout << "lhs vector " << std::boolalpha
	          << (type == EQUAL ? "==" :
	              type == NOT_EQUAL ? "!=" :
	              type == LESS ? "<" :
	              type == LESS_OR_EQUAL ? "<=" :
	              type == GREATER ? ">" : ">=") << " rhs vector? "
	          << (type == EQUAL ? (lhs == rhs) :
	              type == NOT_EQUAL ? (lhs != rhs) :
	              type == LESS ? (lhs < rhs) :
	              type == LESS_OR_EQUAL ? (lhs <= rhs) :
	              type == GREATER ? (lhs > rhs) : (lhs >= rhs)) << std::endl;
}
