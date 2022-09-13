/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_03_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:22:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/13 17:24:25 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_performance.hpp>

template <typename T>
static void beginCases(NAMESPACE::vector<T> &vec) {
	vec.begin() + 0;
	vec.begin() + vec.size() / 2;
	vec.begin() + vec.size() - 1;
}

template <typename T>
static void beginCases(const NAMESPACE::vector<T> &vec) {
	vec.begin() + 0;
	vec.begin() + vec.size() / 2;
	vec.begin() + vec.size() - 1;
}

template <typename T>
static void endCases(NAMESPACE::vector<T> &vec) {
	vec.end() - 1;
	vec.end() - vec.size() / 2;
	vec.end() - vec.size();
}

template <typename T>
static void endCases(const NAMESPACE::vector<T> &vec) {
	vec.end() - 1;
	vec.end() - vec.size() / 2;
	vec.end() - vec.size();
}

#define ITER          typename NAMESPACE::vector<T>::iterator
#define C_ITER        typename NAMESPACE::vector<T>::const_iterator

template <typename T>
static void iteratorLoop(NAMESPACE::vector<T> &vec, ITER start, ITER end) {
	(void)vec;
	for (ITER iter = start; iter != end; iter++) {
		// std::cout << *iter << std::endl;
	}
}

template <typename T>
static void iteratorLoop(const NAMESPACE::vector<T> &vec, C_ITER start, C_ITER end) {
	(void)vec;
	for (C_ITER iter = start; iter != end; iter++) {}
}

template <typename T>
static void iterLoopCases(NAMESPACE::vector<T> &vec) {
	iteratorLoop(vec, vec.begin(), vec.end());
	iteratorLoop(vec, vec.begin() + (vec.size() / 2), vec.end());
	iteratorLoop(vec, vec.begin() + (vec.size() - 1), vec.end());
	iteratorLoop(vec, vec.begin() + vec.size(), vec.end());
	iteratorLoop(vec, vec.begin(), vec.end() - (vec.size() / 4));
	iteratorLoop(vec, vec.begin(), vec.end() - (vec.size() / 2));
	iteratorLoop(vec, vec.begin(), vec.end() - (vec.size() - 1));
	iteratorLoop(vec, vec.begin(), vec.end() - vec.size());
	iteratorLoop(vec, vec.begin() + (vec.size() / 4), vec.end() - (vec.size() / 2));
	iteratorLoop(vec, vec.begin() + (vec.size() / 3), vec.end() - (vec.size() / 3));
	iteratorLoop(vec, vec.begin() + (vec.size() / 2), vec.end() - (vec.size() / 4));
	iteratorLoop(vec, vec.end(), vec.end());
	iteratorLoop(vec, vec.end() - vec.size(), vec.end());
	iteratorLoop(vec, vec.end() - (vec.size() / 2), vec.end());
	iteratorLoop(vec, vec.end() - (vec.size() / 2), vec.end() - (vec.size() / 4));
}

template <typename T>
static void iterLoopCases(const NAMESPACE::vector<T> &vec) {
	iteratorLoop(vec, vec.begin(), vec.end());
	iteratorLoop(vec, vec.begin() + (vec.size() / 2), vec.end());
	iteratorLoop(vec, vec.begin() + (vec.size() - 1), vec.end());
	iteratorLoop(vec, vec.begin() + vec.size(), vec.end());
	iteratorLoop(vec, vec.begin(), vec.end() - (vec.size() / 4));
	iteratorLoop(vec, vec.begin(), vec.end() - (vec.size() / 2));
	iteratorLoop(vec, vec.begin(), vec.end() - (vec.size() - 1));
	iteratorLoop(vec, vec.begin(), vec.end() - vec.size());
	iteratorLoop(vec, vec.begin() + (vec.size() / 4), vec.end() - (vec.size() / 2));
	iteratorLoop(vec, vec.begin() + (vec.size() / 3), vec.end() - (vec.size() / 3));
	iteratorLoop(vec, vec.begin() + (vec.size() / 2), vec.end() - (vec.size() / 4));
	iteratorLoop(vec, vec.end(), vec.end());
	iteratorLoop(vec, vec.end() - vec.size(), vec.end());
	iteratorLoop(vec, vec.end() - (vec.size() / 2), vec.end());
	iteratorLoop(vec, vec.end() - (vec.size() / 2), vec.end() - (vec.size() / 4));
}

template <typename T>
static void rbeginCases(NAMESPACE::vector<T> &vec) {
	vec.rbegin() + 0;
	vec.rbegin() + vec.size() / 2;
	vec.rbegin() + vec.size() - 1;
}

template <typename T>
static void rbeginCases(const NAMESPACE::vector<T> &vec) {
	vec.rbegin() + 0;
	vec.rbegin() + vec.size() / 2;
	vec.rbegin() + vec.size() - 1;
}

template <typename T>
static void rendCases(NAMESPACE::vector<T> &vec) {
	vec.rend() - 1;
	vec.rend() - vec.size() / 2;
	vec.rend() - vec.size() - 1;
}

template <typename T>
static void rendCases(const NAMESPACE::vector<T> &vec) {
	vec.rend() - 1;
	vec.rend() - vec.size() / 2;
	vec.rend() - vec.size() - 1;
}

