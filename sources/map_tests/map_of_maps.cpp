/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_of_maps.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:18:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/08 23:57:48 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

template <typename key1, typename key2, typename value>
void printMapOfMaps(NAMESPACE::map<key1, NAMESPACE::map<key2, value> > &map);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<std::string, NAMESPACE::map<int, int> > test;
	NAMESPACE::map<int, int> value_for_test[5];

	insertRandomValues(value_for_test[0], 5);
	insertRandomValues(value_for_test[1], 10);
	insertRandomValues(value_for_test[2], 15);
	insertRandomValues(value_for_test[3], 20);
	insertRandomValues(value_for_test[4], 25);

	test.insert(NAMESPACE::make_pair("Lorem ipsum dolor sit amet.", value_for_test[0]));
	test.insert(NAMESPACE::make_pair("🚀🚀🚀", value_for_test[1]));
	test.insert(NAMESPACE::make_pair("Why am I doing this 😭", value_for_test[2]));
	test.insert(NAMESPACE::make_pair("42 Abu Dhabi", value_for_test[3]));
	test.insert(NAMESPACE::make_pair("The quick brown fox jumps over the lazy dog", value_for_test[4]));
	printMapOfMaps(test);

	NAMESPACE::map<std::string, NAMESPACE::map<int, int> > clone = test;
	clone.erase(clone.begin());
	clone.erase(++clone.begin());
	clone.insert(NAMESPACE::make_pair("It's fascinating that you know all the planets.", value_for_test[4]));
	clone.insert(NAMESPACE::make_pair("I admire your courage but I don't admire your singing ability.", value_for_test[2]));
	printMapOfMaps(clone);

	test.swap(clone);
	printMapOfMaps(test);
	printMapOfMaps(clone);

	clone.erase(clone.begin(), clone.end());
	test.clear();

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename key1, typename key2, typename value>
void printMapOfMaps(NAMESPACE::map<key1, NAMESPACE::map<key2, value> > &map) {
	printMapInfo(map);
	for (typename NAMESPACE::map<key1, NAMESPACE::map<key2, value> >::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << "Key = " << it->first << std::endl;
		for (typename NAMESPACE::map<key2, value>::iterator inner = it->second.begin(); inner != it->second.end(); inner++) {
			std::cout << "Value->first = " << inner->first << "  |  Value->second = " << inner->second << std::endl;
		}
	}
}
