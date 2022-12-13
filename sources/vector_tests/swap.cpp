/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:58:35 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/14 00:09:13 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	// member function swap
	{
		NAMESPACE::vector<int> vector_1;
		NAMESPACE::vector<int>::iterator it_begin_1 = vector_1.begin();
		NAMESPACE::vector<int>::iterator it_end_1 = vector_1.end();
		pushRandomValues(vector_1, 10);
		printByOperator(vector_1);

		NAMESPACE::vector<int> vector_2;
		NAMESPACE::vector<int>::iterator it_begin_2 = vector_2.begin();
		NAMESPACE::vector<int>::iterator it_end_2 = vector_2.end();
		pushRandomValues(vector_2, 7);
		printByOperator(vector_2);

		std::cout << std::boolalpha
		          << "Is vector_1.begin() == it_begin_1? " << (vector_1.begin() == it_begin_1) << std::endl
		          << "Is vector_1.end() == it_end_1? " << (vector_1.end() == it_end_1) << std::endl
		          << "Is vector_2.begin() == it_begin_2? " << (vector_2.begin() == it_begin_2) << std::endl
		          << "Is vector_2.end() == it_end_2? " << (vector_2.end() == it_end_2) << std::endl;

		it_begin_1 = vector_1.begin();
		it_end_1 = vector_1.end();
		it_begin_2 = vector_2.begin();
		it_end_2 = vector_2.end();

		vector_1.swap(vector_2);
		printByIterator(vector_1, it_begin_2, vector_1.end());
		printByIterator(vector_2, it_begin_1, vector_2.end());

		std::cout << "Is vector_1.begin() == it_begin_1? " << (vector_1.begin() == it_begin_1) << std::endl
		          << "Is vector_1.begin() == it_begin_2? " << (vector_1.begin() == it_begin_2) << std::endl
		          << "Is vector_2.begin() == it_begin_1? " << (vector_2.begin() == it_begin_1) << std::endl
		          << "Is vector_2.begin() == it_begin_2? " << (vector_2.begin() == it_begin_2) << std::endl;

		NAMESPACE::vector<int> vector_3(vector_2);
		NAMESPACE::vector<int>::iterator it_begin_3 = vector_3.begin();

		std::cout << "Is vector_3.begin() == it_begin_1? " << (vector_3.begin() == it_begin_1) << std::endl
		          << "Is vector_3.begin() == it_begin_2? " << (vector_3.begin() == it_begin_2) << std::endl;

		vector_3.swap(vector_1);
		printByIterator(vector_1, it_begin_3, vector_1.end());
		printByIterator(vector_3, it_begin_2, vector_3.end());

		vector_3.swap(vector_2);
		printByIterator(vector_2, it_begin_2, vector_2.end());
		printByIterator(vector_3, it_begin_1, vector_3.end());

		vector_3.clear();
		printByIterator(vector_1, vector_1.begin(), vector_1.end());
		printByIterator(vector_2, vector_2.begin(), vector_2.end());
		printByIterator(vector_3, vector_3.begin(), vector_3.end());
	}

	// non-member function swap
	{
		NAMESPACE::vector<std::string> vector_1;
		NAMESPACE::vector<std::string>::iterator it_begin_1 = vector_1.begin();
		NAMESPACE::vector<std::string>::iterator it_end_1 = vector_1.end();
		vector_1.push_back("I admire your courage but I don't admire your singing ability.");
		vector_1.push_back("There was a big earthquake last night.");
		vector_1.push_back("Tom can't remember all his passwords, so he keeps them in a list disguised as phone numbers.");
		vector_1.push_back("Let's all just take a moment to breathe, please!");
		vector_1.push_back("Let's all just take a moment to breathe, please!");
		vector_1.push_back("It's fascinating that you know all the planets.");
		vector_1.push_back(" Your reputation as an eccentric will rapidly grow in the neighborhood if you're seen walking a pet ostrich on a leash every morning.");
		vector_1.push_back("Have you heard the news?");
		printByOperator(vector_1);

		NAMESPACE::vector<std::string> vector_2;
		NAMESPACE::vector<std::string>::iterator it_begin_2 = vector_2.begin();
		NAMESPACE::vector<std::string>::iterator it_end_2 = vector_2.end();
		vector_2.push_back("Lorem ipsum dolor sit amet");
		vector_2.push_back("");
		vector_2.push_back("The quick brown fox jumps over the lazy dog");
		printByOperator(vector_2);

		std::cout << "Is vector_1.begin() == it_begin_1? " << (vector_1.begin() == it_begin_1) << std::endl
		          << "Is vector_1.end() == it_end_1? " << (vector_1.end() == it_end_1) << std::endl
		          << "Is vector_2.begin() == it_begin_2? " << (vector_2.begin() == it_begin_2) << std::endl
		          << "Is vector_2.end() == it_end_2? " << (vector_2.end() == it_end_2) << std::endl;

		it_begin_1 = vector_1.begin();
		it_end_1 = vector_1.end();
		it_begin_2 = vector_2.begin();
		it_end_2 = vector_2.end();

		NAMESPACE::swap(vector_1, vector_2);
		printByIterator(vector_1, it_begin_2, vector_1.end());
		printByIterator(vector_2, it_begin_1, vector_2.end());

		std::cout << "Is vector_1.begin() == it_begin_1? " << (vector_1.begin() == it_begin_1) << std::endl
		          << "Is vector_1.begin() == it_begin_2? " << (vector_1.begin() == it_begin_2) << std::endl
		          << "Is vector_2.begin() == it_begin_1? " << (vector_2.begin() == it_begin_1) << std::endl
		          << "Is vector_2.begin() == it_begin_2? " << (vector_2.begin() == it_begin_2) << std::endl;

		NAMESPACE::vector<std::string> vector_3(vector_1);
		NAMESPACE::vector<std::string>::iterator it_begin_3 = vector_3.begin();

		std::cout << "Is vector_3.begin() == it_begin_1? " << (vector_3.begin() == it_begin_1) << std::endl
		          << "Is vector_3.begin() == it_begin_2? " << (vector_3.begin() == it_begin_2) << std::endl;

		NAMESPACE::swap(vector_3, vector_2);
		printByIterator(vector_2, it_begin_3, vector_2.end());
		printByIterator(vector_3, it_begin_1, vector_3.end());

		vector_3.clear();
		printByIterator(vector_1, vector_1.begin(), vector_1.end());
		printByIterator(vector_2, vector_2.begin(), vector_2.end());
		printByIterator(vector_3, vector_3.begin(), vector_3.end());
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
