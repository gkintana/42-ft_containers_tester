/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_01_construction.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/02 20:59:44 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

int main() {
	std::cout << PURPLE "Vector Construction Tests" DEFAULT << std::endl
	          << "Empty Char Vector: ";
	resetTestCount();
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		testVectors(ft_vec, std_vec, true);
	}
	std::cout << "Empty Int Vector: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		testVectors(ft_vec, std_vec, true);
	}
	std::cout << "Empty Long Vector: ";
	resetTestCount();
	{
		ft::vector<long> ft_vec;
		std::vector<long> std_vec;
		testVectors(ft_vec, std_vec, true);
	}
	std::cout << "Empty Size_t Vector: ";
	resetTestCount();
	{
		ft::vector<size_t> ft_vec;
		std::vector<size_t> std_vec;
		testVectors(ft_vec, std_vec, true);
	}
	std::cout << "Empty Float Vector: ";
	resetTestCount();
	{
		ft::vector<float> ft_vec;
		std::vector<float> std_vec;
		testVectors(ft_vec, std_vec, true);
	}
	std::cout << "Empty Double Vector: ";
	resetTestCount();
	{
		ft::vector<double> ft_vec;
		std::vector<double> std_vec;
		testVectors(ft_vec, std_vec, true);
	}
	std::cout << "Empty String Vector: ";
	resetTestCount();
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		testVectors(ft_vec, std_vec, true);
	}

	/*------------------------------------------------------------------------*/

	std::cout << PURPLE "Fill Constructor Tests" DEFAULT << std::endl
	          << "Char Vector: ";
	resetTestCount();
	{
		ft::vector<char> ft_vec(0, 97);
		std::vector<char> std_vec(0, 97);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<char> ft_vec(21, 97);
		std::vector<char> std_vec(21, 97);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<char> ft_vec(-5, 97);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<char> std_vec(-5, 97);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	std::cout << "Int Vector: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec(0, 42);
		std::vector<int> std_vec(0, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<int> ft_vec(10, INT_MIN);
		std::vector<int> std_vec(10, INT_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<int> ft_vec(10, 0);
		std::vector<int> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<int> ft_vec(10, INT_MAX);
		std::vector<int> std_vec(10, INT_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<int> ft_vec(-5, 42);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<int> std_vec(-5, 42);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	std::cout << "Long Vector: ";
	resetTestCount();
	{
		ft::vector<long> ft_vec(0, 42);
		std::vector<long> std_vec(0, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MIN);
		std::vector<long> std_vec(10, LONG_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<long> ft_vec(10, 0);
		std::vector<long> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<long> ft_vec(10, LONG_MAX);
		std::vector<long> std_vec(10, LONG_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<long> ft_vec(-5, 42);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<long> std_vec(-5, 42);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	std::cout << "Size_t Vector: ";
	resetTestCount();
	{
		ft::vector<size_t> ft_vec(0, 42);
		std::vector<size_t> std_vec(0, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<size_t> ft_vec(21, 42);
		std::vector<size_t> std_vec(21, 42);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<size_t> ft_vec(-5, 42);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<size_t> std_vec(-5, 42);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	std::cout << "Float Vector: ";
	resetTestCount();
	{
		ft::vector<float> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		std::vector<float> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MIN);
		std::vector<float> std_vec(10, FLT_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<float> ft_vec(10, 0);
		std::vector<float> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<float> ft_vec(10, FLT_MAX);
		std::vector<float> std_vec(10, FLT_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<float> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<float> std_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123f);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	std::cout << "Double Vector: ";
	resetTestCount();
	{
		ft::vector<double> ft_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		std::vector<double> std_vec(0, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MIN);
		std::vector<double> std_vec(10, DBL_MIN);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<double> ft_vec(10, 0);
		std::vector<double> std_vec(10, 0);
		testVectors(ft_vec, std_vec, false);
	}
	{
		ft::vector<double> ft_vec(10, DBL_MAX);
		std::vector<double> std_vec(10, DBL_MAX);
		testVectors(ft_vec, std_vec, false);
	}
	{
		try {
			ft::vector<double> ft_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
			// std::vector<double> std_vec(-5, 42424242424242424242.123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123123);
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
	}

	/*------------------------------------------------------------------------*/

	std::cout << PURPLE "Range Constructor Tests" DEFAULT << std::endl
	          << "Begin to End: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec(21, 42);
		std::vector<int> std_vec(21, 42);

		ft::vector<int> ft_range(ft_vec.begin(), ft_vec.end());
		testVectors(ft_vec, ft_range, false);

		std::vector<int> std_range(std_vec.begin(), std_vec.end());
		testVectors(ft_range, std_range, false);
	}
	{
		ft::vector<int> ft_vec(21, 42);
		std::vector<int> std_vec(21, 42);

		ft::vector<int> ft_range(ft_vec.begin() + 3, ft_vec.end() - 3);
		std::vector<int> std_range(std_vec.begin() + 3, std_vec.end() - 3);
		testVectors(ft_range, std_range, true);
	}

	std::cout << "Error Cases: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec(21, 42);
		std::vector<int> std_vec(21, 42);

		try {
			ft::vector<int> ft_range(ft_vec.rend(), ft_vec.rbegin());
			std::cout << test_no++ << "." RED "KO " DEFAULT << std::endl;
		} catch (std::exception &e) {
			std::cout << test_no++ << "." GREEN "OK " DEFAULT << std::endl;
		}
		// testVectors(ft_vec, ft_range, false);
		// ft::vector<int> ft_range(ft_vec.rbegin(), ft_vec.rend());

		// std::vector<int> std_range(std_vec.rbegin(), std_vec.rend());
		// std::vector<int> std_range(std_vec.rend(), std_vec.rbegin());
		// testVectors(ft_range, std_range, true);
	}
	/*------------------------------------------------------------------------*/

	std::cout << PURPLE "Copy Constructor Tests" DEFAULT << std::endl
	          << "Copy Constructor: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec(10, 42);
		std::vector<int> std_vec(10, 42);

		ft::vector<int> ft_copy1(ft_vec);
		std::vector<int> std_copy1(std_vec);
		testVectors(ft_copy1, std_copy1, false);

		ft::vector<int> ft_copy2 = ft_vec;
		std::vector<int> std_copy2 = std_vec;
		testVectors(ft_copy2, std_copy2, true);
	}

	std::cout << "Copy Assignment: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec(10, 42);
		std::vector<int> std_vec(10, 42);

		ft::vector<int> ft_copy;
		ft_copy = ft_vec;
		std::vector<int> std_copy;
		std_copy = std_vec;
		testVectors(ft_copy, std_copy, true);
	}

	std::cout << "Self-Assignment: ";
	resetTestCount();
	{
		ft::vector<int> ft_vec(10, INT_MAX);
		ft::vector<int> ft_copy(ft_vec);
		testVectors(ft_vec, ft_copy, false);
		ft_vec = ft_copy;
		testVectors(ft_vec, ft_copy, false);

		std::vector<int> std_vec(10, INT_MAX);
		std::vector<int> std_copy(std_vec);
		std_vec = std_copy;
		testVectors(ft_vec, std_vec, true);
	}

	return 0;
}
