/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:26:44 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 16:24:34 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

struct compareStringLength {
	bool operator()(const std::string &lhs, const std::string &rhs) const {
		return lhs.length() < rhs.length();
	}
};

template <typename key, typename value>
static void insertStrings(NAMESPACE::map<key, value> &map);

template <typename key, typename value, typename compare>
static void insertStrings(NAMESPACE::map<key, value, compare> &map);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::map<int, int> test;
		NAMESPACE::map<int, int>::key_compare comp = test.key_comp();

		insertRandomValues(test, 15);
		printByKeyCompare(test, comp);
		printByValueCompare(test);
	}

	{
		NAMESPACE::map<std::string, int, compareStringLength> test;
		NAMESPACE::map<std::string, int, compareStringLength>::key_compare comp = test.key_comp();

		insertStrings(test);
		printByKeyCompare(test, comp);
	}

	{
		NAMESPACE::map<std::string, int> test;

		insertStrings(test);
		printByValueCompare(test);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename key, typename value>
static void insertStrings(NAMESPACE::map<key, value> &map) {
	map.insert(NAMESPACE::make_pair("lorem ipsum dolor sit amet", 0));
	map.insert(NAMESPACE::make_pair("I admire your courage but I don't admire your singing ability.", 1));
	map.insert(NAMESPACE::make_pair("Hello World!", 2));
	map.insert(NAMESPACE::make_pair("1234567890", 3));
	map.insert(NAMESPACE::make_pair("It's fascinating that you know all the planets.", 4));
}

template <typename key, typename value, typename compare>
static void insertStrings(NAMESPACE::map<key, value, compare> &map) {
	map.insert(NAMESPACE::make_pair("lorem ipsum dolor sit amet", 0));
	map.insert(NAMESPACE::make_pair("I admire your courage but I don't admire your singing ability.", 1));
	map.insert(NAMESPACE::make_pair("Hello World!", 2));
	map.insert(NAMESPACE::make_pair("1234567890", 3));
	map.insert(NAMESPACE::make_pair("It's fascinating that you know all the planets.", 4));
}
