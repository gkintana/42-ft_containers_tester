/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_05_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/03 22:55:42 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

template < typename T >
static void clearVectors(ft::vector<T> &ft, std::vector<T> &std) {
	ft.clear();
	std.clear();
}

/*----------------------------------------------------------------------------*/

static void clearTests();
static void pushBackTests();
static void swapTests();

int main() {
	srand(time(NULL));

	std::cout << PURPLE "Clear Tests" DEFAULT << std::endl;
	clearTests();

	std::cout << PURPLE "Vector Push Back Tests" DEFAULT << std::endl;
	pushBackTests();

	std::cout << PURPLE "Swap Tests" DEFAULT << std::endl;
	swapTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void clearTests() {
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	resetTestCount();
	std::cout << "Empty Int Vector: ";
	clearVectors(ft_vec, std_vec);
	testVectors(ft_vec, std_vec, true);

	resetTestCount();
	std::cout << "Char Vector: ";
	{
		ft::vector<char> ft_char(42, 'A');
		std::vector<char> std_char(42, 'A');
		clearVectors(ft_char, std_char);
		testVectors(ft_char, std_char, true);
	}

	resetTestCount();
	std::cout << "Int Vector: ";
	vectorPushLoop(ft_vec, std_vec, 10, false, false);
	clearVectors(ft_vec, std_vec);
	testVectors(ft_vec, std_vec, true);

	resetTestCount();
	std::cout << "String Vector: ";
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

		ft::vector<std::string> ft_str(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_str(array, array + (sizeof(array) / sizeof(std::string)));
		clearVectors(ft_str, std_str);
		testVectors(ft_str, std_str, true);
	}
}

static void pushBackTests() {
	resetTestCount();
	std::cout << "Char Vector: ";
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, true, true);
	}

	resetTestCount();
	std::cout << "Int Vector: ";
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, true, true);
	}

	resetTestCount();
	std::cout << "String Vector: ";
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, "Hello World!", true, true);
	}
}

static void swapTests() {
	resetTestCount();
	std::cout << "Int Vector: ";
	{
		ft::vector<int> ft_vec1;
		std::vector<int> std_vec1;
		// test no. 1 - 5
		vectorPushLoop(ft_vec1, std_vec1, 24, true, false);

		ft::vector<int> ft_vec2;
		std::vector<int> std_vec2;
		// test no. 6 - 10
		vectorPushLoop(ft_vec2, std_vec2, 42, true, false);

		ft_vec1.swap(ft_vec2);
		std_vec1.swap(std_vec2);
		// test no. 11 - 15
		testVectors(ft_vec1, std_vec1, true);
		// test no. 16 - 20
		testVectors(ft_vec2, std_vec2, true);
	}
}
