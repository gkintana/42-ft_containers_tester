/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:41:39 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/08 12:35:55 by gkintana         ###   ########.fr       */
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

	insertRandomValues(test, 30);

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
