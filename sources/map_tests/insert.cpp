/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:58:40 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/05 21:15:52 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

#if __linux__
int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	// map<int, int>
	{
		NAMESPACE::map<int, int> test_map;

		test_map.insert(NAMESPACE::make_pair(1, 10));
		test_map.insert(NAMESPACE::make_pair(2, 20));
		test_map.insert(NAMESPACE::make_pair(3, 30));
		printContent(test_map);

		test_map.insert(NAMESPACE::pair<int, int>(2, 2));
		test_map.insert(NAMESPACE::pair<int, int>(1, 1));
		test_map.insert(NAMESPACE::pair<int, int>(3, 3));
		test_map.insert(NAMESPACE::pair<int, int>(6, 25));
		test_map.insert(NAMESPACE::pair<int, int>(4, 40));
		test_map.insert(NAMESPACE::pair<int, int>(5, 50));
		printContent(test_map);
	}

	// map<int, std::string>
	{
		NAMESPACE::map<int, std::string> test_map;

		test_map.insert(NAMESPACE::make_pair(123, "Lorem ipsum dolor sit amet"));
		test_map.insert(NAMESPACE::make_pair(42, "Hello world!"));
		test_map.insert(NAMESPACE::make_pair(8, "The quick brown fox jumps over the lazy dog"));
		printContent(test_map);

		test_map.insert((--(--(--test_map.begin()))), NAMESPACE::make_pair(9, "🙃🙃🙃"));
		test_map.insert(++(++(test_map.end())), NAMESPACE::make_pair(7825, "😉😉😉"));
		test_map.insert(++(++(test_map.begin())), NAMESPACE::make_pair(90, "😊"));
		printContent(test_map);

		/*---------------------------------------------------------------------------------------*/

		NAMESPACE::map<int, std::string> map_range;

		map_range.insert(test_map.begin(), test_map.begin());
		map_range.insert(test_map.end(), test_map.end());
		printContent(map_range);

		map_range.insert(++(++test_map.begin()), --test_map.end());
		map_range.insert(test_map.begin(), test_map.end());
		printContent(map_range);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
#endif


#if __APPLE__
int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	// map<int, int>
	{
		NAMESPACE::map<int, int> test_map;

		test_map.insert(NAMESPACE::make_pair(1, 10));
		test_map.insert(NAMESPACE::make_pair(2, 20));
		test_map.insert(NAMESPACE::make_pair(3, 30));
		printContent(test_map);

		test_map.insert(NAMESPACE::pair<int, int>(2, 2));
		test_map.insert(NAMESPACE::pair<int, int>(1, 1));
		test_map.insert(NAMESPACE::pair<int, int>(3, 3));
		test_map.insert(NAMESPACE::pair<int, int>(6, 25));
		test_map.insert(NAMESPACE::pair<int, int>(4, 40));
		test_map.insert(NAMESPACE::pair<int, int>(5, 50));
		printContent(test_map);
	}

	// map<int, std::string>
	{
		NAMESPACE::map<int, std::string> test_map;

		test_map.insert(NAMESPACE::make_pair(123, "Lorem ipsum dolor sit amet"));
		test_map.insert(NAMESPACE::make_pair(42, "Hello world!"));
		test_map.insert(NAMESPACE::make_pair(8, "The quick brown fox jumps over the lazy dog"));
		printContent(test_map);

		test_map.insert(++(++(test_map.begin())), NAMESPACE::make_pair(90, "😊"));
		printContent(test_map);

		/*---------------------------------------------------------------------------------------*/

		NAMESPACE::map<int, std::string> map_range;

		map_range.insert(test_map.begin(), test_map.begin());
		map_range.insert(test_map.end(), test_map.end());
		printContent(map_range);

		map_range.insert(++(++test_map.begin()), --test_map.end());
		map_range.insert(test_map.begin(), test_map.end());
		printContent(map_range);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
#endif
