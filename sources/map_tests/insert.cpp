/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:58:40 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 01:19:53 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

// #if __APPLE__
int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::map<int, int> test;

		insertRandomValues(test, 10);
		printContent(test);
		insertRandomValues(test, 20);
		printContent(test);
	}

	{
		NAMESPACE::map<int, std::string> test;

		insertValue(test, INSERT_BY_MAKE_PAIR, 123, "Lorem ipsum dolor sit amet");
		insertValue(test, INSERT_BY_MAKE_PAIR, 42, "Hello world!");
		insertValue(test, INSERT_BY_MAKE_PAIR, 8, "The quick brown fox jumps over the lazy dog");
		printContent(test);

		insertValue(test, ++(++(test.begin())), 90, "😊");
		insertValue(test, test.begin(), 5, "");
		printContent(test);

		/*---------------------------------------------------------------------------------------*/

		NAMESPACE::map<int, std::string> range;

		range.insert(test.begin(), test.begin());
		range.insert(test.end(), test.end());
		printContent(range);

		range.insert(++(++test.begin()), --test.end());
		range.insert(test.begin(), test.end());
		printContent(range);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
// #endif

// #if __linux__
// int main() {
// 	timeval exec_time;
// 	gettimeofday(&exec_time, NULL);
// 	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

// 	{
// 		NAMESPACE::map<int, int> test;

// 		insertRandomValues(test, 10);
// 		printContent(test);
// 		insertRandomValues(test, 20);
// 		printContent(test);
// 	}

// 	{
// 		NAMESPACE::map<int, std::string> test;

// 		insertValue(test, INSERT_BY_MAKE_PAIR, 123, "Lorem ipsum dolor sit amet");
// 		insertValue(test, INSERT_BY_MAKE_PAIR, 42, "Hello world!");
// 		insertValue(test, INSERT_BY_MAKE_PAIR, 8, "The quick brown fox jumps over the lazy dog");
// 		printContent(test);

// 		insertValue(test, --(--(--test.begin())), 9, "🙃🙃🙃");
// 		insertValue(test, ++(++(test.end())), 7825, "😉😉😉");
// 		insertValue(test, ++(++(test.begin())), 90, "😊");
//		insertValue(test, test.begin(), 5, "");
// 		printContent(test);

// 		/*---------------------------------------------------------------------------------------*/

// 		NAMESPACE::map<int, std::string> range;

// 		range.insert(test.begin(), test.begin());
// 		range.insert(test.end(), test.end());
// 		printContent(range);

// 		range.insert(++(++test.begin()), --test.end());
// 		range.insert(test.begin(), test.end());
// 		printContent(range);
// 	}

// 	gettimeofday(&exec_time, NULL);
// 	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
// 	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
// 	return 0;
// }
// #endif
