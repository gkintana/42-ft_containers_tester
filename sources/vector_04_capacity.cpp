/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_04_capacity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:28:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/04 23:46:22 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

template < typename T >
static void resizeAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_size,
                             T value, bool add_newline) {
	ft.resize(new_size, value);
	std.resize(new_size, value);
	compareVectors(ft, std, add_newline);
}

template < typename T >
static void checkResizeExceptions(ft::vector<T> &ft,std::vector<T> &std,
                                 size_t new_size, bool add_newline) {
	bool ft_exception = false,
	     std_exception = false;

	try {
		ft.resize(new_size);
	} catch (std::exception &e) {
		ft_exception = true;
	}

	try {
		std.resize(new_size);
	} catch (std::exception &e) {
		std_exception = true;
	}

	if (ft_exception == std_exception) {
		std::cout << test_no++ << "." GREEN "EXCEPTION OK " DEFAULT;
	} else {
		std::cout << test_no++ << "." RED "EXCEPTION KO " DEFAULT;
	}
	compareVectors(ft, std, add_newline);
}

/*----------------------------------------------------------------------------*/

static void resizeTests();
static void resizeExceptionTests();
// static void reserveTests();

int main() {
	std::cout << PURPLE "Resize Tests" DEFAULT << std::endl;
	resizeTests();

	std::cout << PURPLE "Resize Exception Tests" DEFAULT << std::endl;
	resizeExceptionTests();
	
	return 0;
}

/*----------------------------------------------------------------------------*/

static void resizeTests() {
	resetTestCount("Int Vector: ");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;

		// test no. 1 - 5
		resizeAndCompare(ft_vec, std_vec, 7, 1234567890, false);
		// test no. 6 - 10
		resizeAndCompare(ft_vec, std_vec, 12, 42, false);
		// test no. 11 - 15
		resizeAndCompare(ft_vec, std_vec, 0, INT_MAX, false);
		// test no. 15 - 20
		resizeAndCompare(ft_vec, std_vec, 25, 25, false);
		// test no. 21 - 25
		resizeAndCompare(ft_vec, std_vec, 5, 123, false);
		// test no. 26 - 30
		resizeAndCompare(ft_vec, std_vec, 8, 456, false);
		// test no. 31 - 35
		resizeAndCompare(ft_vec, std_vec, 12, 789789789, true);
	}

	// resetTestCount("String Vector: ");
	// {
		
	// }
}

static void resizeExceptionTests() {
	resetTestCount("Int Vector: ");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;

		checkResizeExceptions(ft_vec, std_vec, 0, false);
		checkResizeExceptions(ft_vec, std_vec, -0, false);
		checkResizeExceptions(ft_vec, std_vec, INT_MIN, false);
		checkResizeExceptions(ft_vec, std_vec, INT_MAX, true);
		checkResizeExceptions(ft_vec, std_vec, LONG_MIN, false);
		checkResizeExceptions(ft_vec, std_vec, LONG_MAX, false);
		checkResizeExceptions(ft_vec, std_vec, -123123123123123123, true);
	}
}
