/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:58:30 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/06 09:47:55 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test;
	NAMESPACE::map<int, int>::iterator it = test.end();

	insertValue(test, INSERT_BY_PAIR, 2, 20);
	insertValue(test, INSERT_BY_PAIR, 1, 10);
	insertValue(test, INSERT_BY_PAIR, 3, 30);
	insertValue(test, INSERT_BY_MAKE_PAIR, 6, 25);
	insertValue(test, INSERT_BY_MAKE_PAIR, 4, 40);
	insertValue(test, INSERT_BY_MAKE_PAIR, 5, 50);
	printContent(test);

	int value = 3;
	std::cout << "find (" << value << ") = " << test.find(value)->first << std::endl;

	value = 1;
	std::cout << "find (" << value << ") = " << test.find(value)->first << std::endl;

	value = 300;
	if (test.find(value)->first == test.end()->first) {
		std::cout << "find (" << value << ") has been safely accessed." << std::endl;
	}

	value = 2;
	std::cout << "Is map::find("<< value << ") == map::end()? "
	          << std::boolalpha << (test.find(value) == test.end()) << std::endl;
	value = 42;
	std::cout << "Is map::find("<< value << ") == map::end()? "
	          << (test.find(value) == test.end()) << std::endl
	          << "Is map::find("<< value << ") == it? "
	          << (test.find(value) == it) << std::endl;

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
