/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:26:11 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/10 16:52:15 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

template <typename T>
static void beginTests(NAMESPACE::vector<T> vector);

template <typename T>
static void endTests(NAMESPACE::vector<T> vector);

template <typename T>
static void printTests(NAMESPACE::vector<T> vector);

template <typename T>
static void rbeginTests(NAMESPACE::vector<T> vector);

template <typename T>
static void rendTests(NAMESPACE::vector<T> vector);

template <typename T>
static void revPrintTests(NAMESPACE::vector<T> vector);

template <typename T>
static void constBeginTests(const NAMESPACE::vector<T> vector);

template <typename T>
static void constEndTests(const NAMESPACE::vector<T> vector);

template <typename T>
static void constPrintTests(const NAMESPACE::vector<T> vector);

template <typename T>
static void constRbeginTests(const NAMESPACE::vector<T> vector);

template <typename T>
static void constRendTests(const NAMESPACE::vector<T> vector);

template <typename T>
static void constRevPrintTests(const NAMESPACE::vector<T> vector);

int array[] = { 32587, 24716, 17501, 38466, 28705,
                10169, 46290, 44120, 28848, 18504,
                25731, 11261, 14575, 21852, 42483,
                15585, 48612, 44087, 20330, 38142 };

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::vector<int> test;
	pushRandomValues(test, 20);
	beginTests(test);
	endTests(test);
	printTests(test);
	rbeginTests(test);
	rendTests(test);
	revPrintTests(test);

	const NAMESPACE::vector<int> const_test(array, array + (sizeof(array) / sizeof(int)));
	constBeginTests(const_test);
	constEndTests(const_test);
	constPrintTests(const_test);
	constRbeginTests(test);
	constRendTests(test);
	constRevPrintTests(test);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename T>
static void beginTests(NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "vector::begin Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *vector.begin() << std::endl
	          << *(vector.begin() + (vector.size() / 2)) << std::endl
			  << *(vector.begin() + (vector.size() - 1)) << std::endl;
}

template <typename T>
static void endTests(NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "vector::end Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *(vector.end() - 1) << std::endl
	          << *(vector.end() - (vector.size() / 2)) << std::endl
			  << *(vector.end() - vector.size()) << std::endl;
}

template <typename T>
static void printTests(NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "Print Tests" << std::endl;
	printByIterator(vector, vector.begin(), vector.end());
	printByIterator(vector, vector.begin() + (vector.size() / 2), vector.end());
	printByIterator(vector, vector.begin() + (vector.size() - 1), vector.end());
	printByIterator(vector, vector.begin() + vector.size(), vector.end());
	printByIterator(vector, vector.begin(), vector.end() - (vector.size() / 4));
	printByIterator(vector, vector.begin(), vector.end() - (vector.size() / 2));
	printByIterator(vector, vector.begin(), vector.end() - (vector.size() - 1));
	printByIterator(vector, vector.begin(), vector.end() - vector.size());
	printByIterator(vector, vector.begin() + (vector.size() / 4), vector.end() - (vector.size() / 2));
	printByIterator(vector, vector.begin() + (vector.size() / 3), vector.end() - (vector.size() / 3));
	printByIterator(vector, vector.begin() + (vector.size() / 2), vector.end() - (vector.size() / 4));
	printByIterator(vector, vector.end(), vector.end());
	printByIterator(vector, vector.end() - vector.size(), vector.end());
	printByIterator(vector, vector.end() - (vector.size() / 2), vector.end());
	printByIterator(vector, vector.end() - (vector.size() / 2), vector.end() - (vector.size() / 4));
}

template <typename T>
static void rbeginTests(NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "vector::rbegin Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *vector.rbegin() << std::endl
	          << *(vector.rbegin() + (vector.size() / 2)) << std::endl
	          << *(vector.rbegin() + (vector.size() - 1)) << std::endl;
}

template <typename T>
static void rendTests(NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "vector::rend Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *(vector.rend() - 1) << std::endl
	          << *(vector.rend() - (vector.size() / 2)) << std::endl
			  << *(vector.rend() - vector.size()) << std::endl;
}

