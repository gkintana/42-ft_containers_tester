/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_05_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:26:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/06 10:51:01 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

template < typename T >
static void clearVectors(ft::vector<T> &ft, std::vector<T> &std, bool add_newline) {
	ft.clear();
	std.clear();
	compareVectors(ft, std, add_newline);
}

/**
** @REMINDER: add one more parameter to determine if begin or end function will
** be used
*/
template < typename T >
static void singleErase(ft::vector<T> &ft, std::vector<T> &std, size_t offset,
                        bool add_newline) {
	ft.erase(ft.begin() + offset);
	std.erase(std.begin() + offset);
	compareVectors(ft, std, add_newline);
}

/*----------------------------------------------------------------------------*/

#define BEGIN     1
#define END       2
#define RBEGIN    3
#define REND      4

static void clearTests();
static void eraseTests();
static void pushBackTests();
// static void popBackTests();
static void swapTests();

int main() {
	srand(time(NULL));

	std::cout << PURPLE "Clear Tests" DEFAULT << std::endl;
	clearTests();

	std::cout << PURPLE "Erase Tests" DEFAULT << std::endl;
	eraseTests();

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

static void eraseTests() {
	resetTestCount("Int Vector: ");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		vectorPushLoop(ft_vec, std_vec, 100, false, false);
		singleErase(ft_vec, std_vec, ft_vec.size() / 3, false);
		singleErase(ft_vec, std_vec, 0, false);
		singleErase(ft_vec, std_vec, ft_vec.size() - 1, true);
		// singleBeginErase(ft_vec, std_vec, ft_vec.size() / 3, true);
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
