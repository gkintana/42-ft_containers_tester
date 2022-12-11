/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_templates.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:11:55 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 14:06:03 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEMPLATES_HPP
#define VECTOR_TEMPLATES_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sys/time.h>
#include <vector>
#include "vector.hpp"

/*---------------------------------------------------------------------------------------------------------*/

template <typename T>
void printVectorInfo(NAMESPACE::vector<T> &vector) {
	std::cout << "--------------------------------------------------" << std::endl << std::boolalpha
	          << "vector::empty() = " << vector.empty() << std::endl
	          << "vector::size() = " << vector.size() << std::endl
	          << "vector::max_size() = " << vector.max_size() << std::endl
	          << "Contents:" << std::endl;
}

template <typename T>
void printVectorInfo(const NAMESPACE::vector<T> &vector) {
	std::cout << "--------------------------------------------------" << std::endl << std::boolalpha
	          << "vector::empty() = " << vector.empty() << std::endl
	          << "vector::size() = " << vector.size() << std::endl
	          << "vector::max_size() = " << vector.max_size() << std::endl
	          << "Contents:" << std::endl;
}

template <typename T>
void printByOperator(NAMESPACE::vector<T> &vector) {
	printVectorInfo(vector);
	for (size_t i = 0; i < vector.size(); i++) {
		std::cout << "vector[" << i << "] = " << vector[i] << std::endl;
	}
}

template <typename T>
void printByIterator(NAMESPACE::vector<T> &vector,
                     typename NAMESPACE::vector<T>::iterator start,
                     typename NAMESPACE::vector<T>::iterator end) {
	printVectorInfo(vector);
	for (typename NAMESPACE::vector<T>::iterator iter = start; iter != end; iter++) {
		std::cout << "*iter = " << *iter << std::endl;
	}
}

template <typename T>
void printByIterator(const NAMESPACE::vector<T> &vector,
                     typename NAMESPACE::vector<T>::const_iterator start,
                     typename NAMESPACE::vector<T>::const_iterator end) {
	printVectorInfo(vector);
	for (typename NAMESPACE::vector<T>::const_iterator iter = start; iter != end; iter++) {
		std::cout << "*iter = " << *iter << std::endl;
	}
}

template <typename T>
void printByReverseIterator(NAMESPACE::vector<T> &vector,
                            typename NAMESPACE::vector<T>::reverse_iterator start,
                            typename NAMESPACE::vector<T>::reverse_iterator end) {
	printVectorInfo(vector);
	for (typename NAMESPACE::vector<T>::reverse_iterator iter = start; iter != end; iter--) {
		std::cout << "*iter = " << *iter << std::endl;
	}
}

template <typename T>
void printByReverseIterator(const NAMESPACE::vector<T> &vector,
                            typename NAMESPACE::vector<T>::const_reverse_iterator start,
                            typename NAMESPACE::vector<T>::const_reverse_iterator end) {
	printVectorInfo(vector);
	for (typename NAMESPACE::vector<T>::const_reverse_iterator iter = start; iter != end; iter--) {
		std::cout << "*iter = " << *iter << std::endl;
	}
}

/*---------------------------------------------------------------------------------------------------------*/

template <typename T>
void capacityExceptionCheck(NAMESPACE::vector<T> &vector, size_t new_size, bool is_resize) {
	try {
		is_resize ? vector.resize(new_size) : vector.reserve(new_size);
	} catch (std::exception &e) {
		std::cout << "Caught exception" << std::endl;
	}
}

template <typename T>
void atExceptionCheck(NAMESPACE::vector<T> &vector, size_t n) {
	try {
		std::cout << "vector.at(" << n << ") = " << vector.at(n) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Caught exception" << std::endl;
	}
}

/*---------------------------------------------------------------------------------------------------------*/

template <typename T>
void pushRandomValues(NAMESPACE::vector<T> &vector, size_t size) {
	for (size_t i = 0; i < size; i++) {
		vector.push_back(10000 + (std::rand() % 50000));
	}
}

void pushString(NAMESPACE::vector<std::string> &vector, size_t size, std::string str) {
	for (size_t i = 0; i < size; i++) {
		vector.push_back(str);
	}
}

template <typename T>
void popLoop(NAMESPACE::vector<T> &vector, size_t size) {
	for (size_t i = 0; i < size; i++) {
		vector.pop_back();
	}
}

#endif
