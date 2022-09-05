/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_04_capacity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:28:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/05 22:42:18 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

// https://stackoverflow.com/questions/30835980/c-error-deduced-conflicting-types-for-parameter-t-string-vs-const-char
template < typename T >
struct identity {
	typedef T type;
};

template < typename T >
static void resizeAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_size,
                             typename identity<T>::type value, bool add_newline) {
	ft.resize(new_size, value);
	std.resize(new_size, value);
	compareVectors(ft, std, add_newline);
}

template < typename T >
static void checkExceptions(ft::vector<T> &ft,std::vector<T> &std, size_t new_size,
                            bool is_resize, bool add_newline) {
	bool ft_exception = false,
	     std_exception = false;

	try {
		if (is_resize) {
			ft.resize(new_size);
		} else {
			ft.reserve(new_size);
		}
	} catch (std::exception &e) {
		ft_exception = true;
	}

	try {
		if (is_resize) {
			std.resize(new_size);
		} else {
			std.reserve(new_size);
		}
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

template < typename T >
static void reserveAndCompare(ft::vector<T> &ft,std::vector<T> &std, size_t new_cap,
                              bool add_newline) {
	ft.reserve(new_cap);
	std.reserve(new_cap);
	compareVectors(ft, std, add_newline);
}

/*----------------------------------------------------------------------------*/

#define RESIZE     true
#define RESERVE    false

static void resizeTests();
static void resizeExceptionTests();
static void reserveTests();
static void reserveExceptionTests();

int main() {
	std::cout << PURPLE "Resize Tests" DEFAULT << std::endl;
	resizeTests();

	std::cout << PURPLE "Resize Exception Tests" DEFAULT << std::endl;
	resizeExceptionTests();
	
	std::cout << PURPLE "Reserve Tests" DEFAULT << std::endl;
	reserveTests();

	std::cout << PURPLE "Reserve Exception Tests" DEFAULT << std::endl;
	reserveExceptionTests();

	return 0;
}

/*----------------------------------------------------------------------------*/

static void resizeTests() {
	resetTestCount("Int Vector: ");
	{
		ft::vector<long> ft_vec;
		std::vector<long> std_vec;

		// test no. 1 - 5
		resizeAndCompare(ft_vec, std_vec, 7, 1234567890, false);
		// test no. 6 - 10
		resizeAndCompare(ft_vec, std_vec, 12, 42, false);
		// test no. 11 - 15
		resizeAndCompare(ft_vec, std_vec, 0, INT_MAX, false);
		// test no. 15 - 20
		resizeAndCompare(ft_vec, std_vec, 25, 'A', false);
		// test no. 21 - 25
		resizeAndCompare(ft_vec, std_vec, 5, 123, false);
		// test no. 26 - 30
		resizeAndCompare(ft_vec, std_vec, 8, 'z', false);
		// test no. 31 - 35
		resizeAndCompare(ft_vec, std_vec, 12, 789789789, true);
	}

	resetTestCount("String Vector: ");
	{
		ft::vector<std::string> ft_vec;
		std::vector<std::string> std_vec;

		// test no. 1 - 5
		resizeAndCompare(ft_vec, std_vec, 7, "Lorem ipsum dolor sit amet", false);
		// test no. 6 - 10
		resizeAndCompare(ft_vec, std_vec, 12, "Proin tellus sem, facilisis vel faucibus nec, convallis in ex", false);
		// test no. 11 - 15
		resizeAndCompare(ft_vec, std_vec, 0, "Quisque accumsan fringilla eros, faucibus auctor leo gravida a. Maecenas sed mi sed tellus pulvinar mattis. Nulla auctor pretium nunc id auctor. Vivamus tincidunt leo sit amet est posuere tincidunt", false);
		// test no. 15 - 20
		resizeAndCompare(ft_vec, std_vec, 25, "Sed a rutrum metus, vitae iaculis leo. Donec vulputate lacus nisl, et viverra quam blandit vitae. Mauris tempor mollis gravida. Morbi sed mauris at diam pretium rhoncus sit amet auctor odio. Ut sed nunc id leo ultrices dapibus sed a ligula. Fusce eget quam felis. Fusce dignissim elementum pretium. Quisque consectetur lectus non enim molestie efficitur", false);
		// test no. 21 - 25
		resizeAndCompare(ft_vec, std_vec, 5, "Mauris in eros pharetra, congue sapien at, varius lorem. Aenean cursus nulla at lectus eleifend suscipit. Aliquam sed lectus sed ante sodales sagittis ut et erat. Aenean eu lacus est. Proin et libero ultrices, lacinia ipsum quis, ultricies lectus. Ut volutpat libero ac lobortis accumsan. Etiam purus quam, convallis non blandit eu, sollicitudin vel sem. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus eleifend euismod euismod. Curabitur interdum sollicitudin est ut volutpat. Suspendisse molestie, mauris sit amet ultricies pulvinar, ante nisl posuere lorem, vel aliquet velit eros quis erat. Aliquam vel neque eu massa rhoncus convallis a non augue. Praesent venenatis magna condimentum nibh pulvinar pretium. Etiam maximus malesuada hendrerit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris mollis erat ut risus mollis, a dictum diam tincidunt", false);
		// test no. 26 - 30
		resizeAndCompare(ft_vec, std_vec, 8, "Hello World!", false);
		// test no. 31 - 35
		resizeAndCompare(ft_vec, std_vec, 12, "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789", true);
	}
}

static void resizeExceptionTests() {
	resetTestCount("");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;

		// test no. 1 - 6
		checkExceptions(ft_vec, std_vec, ft_vec.max_size(), RESIZE, false);
		// test no. 7 - 12
		checkExceptions(ft_vec, std_vec, +0, RESIZE, false);
		// test no. 13 - 18
		checkExceptions(ft_vec, std_vec, -0, RESIZE, false);
		// test no. 19 - 24
		checkExceptions(ft_vec, std_vec, CHAR_BIT, RESIZE, false);
		// test no. 25 - 30
		checkExceptions(ft_vec, std_vec, CHAR_MIN, RESIZE, false);
		// test no. 31 - 36
		checkExceptions(ft_vec, std_vec, CHAR_MAX, RESIZE, false);
		// test no. 37 - 42
		checkExceptions(ft_vec, std_vec, SCHAR_MIN, RESIZE, false);
		// test no. 43 - 48
		checkExceptions(ft_vec, std_vec, SCHAR_MAX, RESIZE, false);
		// test no. 49 - 54
		checkExceptions(ft_vec, std_vec, INT_MIN, RESIZE, false);
		// test no. 55 - 60
		checkExceptions(ft_vec, std_vec, SHRT_MIN, RESIZE, false);
		// test no. 61 - 66
		checkExceptions(ft_vec, std_vec, SHRT_MAX, RESIZE, false);
		// test no. 67 - 72
		checkExceptions(ft_vec, std_vec, USHRT_MAX, RESIZE, false);
		// test no. 73 - 78
		checkExceptions(ft_vec, std_vec, LONG_MIN, RESIZE, false);
		// test no. 79 - 84
		checkExceptions(ft_vec, std_vec, LONG_MAX, RESIZE, false);
		// test no. 85 - 90
		checkExceptions(ft_vec, std_vec, ULONG_MAX, RESIZE, true);

		// the following cases gets stuck or a SIGKILL on campus macs, so I disabled them
		// checkExceptions(ft_vec, std_vec, INT_MAX, RESIZE, true);
		// checkExceptions(ft_vec, std_vec, UINT_MAX, RESIZE, true);
	}
}

static void reserveTests() {
	resetTestCount("");
	{
		size_t size = 10,
		       value = 12345;
		ft::vector<int> ft_vec(size, value);
		std::vector<int> std_vec(size, value);

		// test no. 1 - 5
		reserveAndCompare(ft_vec, std_vec, 42, false);
		// test no. 6 - 10
		reserveAndCompare(ft_vec, std_vec, 'a', false);
		// test no. 11 - 15
		reserveAndCompare(ft_vec, std_vec, 0, false);
		// test no. 16 - 20
		reserveAndCompare(ft_vec, std_vec, 999999999, false);
		// test no. 21 - 25
		reserveAndCompare(ft_vec, std_vec, ft_vec.capacity(), false);
		// test no. 26 - 30
		reserveAndCompare(ft_vec, std_vec, 123456789, false);
		// test no. 31 - 35
		reserveAndCompare(ft_vec, std_vec, 'Z' + 98765 - 12345, false);
		// test no. 36 - 40
		reserveAndCompare(ft_vec, std_vec, *ft_vec.begin() + (ft_vec.size() / 2), true);
	}
}

static void reserveExceptionTests() {
	resetTestCount("");
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;

		// test no. 1 - 6
		checkExceptions(ft_vec, std_vec, ft_vec.max_size(), RESERVE, false);
		// test no. 7 - 12
		checkExceptions(ft_vec, std_vec, +0, RESERVE, false);
		// test no. 13 - 18
		checkExceptions(ft_vec, std_vec, -0, RESERVE, false);
		// test no. 19 - 24
		checkExceptions(ft_vec, std_vec, CHAR_BIT, RESERVE, false);
		// test no. 25 - 30
		checkExceptions(ft_vec, std_vec, CHAR_MIN, RESERVE, false);
		// test no. 31 - 36
		checkExceptions(ft_vec, std_vec, CHAR_MAX, RESERVE, false);
		// test no. 37 - 42
		checkExceptions(ft_vec, std_vec, SCHAR_MIN, RESERVE, false);
		// test no. 43 - 48
		checkExceptions(ft_vec, std_vec, SCHAR_MAX, RESERVE, false);
		// test no. 49 - 54
		checkExceptions(ft_vec, std_vec, INT_MIN, RESERVE, false);
		// test no. 55 - 60
		checkExceptions(ft_vec, std_vec, SHRT_MIN, RESERVE, false);
		// test no. 61 - 66
		checkExceptions(ft_vec, std_vec, SHRT_MAX, RESERVE, false);
		// test no. 67 - 72
		checkExceptions(ft_vec, std_vec, USHRT_MAX, RESERVE, false);
		// test no. 73 - 78
		checkExceptions(ft_vec, std_vec, LONG_MIN, RESERVE, false);
		// test no. 79 - 84
		checkExceptions(ft_vec, std_vec, LONG_MAX, RESERVE, false);
		// test no. 85 - 90
		checkExceptions(ft_vec, std_vec, ULONG_MAX, RESERVE, true);
	}
}
