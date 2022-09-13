/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_02_element_access.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:29:27 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/13 13:38:43 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_performance.hpp>

#define OPERATOR    1
#define AT          2
#define DATA        3

template <typename T>
static void accessLoop(NAMESPACE::vector<T> &vec, int option) {
	std::stringstream ss;
	
	if (option == OPERATOR) {
		for (size_t i = 0; i < vec.size(); i++) {
			ss << vec[i] << " ";
		}
	} else if (option == AT) {
		for (size_t i = 0; i < vec.size(); i++) {
			ss << vec.at(i) << " ";
		}
	} else if (option == DATA) {
		T *ptr = vec.data();
		for (size_t i = 0; i < vec.size(); i++) {
			ss << *ptr++ << " ";
		}
	} else {
		std::cerr << RED "Invalid option. Skipping Test Case" DEFAULT << std::endl;
		return;
	}
	// std::cout << ss.str() << std::endl;
}

template <typename T>
void atException(NAMESPACE::vector<T> &vec, size_t n) {
	try {
		vec.at(n);
	} catch (std::out_of_range &e) {}
}



int main() {
	using std::chrono::high_resolution_clock;
    using std::chrono::duration;
	auto start = high_resolution_clock::now();


	std::srand(time(NULL));
	// Operator[] Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		accessLoop(vec, OPERATOR);

		vec[0] = 0;
		vec[vec.size() - 1] = 123;
		vec[vec.size() / 2] = 123;
		vec[vec.size() / 3] = 456;
		vec[vec.size() / 4] = 789;
		vec[vec.size() / 5] = 1234567890;
		accessLoop(vec, OPERATOR);
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		NAMESPACE::vector<std::string> vec(array, array + (sizeof(array) / sizeof(std::string)));
		accessLoop(vec, OPERATOR);

		vec[0] = "The sun";
		vec[vec.size() - 1] = "had set,";
		vec[vec.size() / 2] = "and";
		vec[vec.size() / 3] = "so had";
		vec[vec.size() / 4] = "his";
		vec[vec.size() / 5] = "grades";
		accessLoop(vec, OPERATOR);
	}


	// At Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		accessLoop(vec, AT);

		vec.at(0) = 0;
		vec.at(vec.size() - 1) = 123;
		vec.at(vec.size() / 2) = 123;
		vec.at(vec.size() / 3) = 456;
		vec.at(vec.size() / 4) = 789;
		vec.at(vec.size() / 5) = 1234567890;
		accessLoop(vec, AT);
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		NAMESPACE::vector<std::string> vec(array, array + (sizeof(array) / sizeof(std::string)));
		accessLoop(vec, AT);

		vec.at(0) = "The sun";
		vec.at(vec.size() - 1) = "had set,";
		vec.at(vec.size() / 2) = "and";
		vec.at(vec.size() / 3) = "so had";
		vec.at(vec.size() / 4) = "his";
		vec.at(vec.size() / 5) = "grades";
		accessLoop(vec, AT);
	}


	// At Exception Tests
	{
		NAMESPACE::vector<long> vec;
		pushBackLoop(vec);

		atException(vec, 0);
		atException(vec, vec.size());
		atException(vec, vec.size() / 2);
		atException(vec, vec.max_size());
		atException(vec, vec.max_size() / 2);
		atException(vec, CHAR_BIT);
		atException(vec, CHAR_MIN);
		atException(vec, CHAR_MAX);
		atException(vec, SCHAR_MIN);
		atException(vec, SCHAR_MAX);
		atException(vec, INT_MIN);
		atException(vec, INT_MAX);
		atException(vec, SHRT_MIN);
		atException(vec, SHRT_MAX);
		atException(vec, USHRT_MAX);
		atException(vec, LONG_MIN);
		atException(vec, LONG_MAX);
		atException(vec, ULONG_MAX);
		atException(vec, RNG);
	}


	// Front Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		
		vec.front();
		vec.at(0) = 0;
		vec.front();
		vec.resize(42, 123456789);
		vec.front();
		vec.at(0) = 24;
		vec.front();
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		NAMESPACE::vector<std::string> vec(array, array + (sizeof(array) / sizeof(std::string)));

		vec.front();
		vec.at(0) = "Hello World!";
		vec.front();
		vec.resize(42, "Lorem ipsum dolor sit amet,");
		vec.front();
		vec.at(0) = "The quick brown fox jumps over the lazy dog";
		vec.front();
	}


	// Back Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);

		vec.back();
		vec.at(vec.size() - 1) = 0;
		vec.back();
		vec.resize(42, 123456789);
		vec.back();
		vec.at(vec.size() - 1) = 24;
		vec.back();
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		NAMESPACE::vector<std::string> vec(array, array + (sizeof(array) / sizeof(std::string)));

		vec.back();
		vec.at(vec.size() - 1) = "Hello World!";
		vec.back();
		vec.resize(42, "Lorem ipsum dolor sit amet,");
		vec.back();
		vec.at(vec.size() - 1) = "The quick brown fox jumps over the lazy dog";
		vec.back();
	}


	// Data Tests
	{
		NAMESPACE::vector<int> vec;
		pushBackLoop(vec);
		accessLoop(vec, DATA);

		int *ptr = vec.data() + 0;
		ptr = vec.data() + (vec.size() - 1);
		ptr = vec.data() + (vec.size() / 2);
		ptr = vec.data() + (vec.size() / 3);
		ptr = vec.data() + (vec.size() / 4);
		ptr = vec.data() + (vec.size() / 5);
	}
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing", "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		NAMESPACE::vector<std::string> vec;
		accessLoop(vec, DATA);

		std::string *ptr = vec.data() + 0;
		ptr = vec.data() + (vec.size() - 1);
		ptr = vec.data() + (vec.size() / 2);
		ptr = vec.data() + (vec.size() / 3);
		ptr = vec.data() + (vec.size() / 4);
		ptr = vec.data() + (vec.size() / 5);
	}


	auto end = high_resolution_clock::now();
	duration<double, std::milli> ms_double = end - start;
	std::cout << std::setprecision(3) << ms_double.count() << " ms" << std::endl;

	return 0;
}
