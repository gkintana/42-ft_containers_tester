/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_performance.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:36:06 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/14 00:18:55 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_PERFORMANCE_HPP
#define VECTOR_PERFORMANCE_HPP

#include <vector_templates.hpp>
#include <chrono>

#define TEST_SIZE    500

template <typename T>
void pushLoop(NAMESPACE::vector<T> &vec, size_t n, typename vectorTester::identity<T>::type value) {
	for (size_t i = 0; i < n; i++) {
		vec.push_back(value);
	}
}

template <typename T>
void popLoop(NAMESPACE::vector<T> &vec, size_t n) {
	for (size_t i = 0; i < n; i++) {
		vec.pop_back();
	}
}


// void pushStrLoop(NAMESPACE::vector<std::string> &vec, size_t n, std::string str) {
// 	for (size_t i = 0; i < n; i++) {
// 		vec.push_back(str);
// 	}
// }

#endif
