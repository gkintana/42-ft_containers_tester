/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds_and_range.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:31:26 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/06 10:25:04 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

template <typename key, typename value>
void printBound(NAMESPACE::map<key, value> &map,
                typename NAMESPACE::map<key, value>::key_type k, bool isLower = true);

template <typename key, typename value>
void printRange(NAMESPACE::map<key, value> &map, 
                typename NAMESPACE::map<key, value>::key_type k);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<char, int> test;
	insertValue(test, INSERT_BY_PAIR, 'k', 107);
	insertValue(test, INSERT_BY_PAIR, '|', 124);
	insertValue(test, INSERT_BY_MAKE_PAIR, 'A', 65);
	insertValue(test, INSERT_BY_MAKE_PAIR, '#', 35);
	insertValue(test, INSERT_BY_OPERATOR, 'k', 0);
	insertValue(test, INSERT_BY_OPERATOR, '+', 45);
	insertValue(test, INSERT_BY_OPERATOR, ' ', 32);
	insertValue(test, --test.end(), '1', 49);
	insertValue(test, ++test.begin(), '[', 91);
	printContent(test);

	/*-------------------------------------------------------------------------------------------*/

	printBound(test, 'A');
	printBound(test, '!');
	printBound(test, 'j');
	NAMESPACE::map<char, int>::key_type key = '~';
	std::cout << "Is map::lower_bound(" << key << ") == map::end()? "
	          << (test.lower_bound(key) == test.end()) << std::endl;

	/*-------------------------------------------------------------------------------------------*/

	printBound(test, 'A', false);
	printBound(test, '!', false);
	printBound(test, 'j', false);
	std::cout << "Is map::upper_bound(" << key << ") == map::end()? "
	          << (test.upper_bound(key) == test.end()) << std::endl;

	/*-------------------------------------------------------------------------------------------*/

	printRange(test, 'A');
	printRange(test, '!');
	printRange(test, 'j');

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
}

template <typename key, typename value>
void printBound(NAMESPACE::map<key, value> &map, 
                typename NAMESPACE::map<key, value>::key_type k, bool isLower) {
	if (isLower) {
		std::cout << "map::lower_bound(";
	} else {
		std::cout << "map::upper_bound(";
	}
	std::cout << k << ") = " << (isLower ? map.lower_bound(k)->first : map.upper_bound(k)->first) << std::endl;
}

template <typename key, typename value>
void printRange(NAMESPACE::map<key, value> &map, 
                typename NAMESPACE::map<key, value>::key_type k) {
	typedef typename NAMESPACE::map<key, value>::iterator iterator;

	NAMESPACE::pair<iterator, iterator> result = map.equal_range(k);
	std::cout << "map::equal_range(" << k << ").first->first = " << result.first->first << std::endl
	          << "map::equal_range(" << k << ").second->first = " << result.second->first << std::endl;
}