#define REV_ITER      typename NAMESPACE::vector<T>::reverse_iterator
#define C_REV_ITER    typename NAMESPACE::vector<T>::const_reverse_iterator

template <typename T>
static void revIterLoop(NAMESPACE::vector<T> &vec, REV_ITER start, REV_ITER end) {
	(void)vec;
	for (REV_ITER iter = start; iter != end; iter--) {
		// std::cout << *iter << std::endl;
	}
}

template <typename T>
static void revIterLoop(const NAMESPACE::vector<T> &vec, C_REV_ITER start, C_REV_ITER end) {
	(void)vec;
	for (C_REV_ITER iter = start; iter != end; iter--) {}
}

template <typename T>
static void revIterLoopCases(NAMESPACE::vector<T> &vec) {
	revIterLoop(vec, vec.rend() - 1, vec.rbegin());
	revIterLoop(vec, vec.rend() - (vec.size() / 2), vec.rbegin());
	revIterLoop(vec, vec.rend() - (vec.size() - 1), vec.rbegin());
	revIterLoop(vec, vec.rend() - vec.size(), vec.rbegin());
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() / 4));
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() / 3));
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() / 2));
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() - 1));
	revIterLoop(vec, vec.rend() - (vec.size() / 4), vec.rbegin() + (vec.size() / 2));
	revIterLoop(vec, vec.rend() - (vec.size() / 3), vec.rbegin() + (vec.size() / 3));
	revIterLoop(vec, vec.rend() - (vec.size() / 2), vec.rbegin() + (vec.size() / 4));
	revIterLoop(vec, vec.rbegin() + 1, vec.rbegin());
	revIterLoop(vec, vec.rbegin() + (vec.size() - 1), vec.rbegin());
	revIterLoop(vec, vec.rbegin() + (vec.size() / 2), vec.rbegin());
	revIterLoop(vec, vec.rbegin() + (vec.size() / 2), vec.rbegin() + (vec.size() / 4));
}

template <typename T>
static void revIterLoopCases(const NAMESPACE::vector<T> &vec) {
	revIterLoop(vec, vec.rend() - 1, vec.rbegin());
	revIterLoop(vec, vec.rend() - (vec.size() / 2), vec.rbegin());
	revIterLoop(vec, vec.rend() - (vec.size() - 1), vec.rbegin());
	revIterLoop(vec, vec.rend() - vec.size(), vec.rbegin());
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() / 4));
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() / 3));
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() / 2));
	revIterLoop(vec, vec.rend() - 1, vec.rbegin() + (vec.size() - 1));
	revIterLoop(vec, vec.rend() - (vec.size() / 4), vec.rbegin() + (vec.size() / 2));
	revIterLoop(vec, vec.rend() - (vec.size() / 3), vec.rbegin() + (vec.size() / 3));
	revIterLoop(vec, vec.rend() - (vec.size() / 2), vec.rbegin() + (vec.size() / 4));
	revIterLoop(vec, vec.rbegin() + 1, vec.rbegin());
	revIterLoop(vec, vec.rbegin() + (vec.size() - 1), vec.rbegin());
	revIterLoop(vec, vec.rbegin() + (vec.size() / 2), vec.rbegin());
	revIterLoop(vec, vec.rbegin() + (vec.size() / 2), vec.rbegin() + (vec.size() / 4));
}

int array[] = { 16801, 19817, 48952, 20130, 73915, 23176, 42669, 82132, 42510, 54383,
                81435, 2480, 46371, 64482, 89407, 5378, 46018, 33244, 16355, 88450,
                95943, 88707, 14117, 11984, 42966, 4000, 28060, 78251, 93742, 39744, };

int main() {
	using std::chrono::high_resolution_clock;
    using std::chrono::duration;
	auto start = high_resolution_clock::now();


	std::srand(time(NULL));
	// Begin Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		beginCases(vec);
	}
	// Const Begin Tests
	{
		const NAMESPACE::vector<int> vec(array, array + (sizeof(array) / sizeof(int)));
		beginCases(vec);
	}
	// End Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		endCases(vec);
	}
	// Const End Tests
	{
		const NAMESPACE::vector<int> vec(array, array + (sizeof(array) / sizeof(int)));
		endCases(vec);
	}
	// Iterator Loop Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		iterLoopCases(vec);
	}
	// Const Iterator Loop Tests
	{
		const NAMESPACE::vector<int> vec(array, array + (sizeof(array) / sizeof(int)));
		iterLoopCases(vec);
	}
	// Rbegin Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		rbeginCases(vec);
	}
	// Const Rbegin Tests
	{
		const NAMESPACE::vector<int> vec(array, array + (sizeof(array) / sizeof(int)));
		rbeginCases(vec);
	}
	// Rend Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		rendCases(vec);
	}
	// Const Rend Tests
	{
		const NAMESPACE::vector<int> vec(array, array + (sizeof(array) / sizeof(int)));
		rendCases(vec);
	}
	// Reverse Iterator Loop Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		revIterLoopCases(vec);
	}
	// Const Reverse Iterator Loop Tests
	{
		const NAMESPACE::vector<int> vec(array, array + (sizeof(array) / sizeof(int)));
		revIterLoopCases(vec);
	}


	auto end = high_resolution_clock::now();
	duration<double, std::milli> ms_double = end - start;
	std::cout << std::setprecision(3) << ms_double.count() << " ms" << std::endl;

	return 0;
}
