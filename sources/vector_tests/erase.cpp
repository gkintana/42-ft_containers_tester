/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/11 11:54:35 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

template <typename T>
void singleEraseTests(NAMESPACE::vector<T> &vector);

void rangeEraseTests(NAMESPACE::vector<int> &vector);
void rangeEraseTests(NAMESPACE::vector<std::string> &vector);

std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing",
                        "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing",
                        "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int> test;

		pushRandomValues(test, 20);
		printByOperator(test);

		singleEraseTests(test);
		printByOperator(test);

		rangeEraseTests(test);
		printByOperator(test);
	}

	{
		NAMESPACE::vector<std::string> test(array, array + (sizeof(array) / sizeof(std::string)));

		singleEraseTests(test);
		printByOperator(test);

		rangeEraseTests(test);
		printByOperator(test);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

template <typename T>
void singleEraseTests(NAMESPACE::vector<T> &vector) {
	vector.erase(vector.begin());
	vector.erase(vector.begin() + (vector.size() / 2));
	vector.erase(vector.begin() + (vector.size() - 1));
	vector.erase(vector.end() - 1);
	vector.erase(vector.end() - vector.size());
	vector.erase(vector.end() - (vector.size() / 2));
}

void rangeEraseTests(NAMESPACE::vector<int> &vector) {
	pushRandomValues(vector, 20);
	vector.erase(vector.begin(), vector.begin());
	pushRandomValues(vector, 20);
	vector.erase(vector.begin(), vector.begin() + vector.size());
	pushRandomValues(vector, 20);
	vector.erase(vector.begin(), vector.end());
	pushRandomValues(vector, 20);
	vector.erase(vector.begin() + (vector.size() / 2), vector.end());
	pushRandomValues(vector, 20);
	vector.erase(vector.begin() + (vector.size() - 1), vector.end());
	pushRandomValues(vector, 20);
	vector.erase(vector.begin() + vector.size(), vector.end());
	pushRandomValues(vector, 20);
	vector.erase(vector.end() - 1, vector.begin() + vector.size());
	pushRandomValues(vector, 20);
	vector.erase(vector.end() - 1, vector.end() - 1);
}

void rangeEraseTests(NAMESPACE::vector<std::string> &vector) {
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.begin(), vector.begin());
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.begin(), vector.begin() + vector.size());
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.begin(), vector.end());
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.begin() + (vector.size() / 2), vector.end());
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.begin() + (vector.size() - 1), vector.end());
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.begin() + vector.size(), vector.end());
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.end() - 1, vector.begin() + vector.size());
	vector.insert(vector.begin(), 20, "The quick brown fox jumps over the lazy dog");
	vector.erase(vector.end() - 1, vector.end() - 1);
}
