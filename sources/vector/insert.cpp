/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/10 19:56:14 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

#define RNG    10000 + (std::rand() % 50000)

void singleInsertTests(NAMESPACE::vector<int> &vector);
void singleInsertTests(NAMESPACE::vector<std::string> &vector);

void rangeInsertTests(NAMESPACE::vector<int> &vector);
void rangeInsertTests(NAMESPACE::vector<std::string> &vector);

void iteratorInsertTests(NAMESPACE::vector<int> &vector);
void iteratorInsertTests(NAMESPACE::vector<std::string> &vector);

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int> test;
		singleInsertTests(test);
		printByOperator(test);
		rangeInsertTests(test);
		printByOperator(test);
		iteratorInsertTests(test);
		printByOperator(test);
	}

	{
		NAMESPACE::vector<std::string> test;
		singleInsertTests(test);
		printByOperator(test);
		rangeInsertTests(test);
		printByOperator(test);
		iteratorInsertTests(test);
		printByOperator(test);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

void singleInsertTests(NAMESPACE::vector<int> &vector) {
	vector.insert(vector.begin(), RNG);
	vector.insert(vector.begin() + (vector.size() / 2), RNG);
	vector.insert(vector.begin() + (vector.size() - 1), RNG);
	vector.insert(vector.end() - 1, RNG);
	vector.insert(vector.end() - vector.size(), RNG);
	vector.insert(vector.end() - (vector.size() / 2), RNG);		
}

void singleInsertTests(NAMESPACE::vector<std::string> &vector) {
	vector.insert(vector.begin(), "Lorem ipsum dolor sit amet");
	vector.insert(vector.begin() + (vector.size() / 2), "There was a big earthquake last night.");
	vector.insert(vector.begin() + (vector.size() - 1), "The quick brown fox jumps over the lazy dog");
	vector.insert(vector.end() - 1, "");
	vector.insert(vector.end() - vector.size(), "I admire your courage but I don't admire your singing ability.");
	vector.insert(vector.end() - (vector.size() / 2), "It's fascinating that you know all the planets.");
}

void rangeInsertTests(NAMESPACE::vector<int> &vector) {
	vector.insert(vector.begin(), 3, RNG);
	vector.insert(vector.begin() + (vector.size() / 2), 5, RNG);
	vector.insert(vector.begin() + (vector.size() / 3), 0, RNG);
	vector.insert(vector.begin() + (vector.size() / 4), 4, RNG);
	vector.insert(vector.begin() + (vector.size() / 5), 1, RNG);
	vector.insert(vector.begin() + (vector.size() - 1), 10, RNG);
	vector.insert(vector.end() - 1, 1, RNG);
	vector.insert(vector.end() - vector.size(), 5, RNG);
	vector.insert(vector.end() - (vector.size() / 2), 3, RNG);
	vector.insert(vector.end() - (vector.size() / 3), 8, RNG);
	vector.insert(vector.end() - (vector.size() / 4), 0, RNG);
}

void rangeInsertTests(NAMESPACE::vector<std::string> &vector) {
	vector.insert(vector.begin(), 3, "My");
	vector.insert(vector.begin() + (vector.size() / 2), 5, "dentist");
	vector.insert(vector.begin() + (vector.size() / 3), 0, "tells");
	vector.insert(vector.begin() + (vector.size() / 4), 4, "me");
	vector.insert(vector.begin() + (vector.size() / 5), 1, "that");
	vector.insert(vector.begin() + (vector.size() - 1), 10, "chewing");
	vector.insert(vector.end() - 1, 1, "bricks");
	vector.insert(vector.end() - vector.size(), 5, "is very bad");
	vector.insert(vector.end() - (vector.size() / 2), 0, "for your");
	vector.insert(vector.end() - (vector.size() / 3), 8, "teeth");
	vector.insert(vector.end() - (vector.size() / 4), 2, "😬");
}


void iteratorInsertTests(NAMESPACE::vector<int> &vector) {
	int array[] = { 32587, 24716, 17501, 38466, 28705, 10169, 46290, 44120, 28848, 18504,
	                25731, 11261, 14575, 21852, 42483, 15585, 48612, 44087, 20330, 38142 };
	size_t size = sizeof(array) / sizeof(int);

	pushRandomValues(vector, size / 2);
	vector.insert(vector.begin(), array, array + size);
	vector.insert(vector.begin() + (vector.size() / 5), array, array + size / 2);
}


void iteratorInsertTests(NAMESPACE::vector<std::string> &vector) {
	std::string array[] = { "My", "dentist", "tells", "me", "that", "chewing", "bricks",
	                        "is", "very", "bad", "for", "your", "teeth", "😬" };
	size_t size = sizeof(array) / sizeof(std::string);

	vector.insert(vector.begin(), array, array + size);
	vector.insert(vector.begin() + (vector.size() / 5), array, array + size / 2);
}
