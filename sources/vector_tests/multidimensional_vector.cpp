/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multidimensional_vector.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:20:48 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 13:55:49 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

#define RNG    10 + (std::rand() % 50)

template <typename T>
static void printMultiDimensinalVector(NAMESPACE::vector<NAMESPACE::vector<NAMESPACE::vector<T> > > &vector);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	size_t vector_size = 5;
	NAMESPACE::vector<int> inner[vector_size];

	for (size_t i = 0; i < vector_size; i++) {
		pushRandomValues(inner[i], RNG);
	}

	NAMESPACE::vector<NAMESPACE::vector<int> > middle;
	for (size_t i = 0; i < vector_size; i++) {
		middle.push_back(inner[i]);
	}

	NAMESPACE::vector<NAMESPACE::vector<NAMESPACE::vector<int> > > outer;
	for (size_t i = 0; i < vector_size; i++) {
		outer.push_back(middle);
	}
	printMultiDimensinalVector(outer);

	NAMESPACE::vector<NAMESPACE::vector<NAMESPACE::vector<int> > > outer_clone = outer;
	outer.clear();
	printMultiDimensinalVector(outer);
	printMultiDimensinalVector(outer_clone);


	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename T>
static void printMultiDimensinalVector(NAMESPACE::vector<NAMESPACE::vector<NAMESPACE::vector<T> > > &vector) {
	std::cout << "--------------------------------------------------" << std::endl << std::boolalpha
	          << "vector::empty() = " << vector.empty() << std::endl
	          << "vector::size() = " << vector.size() << std::endl
	          << "vector::max_size() = " << vector.max_size() << std::endl
	          << "Contents:" << std::endl;
	for (size_t i = 0; i < vector.size(); i++) {
		for (size_t j = 0; j < vector[i].size(); j++) {
			for (size_t k = 0; k < vector[i][j].size(); k++) {
				std::cout << "vector[" << i << "][" << j << "][" << k << "] = " << vector[i][j][k] << std::endl;
			}
		}
	}
}
