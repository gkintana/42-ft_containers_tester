/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multidimensional_stack.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:07:07 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 21:26:11 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_templates.hpp"

#define RNG    10 + (std::rand() % 50)

template <typename T>
static void printMultiDimensinalStack(NAMESPACE::stack<NAMESPACE::stack<NAMESPACE::stack<T> > > &stack);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	size_t stack_size = 5;
	NAMESPACE::stack<int> inner[stack_size];
	for (size_t i = 0; i < stack_size; i++) {
		pushRandomValues(inner[i], RNG);
	}

	NAMESPACE::stack<NAMESPACE::stack<int> > middle;
	for (size_t i = 0; i < stack_size; i++) {
		middle.push(inner[i]);
	}

	NAMESPACE::stack<NAMESPACE::stack<NAMESPACE::stack<int> > > outer;
	for (size_t i = 0; i < stack_size; i++) {
		outer.push(middle);
	}
	printMultiDimensinalStack(outer);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename T>
static void printMultiDimensinalStack(NAMESPACE::stack<NAMESPACE::stack<NAMESPACE::stack<T> > > &stack) {
	std::cout << "--------------------------------------------------" << std::endl << std::boolalpha
	          << "stack.empty() = " << stack.empty() << std::endl
	          << "stack.size() = " << stack.size() << std::endl
	          << "stack.top().size() = " << stack.top().size() << std::endl
	          << "stack.top().top().size() = " << stack.top().top().size() << std::endl
	          << "Contents:" << std::endl;
	for (; !stack.empty(); stack.pop()) {
		for (; !stack.top().empty(); stack.top().pop()) {
			for (; !stack.top().top().empty(); stack.top().top().pop()) {
				std::cout << stack.top().top().top() << std::endl;
			}
		}
	}
}
