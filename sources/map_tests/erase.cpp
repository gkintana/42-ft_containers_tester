/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:39:41 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/08 12:44:08 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test;
	insertRandomValues(test, 30);
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
