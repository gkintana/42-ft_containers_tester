/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:39:41 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/07 22:19:10 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

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
	printContent(test);
	
	NAMESPACE::map<int, int> clone(test);
	printContent(clone);

	clone.erase(1234);
	clone.erase(2339);
	clone.erase(9876);
	clone.erase(3919);
	printContent(clone);

	clone.erase(clone.begin(), clone.begin());
	clone.erase(clone.end(), clone.end());
	printContent(clone);

	clone.swap(test);
	printContent(test);
	printContent(clone);

	clone.erase(++(++(clone.begin())));
	clone.erase(++(clone.begin()));
	clone.erase(--clone.end());
	printContent(clone);

	clone.erase(++(++clone.begin()), clone.end());
	printContent(clone);

	test.erase(test.begin(), test.end());
	printContent(test);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
