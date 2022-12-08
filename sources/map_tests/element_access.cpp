/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:18:14 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/08 14:01:52 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

template <typename key, typename value>
void mapAtExceptionCheck(NAMESPACE::map<key, value> &map,
                         typename NAMESPACE::map<key, value>::key_type k);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, int> test;
	insertRandomValues(test, 30);

	for (NAMESPACE::map<int, int>::iterator it = test.begin(); it != test.end(); it++) {
		std::cout << "map::at(" << it->first << ") = " << test.at(it->first) << "\t|\t"
		          << "map::operator[" << it->first << "] = " << test[it->first] << std::endl;
	}

	for (size_t i = 0; i < 30; i++) {
		mapAtExceptionCheck(test, 9900 + (std::rand() % 20000));
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename key, typename value>
void mapAtExceptionCheck(NAMESPACE::map<key, value> &map,
                         typename NAMESPACE::map<key, value>::key_type k) {
	try {
		std::cout << "map::at(" << k << ") = " << map.at(k) << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << "Caught an out_of_range exception" << std::endl;
	}
}
