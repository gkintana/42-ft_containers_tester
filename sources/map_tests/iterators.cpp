/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:41:39 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/07 23:06:42 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
    timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

    NAMESPACE::map<int, int> test;
    NAMESPACE::map<int, int>::iterator iter_begin = test.begin();
    NAMESPACE::map<int, int>::iterator iter_end = test.end();

    std::cout << "Is map.begin() == map.end()? " << std::boolalpha
              << (test.begin() == test.end()) << std::endl;

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

    std::cout << "Is map.begin() == iter_begin? "
	          << (test.begin() == iter_begin) << std::endl
	          << "Is map.end() == iter_end? "
	          << (test.end() == iter_end) << std::endl
	          << "Is map.begin() == map.end()? "
	          << (test.begin() == test.end()) << std::endl;

	printByIterator(test, test.begin(), test.end());
	printByIterator(test, --test.end(), test.begin(), false);

	printByConstIterator(test, test.begin(), test.end());
	printByConstIterator(test, --test.end(), test.begin(), false);

	printByReverseIterator(test, test.rbegin(), test.rend());
	printByReverseIterator(test, --test.rend(), test.rbegin(), false);

	printByConstReverseIterator(test, test.rbegin(), test.rend());
	printByConstReverseIterator(test, --test.rend(), test.rbegin(), false);

	/*---------------------------------------------------------------------------------------*/

	NAMESPACE::map<int, int>::const_iterator const_iter_begin = test.begin();
	std::cout << "Is const_iter_begin == iter_begin? "
	          << (const_iter_begin == iter_begin) << std::endl
	          << "Is iter_begin == const_iter_begin? "
	          << (iter_begin == const_iter_begin) << std::endl;

	NAMESPACE::map<int, int>::const_iterator const_iter_end = test.end();
	std::cout << "Is const_iter_end == iter_end? "
	          << (const_iter_end == iter_end) << std::endl
	          << "Is iter_end == const_iter_end? "
	          << (iter_end == const_iter_end) << std::endl;

    gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
