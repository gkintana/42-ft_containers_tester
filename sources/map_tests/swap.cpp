/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:17:20 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/10 12:46:05 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::map<int, int> map_1;
		NAMESPACE::map<int, int>::iterator it_begin_1 = map_1.begin();
		NAMESPACE::map<int, int>::iterator it_end_1 = map_1.end();
		insertRandomValues(map_1, 15);
		printContent(map_1);

		NAMESPACE::map<int, int> map_2;
		NAMESPACE::map<int, int>::iterator it_begin_2 = map_2.begin();
		NAMESPACE::map<int, int>::iterator it_end_2 = map_2.end();
		insertRandomValues(map_2, 8);
		printContent(map_2);

		std::cout << std::boolalpha
		          << "Is it_begin_1 == it_begin_2? " << (it_begin_1 == it_begin_2) << std::endl
		          << "Is it_end_1 == it_end_2? " << (it_end_1 == it_end_2) << std::endl
		          << "Is map_1.begin() == it_begin_1? " << (map_1.begin() == it_begin_1) << std::endl
		          << "Is map_1.end() == it_end_1? " << (map_1.end() == it_end_1) << std::endl
		          << "Is map_2.begin() == it_begin_2? " << (map_2.begin() == it_begin_2) << std::endl
		          << "Is map_2.end() == it_end_2? " << (map_2.end() == it_end_2) << std::endl;

		it_begin_1 = map_1.begin();
		it_end_1 = map_1.end();
		it_begin_2 = map_2.begin();
		it_end_2 = map_2.end();

		map_1.swap(map_2);
		printByIterator(map_1, it_begin_2, map_1.end());
		printByIterator(map_2, it_begin_1, map_2.end());

		std::cout << "Is map_1.begin() == it_begin_1? " << (map_1.begin() == it_begin_1) << std::endl
		          << "Is map_1.begin() == it_begin_2? " << (map_1.begin() == it_begin_2) << std::endl
		          << "Is map_2.begin() == it_begin_1? " << (map_2.begin() == it_begin_1) << std::endl
		          << "Is map_2.begin() == it_begin_2? " << (map_2.begin() == it_begin_2) << std::endl;

		NAMESPACE::map<int, int> map_3(map_2);
		NAMESPACE::map<int, int>::iterator it_begin_3 = map_3.begin();

		std::cout << "Is map_3.begin() == it_begin_1? " << (map_3.begin() == it_begin_1) << std::endl
		          << "Is map_3.begin() == it_begin_2? " << (map_3.begin() == it_begin_2) << std::endl;
		        //   << "Is map_3.end() == it_end_1? " << (map_3.end() == it_end_1) << std::endl
		        //   << "Is map_3.end() == it_end_2? " << (map_3.end() == it_end_2) << std::endl;

		map_3.swap(map_1);
		printByIterator(map_1, it_begin_3, map_1.end());
		printByIterator(map_3, it_begin_2, map_3.end());

		map_3.swap(map_2);
		printByIterator(map_2, it_begin_2, map_2.end());
		printByIterator(map_3, it_begin_1, map_3.end());

		map_3.clear();
		printContent(map_1);
		printContent(map_2);
		printContent(map_3);
	}

	{
		NAMESPACE::map<char, std::string> map_1;
		NAMESPACE::map<char, std::string>::iterator it_begin_1 = map_1.begin();
		NAMESPACE::map<char, std::string>::iterator it_end_1 = map_1.end();
		insertValue(map_1, INSERT_BY_MAKE_PAIR, 'b', "I admire your courage but I don't admire your singing ability.");
		insertValue(map_1, INSERT_BY_MAKE_PAIR, '0', "There was a big earthquake last night.");
		insertValue(map_1, INSERT_BY_MAKE_PAIR, ' ', "Tom can't remember all his passwords, so he keeps them in a list disguised as phone numbers.");
		insertValue(map_1, INSERT_BY_MAKE_PAIR, '!', "Let's all just take a moment to breathe, please!");
		insertValue(map_1, INSERT_BY_MAKE_PAIR, '\\', "It's fascinating that you know all the planets.");
		insertValue(map_1, INSERT_BY_MAKE_PAIR, 'q', " Your reputation as an eccentric will rapidly grow in the neighborhood if you're seen walking a pet ostrich on a leash every morning.");
		insertValue(map_1, INSERT_BY_MAKE_PAIR, '^', "Have you heard the news?");

		NAMESPACE::map<char, std::string> map_2;
		NAMESPACE::map<char, std::string>::iterator it_begin_2 = map_2.begin();
		NAMESPACE::map<char, std::string>::iterator it_end_2 = map_2.end();
		insertValue(map_2, INSERT_BY_MAKE_PAIR, 'G', "Lorem ipsum dolor sit amet");
		insertValue(map_2, INSERT_BY_MAKE_PAIR, '@', "");
		insertValue(map_2, INSERT_BY_MAKE_PAIR, '\'', "The quick brown fox jumps over the lazy dog");

		std::cout << "Is it_begin_1 == it_begin_2? " << (it_begin_1 == it_begin_2) << std::endl
		          << "Is it_end_1 == it_end_2? " << (it_end_1 == it_end_2) << std::endl
		          << "Is map_1.begin() == it_begin_1? " << (map_1.begin() == it_begin_1) << std::endl
		          << "Is map_1.end() == it_end_1? " << (map_1.end() == it_end_1) << std::endl
		          << "Is map_2.begin() == it_begin_2? " << (map_2.begin() == it_begin_2) << std::endl
		          << "Is map_2.end() == it_end_2? " << (map_2.end() == it_end_2) << std::endl;

		it_begin_1 = map_1.begin();
		it_end_1 = map_1.end();
		it_begin_2 = map_2.begin();
		it_end_2 = map_2.end();

		map_1.swap(map_2);
		printByIterator(map_1, it_begin_2, map_1.end());
		printByIterator(map_2, it_begin_1, map_2.end());

		std::cout << "Is map_1.begin() == it_begin_1? " << (map_1.begin() == it_begin_1) << std::endl
		          << "Is map_1.begin() == it_begin_2? " << (map_1.begin() == it_begin_2) << std::endl
		          << "Is map_2.begin() == it_begin_1? " << (map_2.begin() == it_begin_1) << std::endl
		          << "Is map_2.begin() == it_begin_2? " << (map_2.begin() == it_begin_2) << std::endl;

		NAMESPACE::map<char, std::string> map_3(map_1);
		NAMESPACE::map<char, std::string>::iterator it_begin_3 = map_3.begin();

		std::cout << "Is map_3.begin() == it_begin_1? " << (map_3.begin() == it_begin_1) << std::endl
		          << "Is map_3.begin() == it_begin_2? " << (map_3.begin() == it_begin_2) << std::endl;
		        //   << "Is map_3.end() == it_end_1? " << (map_3.end() == it_end_1) << std::endl
		        //   << "Is map_3.end() == it_end_2? " << (map_3.end() == it_end_2) << std::endl;

		map_3.swap(map_2);
		printByIterator(map_2, it_begin_3, map_2.end());
		printByIterator(map_3, it_begin_1, map_3.end());

		map_3.clear();
		printContent(map_1);
		printContent(map_2);
		printContent(map_3);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
}
