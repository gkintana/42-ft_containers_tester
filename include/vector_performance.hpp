/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_performance.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:36:06 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/13 13:37:50 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_PERFORMANCE_HPP
#define VECTOR_PERFORMANCE_HPP

#include <vector_templates.hpp>
#include <chrono>

#define VEC_SIZE    42

template <typename T>
static void pushBackLoop(NAMESPACE::vector<T> &vec) {
	for (size_t i = 0; i < VEC_SIZE; i++) {
		vec.push_back(RNG);
	}
}

#endif
