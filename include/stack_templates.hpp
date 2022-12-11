/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_templates.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:00:56 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 17:33:54 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEMPLATES_HPP
#define STACK_TEMPLATES_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sys/time.h>
#include <stack>
#include "stack.hpp"

template <typename T>
void printStack(NAMESPACE::stack<T> &stack) {
	NAMESPACE::stack<T> temp;

	std::cout << "--------------------------------------------------" << std::endl
	          << "stack.empty() = " << std::boolalpha << stack.empty() << std::endl
	          << "stack.size() = " << stack.size() << std::endl
	          << "Contents:" << std::endl;

	for (; !stack.empty(); stack.pop()) {
		std::cout << "stack.top() = " << stack.top() << std::endl;
		temp.push(stack.top());
	}

	for (; !temp.empty(); temp.pop()) {
		stack.push(temp.top());
	}
}

template <typename T>
void pushRandomValues(NAMESPACE::stack<T> &stack, size_t size) {
	for (size_t i = 0; i < size; i++) {
		stack.push(10000 + (std::rand() % 50000));
	}
}

template <typename T>
void popLoop(NAMESPACE::stack<T> &stack, size_t size) {
	std::cout << "--------------------------------------------------" << std::endl;
	for (size_t i = 0; i < size; i++) {
		std::cout << "Popped = " << stack.top() << std::endl;
		stack.pop();
	}
}

#endif
