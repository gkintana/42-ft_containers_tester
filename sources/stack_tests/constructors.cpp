/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:58:19 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 17:41:19 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::stack<int> test;

	pushRandomValues(test, 5);
	printStack(test);

	NAMESPACE::stack<int> clone(test);
	pushRandomValues(clone, 5);
	printStack(clone);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
