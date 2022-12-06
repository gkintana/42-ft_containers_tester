/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:51:04 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/07 00:00:49 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

#define EQUAL               1
#define NOT_EQUAL           2
#define LESS                3
#define LESS_OR_EQUAL       4
#define GREATER             5
#define GREATER_OR_EQUAL    6

template <typename key, typename value>
void getComparison(NAMESPACE::map<key, value> &map1, NAMESPACE::map<key, value> &map2, int type);

template <typename key, typename value>
void doRelationalTests(NAMESPACE::map<key, value> &map1, NAMESPACE::map<key, value> &map2);

/*-------------------------------------------------------------------------------------------*/

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

    NAMESPACE::map<int, int> test;
	insertValue(test, INSERT_BY_PAIR, -864, -2587);
	insertValue(test, INSERT_BY_PAIR, -8009, -4062);
	insertValue(test, INSERT_BY_PAIR, 7169, -8664);
	insertValue(test, INSERT_BY_PAIR, 8507, -7579);
	insertValue(test, INSERT_BY_PAIR, -1955, -7323);
	insertValue(test, INSERT_BY_MAKE_PAIR, 4422, -8493);
	insertValue(test, INSERT_BY_MAKE_PAIR, 7264, 6940);
	insertValue(test, INSERT_BY_MAKE_PAIR, 5916, -781);
	insertValue(test, INSERT_BY_MAKE_PAIR, -8379, 4325);
	insertValue(test, INSERT_BY_MAKE_PAIR, -9776, -877);
	insertValue(test, INSERT_BY_OPERATOR, -1095, -8887);
	insertValue(test, INSERT_BY_OPERATOR, -4338, 4283);
	insertValue(test, INSERT_BY_OPERATOR, 4367, 4430);
	insertValue(test, INSERT_BY_OPERATOR, 3919, -8373);
	insertValue(test, INSERT_BY_OPERATOR, 2339, 3903);

	// same size & same values
	NAMESPACE::map<int, int> clone(test);
	doRelationalTests(test, clone);

	// same size but different values
	clone.erase(clone.begin());
	clone.erase(--clone.end());
	insertValue(clone, INSERT_BY_MAKE_PAIR, 4920, -3737);
	insertValue(clone, INSERT_BY_MAKE_PAIR, 5864, -4092);
	doRelationalTests(test, clone);

	// empty lhs container
	test.clear();
	doRelationalTests(test, clone);

	// different size & values
	clone = test;
	insertValue(test, INSERT_BY_PAIR, -864, -2587);
	insertValue(test, INSERT_BY_OPERATOR, 2339, 3903);
	doRelationalTests(test, clone);

	// empty rhs container
	clone.erase(clone.begin(), clone.end());
	doRelationalTests(test, clone);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename key, typename value>
void doRelationalTests(NAMESPACE::map<key, value> &lhs, NAMESPACE::map<key, value> &rhs) {
	std::cout << "--------------------------------------------------" << std::endl;
	getComparison(lhs, rhs, EQUAL);
	getComparison(lhs, rhs, NOT_EQUAL);
	getComparison(lhs, rhs, LESS);
	getComparison(lhs, rhs, LESS_OR_EQUAL);
	getComparison(lhs, rhs, GREATER);
	getComparison(lhs, rhs, GREATER_OR_EQUAL);
}

template <typename key, typename value>
void getComparison(NAMESPACE::map<key, value> &lhs, NAMESPACE::map<key, value> &rhs, int type) {
	std::cout << "lhs map " << std::boolalpha
	          << (type == EQUAL ? "==" :
	              type == NOT_EQUAL ? "!=" :
	              type == LESS ? "<" :
	              type == LESS_OR_EQUAL ? "<=" :
	              type == GREATER ? ">" : ">=") << " rhs map? "
	          << (type == EQUAL ? (lhs == rhs) :
	              type == NOT_EQUAL ? (lhs != rhs) :
	              type == LESS ? (lhs < rhs) :
	              type == LESS_OR_EQUAL ? (lhs <= rhs) :
	              type == GREATER ? (lhs > rhs) : (lhs >= rhs)) << std::endl;
}
