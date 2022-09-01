/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/01 13:56:48 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tester.hpp>

int main() {
	std::cout << PURPLE "Vector Push Back Tests" DEFAULT << std::endl
	          << "Char Vector: ";
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;

		size_t limit = 127;
		for (size_t i = 32; i < 127; i++) {
			ft_vec.push_back(i);
			std_vec.push_back(i);
			if (i == limit / 2) {
				testVectors(ft_vec, std_vec, false);
			}
		}
		testVectors(ft_vec, std_vec, true);
	}

	/*------------------------------------------------------------------------*/

	std::cout << "Int Vector: ";
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;

		size_t limit = 42;
		for (size_t i = 0; i < limit; i++) {
			ft_vec.push_back(i);
			std_vec.push_back(i);
			if (i == limit / 2) {
				testVectors(ft_vec, std_vec, false);
			}
		}
		testVectors(ft_vec, std_vec, true);
	}

	/*------------------------------------------------------------------------*/

	std::cout << "String Vector: ";
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;

		size_t limit = 42;
		for (size_t i = 0; i < limit; i++) {
			ft_vec.push_back("Hello World!");
			std_vec.push_back("Hello World!");
			if (i == limit / 2) {
				testVectors(ft_vec, std_vec, false);
			}
		}
		testVectors(ft_vec, std_vec, true);
	}

	return 0;
}
