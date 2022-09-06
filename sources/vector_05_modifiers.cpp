/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_05_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/06 14:58:06 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

#define BEGIN     1
#define END       2

template < typename T >
static void clearVectors(ft::vector<T> &ft, std::vector<T> &std, bool add_newline) {
	ft.clear();
	std.clear();
	compareVectors(ft, std, add_newline);
}

template < typename T >
static void singleErase(ft::vector<T> &ft, std::vector<T> &std, size_t option,
                        size_t offset, bool add_newline) {
	if (option == BEGIN) {
		ft.erase(ft.begin() + offset);
		std.erase(std.begin() + offset);
	} else if (option == END) {
		ft.erase(ft.end() - offset);
		std.erase(std.end() - offset);
	}
	compareVectors(ft, std, add_newline);
}

/*----------------------------------------------------------------------------*/

static void clearTests();
static void singleEraseTests();
static void pushBackTests();
// static void popBackTests();
static void swapTests();

int main() {
	srand(time(NULL));

	std::cout << PURPLE "Clear Tests" DEFAULT << std::endl;
	clearTests();

	std::cout << PURPLE "Single Erase Tests" DEFAULT << std::endl;
	singleEraseTests();

	std::cout << PURPLE "Push Back Tests" DEFAULT << std::endl;
	pushBackTests();

	std::cout << PURPLE "Swap Tests" DEFAULT << std::endl;
	swapTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void clearTests() {
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	resetTestCount("Empty Int Vector: ");
	clearVectors(ft_vec, std_vec, true);

	resetTestCount("Char Vector: ");
	{
		ft::vector<char> ft_char(42, 'A');
		std::vector<char> std_char(42, 'A');
		clearVectors(ft_char, std_char, true);
	}

	resetTestCount("Int Vector: ");
	vectorPushLoop(ft_vec, std_vec, 10, false, false);
	clearVectors(ft_vec, std_vec, true);

	resetTestCount("String Vector: ");
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

		ft::vector<std::string> ft_str(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_str(array, array + (sizeof(array) / sizeof(std::string)));
		clearVectors(ft_str, std_str, true);
	}
}

static void singleEraseTests() {
	resetTestCount("Int Vector: ");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 10, false, false);

		// test no. 1 - 5
		singleErase(ft_vec, std_vec, BEGIN, 0, false);
		// test no. 6 - 10
		singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() / 2, false);
		// test no. 11 - 15
		singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() - 1, false);
		// test no. 16 - 20
		singleErase(ft_vec, std_vec, END, 1, false);
		// test no. 21 - 25
		singleErase(ft_vec, std_vec, END, ft_vec.size() / 2, false);
		// test no. 26 - 30
		singleErase(ft_vec, std_vec, END, ft_vec.size(), true);
	}

	resetTestCount("String Vector: ");
	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };
		ft::vector<std::string> ft_vec(array, array + (sizeof(array) / sizeof(std::string)));
		std::vector<std::string> std_vec(array, array + (sizeof(array) / sizeof(std::string)));

		// test no. 1 - 5
		singleErase(ft_vec, std_vec, BEGIN, 0, false);
		// test no. 6 - 10
		singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() / 2, false);
		// test no. 11 - 15
		singleErase(ft_vec, std_vec, BEGIN, ft_vec.size() - 1, false);
		// test no. 16 - 20
		singleErase(ft_vec, std_vec, END, 1, false);
		// test no. 21 - 25
		singleErase(ft_vec, std_vec, END, ft_vec.size() / 2, false);
		// test no. 26 - 30
		singleErase(ft_vec, std_vec, END, ft_vec.size(), true);
	}
}

static void pushBackTests() {
	resetTestCount("Char Vector: ");
	{
		ft::vector<char> ft_vec;
		std::vector<char> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, true, true);
	}

	resetTestCount("Int Vector: ");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, true, true);
	}

	resetTestCount("String Vector: ");
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;
		vectorPushLoop(ft_vec, std_vec, 42, "Hello World!", true, true);
	}
}

// static void popBackTests() {
	
// }

static void swapTests() {
	resetTestCount("Int Vector: ");
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
		compareVectors(ft_vec1, std_vec1, false);
		// test no. 16 - 20
		compareVectors(ft_vec2, std_vec2, true);
	}
}
