/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop_back.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 11:51:39 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

static void pushBackTests(NAMESPACE::vector<int> &vector);
static void pushBackTests(NAMESPACE::vector<std::string> &vector);

template <typename T>
static void popBackTests(NAMESPACE::vector<T> &vector);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int> test;

		pushBackTests(test);
		popBackTests(test);
	}

	{
		NAMESPACE::vector<std::string> test;

		pushBackTests(test);
		popBackTests(test);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

static void pushBackTests(NAMESPACE::vector<int> &vector) {
	pushRandomValues(vector, 10);
	printByOperator(vector);

	pushRandomValues(vector, 0);
	printByOperator(vector);

	pushRandomValues(vector, vector.size());
	printByOperator(vector);

	pushRandomValues(vector, 24);
	printByOperator(vector);
}

static void pushBackTests(NAMESPACE::vector<std::string> &vector) {
	pushString(vector, 10, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean condimentum tellus eget tellus molestie fringilla");
	printByOperator(vector);

	pushString(vector, 0, "Hello World!");
	printByOperator(vector);

	pushString(vector, vector.size(), "It's fascinating that you know all the planets.");
	printByOperator(vector);

	pushString(vector, 24, "I admire your courage but I don't admire your singing ability.");
	printByOperator(vector);
}

template <typename T>
static void popBackTests(NAMESPACE::vector<T> &vector) {
	popLoop(vector, vector.size() / 6);
	printByOperator(vector);

	popLoop(vector, vector.size() / 4);
	printByOperator(vector);

	popLoop(vector, 0);
	printByOperator(vector);

	popLoop(vector, vector.size() / 2);
	printByOperator(vector);

	popLoop(vector, vector.size());
	printByOperator(vector);
}
