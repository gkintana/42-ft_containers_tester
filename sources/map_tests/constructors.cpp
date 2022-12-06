/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:39:57 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/06 15:05:16 by gkintana         ###   ########.fr       */
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
		NAMESPACE::map<int, std::string> clone(test.begin(), test.end());
		NAMESPACE::map<int, std::string> copy1(clone);
		NAMESPACE::map<int, std::string> copy2 = clone;
		printContent(copy1);
		printContent(copy2);
		clone.clear();
		printContent(clone);
		printContent(copy1);
		printContent(copy2);
	}

	{
		NAMESPACE::map<int, std::string> clone(test.begin(), test.end());
		NAMESPACE::map<int, std::string> assignment;
		assignment = clone;
		printContent(assignment);
		clone.clear();
		printContent(clone);
		printContent(assignment);
	}

	{
		NAMESPACE::map<int, std::string> range(test.begin(), test.end());
		printContent(range);
		test.clear();
		printContent(test);
		printContent(range);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