template <typename T>
static void revPrintTests(NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "Reverse Print Tests" << std::endl;
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin());
	printByReverseIterator(vector, vector.rend() - (vector.size() / 2), vector.rbegin());
	printByReverseIterator(vector, vector.rend() - (vector.size() - 1), vector.rbegin());
	printByReverseIterator(vector, vector.rend() - vector.size(), vector.rbegin());
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() / 4));
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() / 3));
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() / 2));
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() - 1));
	printByReverseIterator(vector, vector.rend() - (vector.size() / 4), vector.rbegin() + (vector.size() / 2));
	printByReverseIterator(vector, vector.rend() - (vector.size() / 3), vector.rbegin() + (vector.size() / 3));
	printByReverseIterator(vector, vector.rend() - (vector.size() / 2), vector.rbegin() + (vector.size() / 4));
	printByReverseIterator(vector, vector.rbegin() + 1, vector.rbegin());
	printByReverseIterator(vector, vector.rbegin() + (vector.size() - 1), vector.rbegin());
	printByReverseIterator(vector, vector.rbegin() + (vector.size() / 2), vector.rbegin());
	printByReverseIterator(vector, vector.rbegin() + (vector.size() / 2), vector.rbegin() + (vector.size() / 4));
}

template <typename T>
static void constBeginTests(const NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "const vector::begin Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *vector.begin() << std::endl
	          << *(vector.begin() + (vector.size() / 2)) << std::endl
			  << *(vector.begin() + (vector.size() - 1)) << std::endl;
}

template <typename T>
static void constEndTests(const NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "const vector::end Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *(vector.end() - 1) << std::endl
	          << *(vector.end() - (vector.size() / 2)) << std::endl
			  << *(vector.end() - vector.size()) << std::endl;
}

template <typename T>
static void constPrintTests(const NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "Const Print Tests" << std::endl;
	printByIterator(vector, vector.begin(), vector.end());
	printByIterator(vector, vector.begin() + (vector.size() / 2), vector.end());
	printByIterator(vector, vector.begin() + (vector.size() - 1), vector.end());
	printByIterator(vector, vector.begin() + vector.size(), vector.end());
	printByIterator(vector, vector.begin(), vector.end() - (vector.size() / 4));
	printByIterator(vector, vector.begin(), vector.end() - (vector.size() / 2));
	printByIterator(vector, vector.begin(), vector.end() - (vector.size() - 1));
	printByIterator(vector, vector.begin(), vector.end() - vector.size());
	printByIterator(vector, vector.begin() + (vector.size() / 4), vector.end() - (vector.size() / 2));
	printByIterator(vector, vector.begin() + (vector.size() / 3), vector.end() - (vector.size() / 3));
	printByIterator(vector, vector.begin() + (vector.size() / 2), vector.end() - (vector.size() / 4));
	printByIterator(vector, vector.end(), vector.end());
	printByIterator(vector, vector.end() - vector.size(), vector.end());
	printByIterator(vector, vector.end() - (vector.size() / 2), vector.end());
	printByIterator(vector, vector.end() - (vector.size() / 2), vector.end() - (vector.size() / 4));
}

template <typename T>
static void constRbeginTests(const NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "const vector::rbegin Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *vector.rbegin() << std::endl
	          << *(vector.rbegin() + (vector.size() / 2)) << std::endl
	          << *(vector.rbegin() + (vector.size() - 1)) << std::endl;
}

template <typename T>
static void constRendTests(const NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "const vector::rend Tests" << std::endl
	          << "--------------------------------------------------" << std::endl
	          << *(vector.rend() - 1) << std::endl
	          << *(vector.rend() - (vector.size() / 2)) << std::endl
			  << *(vector.rend() - vector.size()) << std::endl;
}

template <typename T>
static void constRevPrintTests(const NAMESPACE::vector<T> vector) {
	std::cout << "--------------------------------------------------" << std::endl
	          << "Reverse Print Tests" << std::endl;
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin());
	printByReverseIterator(vector, vector.rend() - (vector.size() / 2), vector.rbegin());
	printByReverseIterator(vector, vector.rend() - (vector.size() - 1), vector.rbegin());
	printByReverseIterator(vector, vector.rend() - vector.size(), vector.rbegin());
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() / 4));
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() / 3));
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() / 2));
	printByReverseIterator(vector, vector.rend() - 1, vector.rbegin() + (vector.size() - 1));
	printByReverseIterator(vector, vector.rend() - (vector.size() / 4), vector.rbegin() + (vector.size() / 2));
	printByReverseIterator(vector, vector.rend() - (vector.size() / 3), vector.rbegin() + (vector.size() / 3));
	printByReverseIterator(vector, vector.rend() - (vector.size() / 2), vector.rbegin() + (vector.size() / 4));
	printByReverseIterator(vector, vector.rbegin() + 1, vector.rbegin());
	printByReverseIterator(vector, vector.rbegin() + (vector.size() - 1), vector.rbegin());
	printByReverseIterator(vector, vector.rbegin() + (vector.size() / 2), vector.rbegin());
	printByReverseIterator(vector, vector.rbegin() + (vector.size() / 2), vector.rbegin() + (vector.size() / 4));
}
