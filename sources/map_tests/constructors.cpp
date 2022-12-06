/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:39:57 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/06 13:05:30 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<int, std::string> test;
	printContent(test);

	insertValue(test, INSERT_BY_MAKE_PAIR, -7395, "Hello world!");
	insertValue(test, INSERT_BY_MAKE_PAIR, -8637, "Lorem ipsum dolor sit amet, consectetur adipiscing elit");
	insertValue(test, INSERT_BY_MAKE_PAIR, -6296, "");
	insertValue(test, INSERT_BY_MAKE_PAIR, 9756, "His ultimate dream fantasy consisted of being content and sleeping eight hours in a row");
	insertValue(test, INSERT_BY_MAKE_PAIR, 733, "ft_containers");
	insertValue(test, INSERT_BY_MAKE_PAIR, -527, "The quick brown fox jumps over the lazy dog");
	printContent(test);

	{
		NAMESPACE::map<int, std::string> test_copy1(test);
		NAMESPACE::map<int, std::string> test_copy2 = test;
		printContent(test_copy1);
		printContent(test_copy2);
		test.clear();
		printContent(test);
		printContent(test_copy1);
		printContent(test_copy2);
	}

	insertValue(test, INSERT_BY_MAKE_PAIR, -7395, "Hello world!");
	insertValue(test, INSERT_BY_MAKE_PAIR, -8637, "Lorem ipsum dolor sit amet, consectetur adipiscing elit");
	insertValue(test, INSERT_BY_MAKE_PAIR, -6296, "");
	insertValue(test, INSERT_BY_MAKE_PAIR, 9756, "His ultimate dream fantasy consisted of being content and sleeping eight hours in a row");
	insertValue(test, INSERT_BY_MAKE_PAIR, 733, "ft_containers");
	insertValue(test, INSERT_BY_MAKE_PAIR, -527, "The quick brown fox jumps over the lazy dog");

	{
		NAMESPACE::map<int, std::string> test_assignment;
		test_assignment = test;
		printContent(test_assignment);
		test.clear();
		printContent(test);
		printContent(test_assignment);
	}

	insertValue(test, INSERT_BY_MAKE_PAIR, -7395, "Hello world!");
	insertValue(test, INSERT_BY_MAKE_PAIR, -8637, "Lorem ipsum dolor sit amet, consectetur adipiscing elit");
	insertValue(test, INSERT_BY_MAKE_PAIR, -6296, "");
	insertValue(test, INSERT_BY_MAKE_PAIR, 9756, "His ultimate dream fantasy consisted of being content and sleeping eight hours in a row");
	insertValue(test, INSERT_BY_MAKE_PAIR, 733, "ft_containers");
	insertValue(test, INSERT_BY_MAKE_PAIR, -527, "The quick brown fox jumps over the lazy dog");

	{
		NAMESPACE::map<int, std::string> test_range(test.begin(), test.end());
		printContent(test_range);
		test.clear();
		printContent(test);
		printContent(test_range);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
