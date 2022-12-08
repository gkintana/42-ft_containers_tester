/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:11:14 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/08 13:13:09 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test;
	insertRandomValues(test, 20);
	printContent(test);

	for (NAMESPACE::map<int, int>::iterator it = test.begin(); it != test.end(); it++) {
		std::cout << "map::count(" << it->first << ") = " << test.count(it->first) << std::endl;
	}

	NAMESPACE::map<int, int>::key_type value = 42;
	std::cout << "map::count(" << value << ") = " << test.count(value) << std::endl;
	value = ' ';
	std::cout << "map::count(" << value << ") = " << test.count(value) << std::endl;

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
