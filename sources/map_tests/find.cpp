/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:58:30 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/04 23:59:08 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <map>
#include "map.hpp"
#include <sys/time.h>

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test_map;

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

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
