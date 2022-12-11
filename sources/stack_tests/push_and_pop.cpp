/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:24:28 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 17:33:30 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::stack<int> test;

	pushRandomValues(test, 20);
	printStack(test);
	pushRandomValues(test, test.size() / 4);
	printStack(test);

	popLoop(test, test.size() / 2);
	printStack(test);
	popLoop(test, test.size());
	printStack(test);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
