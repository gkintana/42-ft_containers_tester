/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:58:30 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 01:09:39 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test;
	NAMESPACE::map<int, int>::iterator it = test.end();
	insertRandomValues(test, 20);
	printContent(test);

	for (NAMESPACE::map<int, int>::iterator it = test.begin(); it != test.end(); it++) {
		std::cout << "map::find(" << it->first << ") = " << test.find(it->first)->first << std::endl;
	}

	NAMESPACE::map<int, int>::key_type value = (++(++test.begin()))->first;
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
