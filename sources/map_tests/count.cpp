/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:11:14 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/07 17:14:41 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test;

	insertValue(test, INSERT_BY_PAIR, 2, 20);
	insertValue(test, INSERT_BY_PAIR, 1, 10);
	insertValue(test, INSERT_BY_PAIR, 3, 30);
	insertValue(test, INSERT_BY_MAKE_PAIR, 6, 25);
	insertValue(test, INSERT_BY_MAKE_PAIR, 4, 40);
	insertValue(test, INSERT_BY_MAKE_PAIR, 5, 50);
	printContent(test);

	int value = 3;
	std::cout << "count (" << value << ") = " << test.count(value) << std::endl;

	value = 1;
	std::cout << "count (" << value << ") = " << test.count(value) << std::endl;

	value = 300;
	std::cout << "count (" << value << ") = " << test.count(value) << std::endl;

	value = 'a';
	std::cout << "count (" << value << ") = " << test.count(value) << std::endl;

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
