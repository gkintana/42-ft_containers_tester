/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_04_capacity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:28:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 10:26:59 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

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
	vectorTester test;
	{
		ft::vector<long> ft;
		std::vector<long> std;

		test.resizeAndCompare(ft, std, 7, 1234567890);
		test.resizeAndCompare(ft, std, 12, 42);
		test.resizeAndCompare(ft, std, 0, INT_MAX);
		test.resizeAndCompare(ft, std, 25, 'A');
		test.resizeAndCompare(ft, std, 5, 123);
		test.resizeAndCompare(ft, std, 8, 'z');
		test.resizeAndCompare(ft, std, 12, 789789789);

		test.printTestResults("Long Vector ");
	}

	{
		ft::vector<std::string> ft;
		std::vector<std::string> std;

		test.resizeAndCompare(ft, std, 7, "Lorem ipsum dolor sit amet");
		test.resizeAndCompare(ft, std, 12, "Proin tellus sem, facilisis vel faucibus nec, convallis in ex");
		test.resizeAndCompare(ft, std, 0, "Quisque accumsan fringilla eros, faucibus auctor leo gravida a. Maecenas sed mi sed tellus pulvinar mattis. Nulla auctor pretium nunc id auctor. Vivamus tincidunt leo sit amet est posuere tincidunt");
		test.resizeAndCompare(ft, std, 25, "Sed a rutrum metus, vitae iaculis leo. Donec vulputate lacus nisl, et viverra quam blandit vitae. Mauris tempor mollis gravida. Morbi sed mauris at diam pretium rhoncus sit amet auctor odio. Ut sed nunc id leo ultrices dapibus sed a ligula. Fusce eget quam felis. Fusce dignissim elementum pretium. Quisque consectetur lectus non enim molestie efficitur");
		test.resizeAndCompare(ft, std, 5, "Mauris in eros pharetra, congue sapien at, varius lorem. Aenean cursus nulla at lectus eleifend suscipit. Aliquam sed lectus sed ante sodales sagittis ut et erat. Aenean eu lacus est. Proin et libero ultrices, lacinia ipsum quis, ultricies lectus. Ut volutpat libero ac lobortis accumsan. Etiam purus quam, convallis non blandit eu, sollicitudin vel sem. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus eleifend euismod euismod. Curabitur interdum sollicitudin est ut volutpat. Suspendisse molestie, mauris sit amet ultricies pulvinar, ante nisl posuere lorem, vel aliquet velit eros quis erat. Aliquam vel neque eu massa rhoncus convallis a non augue. Praesent venenatis magna condimentum nibh pulvinar pretium. Etiam maximus malesuada hendrerit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris mollis erat ut risus mollis, a dictum diam tincidunt");
		test.resizeAndCompare(ft, std, 8, "Hello World!");
		test.resizeAndCompare(ft, std, 12, "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");

		test.printTestResults("String Vector");
	}
}

static void resizeExceptionTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;

		test.checkExceptions(ft, std, ft.max_size(), RESIZE);
		test.checkExceptions(ft, std, +0, RESIZE);
		test.checkExceptions(ft, std, -0, RESIZE);
		test.checkExceptions(ft, std, CHAR_BIT, RESIZE);
		test.checkExceptions(ft, std, CHAR_MIN, RESIZE);
		test.checkExceptions(ft, std, CHAR_MAX, RESIZE);
		test.checkExceptions(ft, std, SCHAR_MIN, RESIZE);
		test.checkExceptions(ft, std, SCHAR_MAX, RESIZE);
		test.checkExceptions(ft, std, INT_MIN, RESIZE);
		test.checkExceptions(ft, std, SHRT_MIN, RESIZE);
		test.checkExceptions(ft, std, SHRT_MAX, RESIZE);
		test.checkExceptions(ft, std, USHRT_MAX, RESIZE);
		test.checkExceptions(ft, std, LONG_MIN, RESIZE);
		test.checkExceptions(ft, std, LONG_MAX, RESIZE);
		test.checkExceptions(ft, std, ULONG_MAX, RESIZE);
		// the following cases gets stuck or a SIGKILL on campus macs, so I disabled them
		// test.checkExceptions(ft, std, INT_MAX, RESIZE);
		// test.checkExceptions(ft, std, UINT_MAX, RESIZE);

		test.printTestResults("");
	}
}

static void reserveTests() {
	vectorTester test;
	{
		size_t size = 10,
               value = 12345;
		ft::vector<int> ft(size, value);
		std::vector<int> std(size, value);

		test.reserveAndCompare(ft, std, 42);
		test.reserveAndCompare(ft, std, 'a');
		test.reserveAndCompare(ft, std, 0);
		test.reserveAndCompare(ft, std, 999999999);
		test.reserveAndCompare(ft, std, ft.capacity());
		test.reserveAndCompare(ft, std, 123456789);
		test.reserveAndCompare(ft, std, 'Z' + 98765 - 12345);
		test.reserveAndCompare(ft, std, *ft.begin() + (ft.size() / 2));

		test.printTestResults("");
	}
}

static void reserveExceptionTests() {
	vectorTester test;
	{
		ft::vector<int> ft;
		std::vector<int> std;

		test.checkExceptions(ft, std, ft.max_size(), RESERVE);
		test.checkExceptions(ft, std, +0, RESERVE);
		test.checkExceptions(ft, std, -0, RESERVE);
		test.checkExceptions(ft, std, CHAR_BIT, RESERVE);
		test.checkExceptions(ft, std, CHAR_MIN, RESERVE);
		test.checkExceptions(ft, std, CHAR_MAX, RESERVE);
		test.checkExceptions(ft, std, SCHAR_MIN, RESERVE);
		test.checkExceptions(ft, std, SCHAR_MAX, RESERVE);
		test.checkExceptions(ft, std, INT_MIN, RESERVE);
		test.checkExceptions(ft, std, SHRT_MIN, RESERVE);
		test.checkExceptions(ft, std, SHRT_MAX, RESERVE);
		test.checkExceptions(ft, std, USHRT_MAX, RESERVE);
		test.checkExceptions(ft, std, LONG_MIN, RESERVE);
		test.checkExceptions(ft, std, LONG_MAX, RESERVE);
		test.checkExceptions(ft, std, ULONG_MAX, RESERVE);

		test.printTestResults("");
	}
}
