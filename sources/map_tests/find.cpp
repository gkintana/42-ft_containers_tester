/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:58:30 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/05 21:23:46 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test_map;
	NAMESPACE::map<int, int>::iterator it = test_map.end();

	test_map.insert(NAMESPACE::make_pair(2, 2));
	test_map.insert(NAMESPACE::make_pair(1, 1));
	test_map.insert(NAMESPACE::make_pair(3, 3));
	test_map.insert(NAMESPACE::make_pair(6, 25));
	test_map.insert(NAMESPACE::make_pair(4, 40));
	test_map.insert(NAMESPACE::make_pair(5, 50));

	int value = 3;
	std::cout << "find (" << value << ") = " << test_map.find(value)->first << std::endl;

	value = 1;
	std::cout << "find (" << value << ") = " << test_map.find(value)->first << std::endl;

	value = 300;
	if (test_map.find(value)->first == test_map.end()->first) {
		std::cout << "find (" << value << ") has been safely accessed." << std::endl;
	}

	value = 2;
	std::cout << "Is map::find("<< value << ") == map::end()? "
	          << std::boolalpha << (test_map.find(value) == test_map.end()) << std::endl;
	value = 42;
	std::cout << "Is map::find("<< value << ") == map::end()? "
	          << (test_map.find(value) == test_map.end()) << std::endl
			  << "Is map::find("<< value << ") == it? "
	          << (test_map.find(value) == it) << std::endl;

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
