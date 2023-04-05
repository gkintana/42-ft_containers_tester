/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:28:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 01:22:31 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

static void basicTests();
static void exceptionTests();

#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#ifndef ENABLE_THREAD
# define ENABLE_THREAD false
#endif

void* timer_thread(void* arg)
{
	(void)arg;
    time_t start_time = time(NULL);
    while (true) {
        time_t current_time = time(NULL);
        if (difftime(current_time, start_time) > 10) {
            std::cout << "TIMEOUT" << std::endl;
            exit(1);
        }
        usleep(100);
    }
}

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	if (ENABLE_THREAD == true) {
		pthread_t timer;
		if (pthread_create(&timer, NULL, timer_thread, NULL)) {
			std::cerr << "Error creating thread.\n";
			return 1;
		}
		if (pthread_detach(timer)) {
			std::cerr << "Error detaching thread.\n";
			return 1;
		}
	}

	basicTests();
	exceptionTests();

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}

static void basicTests() {
	{
		NAMESPACE::vector<long> test;
		printByOperator(test);

		test.resize(7, 1234567890);
		printByOperator(test);
		test.resize(12, 42);
		printByOperator(test);
		test.resize(0, INT_MAX);
		printByOperator(test);
		test.resize(25, 'A');
		printByOperator(test);
		test.resize(5, 123);
		printByOperator(test);
		test.resize(8, 'z');
		printByOperator(test);
		test.resize(12, 789789789);
		printByOperator(test);
	}
	{
		NAMESPACE::vector<std::string> test;
		printByOperator(test);

		test.resize(7, "Lorem ipsum dolor sit amet");
		printByOperator(test);
		test.resize(12, "Proin tellus sem, facilisis vel faucibus nec, convallis in ex");
		printByOperator(test);
		test.resize(0, "Quisque accumsan fringilla eros, faucibus auctor leo gravida a. Maecenas sed mi sed tellus pulvinar mattis. Nulla auctor pretium nunc id auctor. Vivamus tincidunt leo sit amet est posuere tincidunt");
		printByOperator(test);
		test.resize(25, "Sed a rutrum metus, vitae iaculis leo. Donec vulputate lacus nisl, et viverra quam blandit vitae. Mauris tempor mollis gravida. Morbi sed mauris at diam pretium rhoncus sit amet auctor odio. Ut sed nunc id leo ultrices dapibus sed a ligula. Fusce eget quam felis. Fusce dignissim elementum pretium. Quisque consectetur lectus non enim molestie efficitur");
		printByOperator(test);
		test.resize(5, "Mauris in eros pharetra, congue sapien at, varius lorem. Aenean cursus nulla at lectus eleifend suscipit. Aliquam sed lectus sed ante sodales sagittis ut et erat. Aenean eu lacus est. Proin et libero ultrices, lacinia ipsum quis, ultricies lectus. Ut volutpat libero ac lobortis accumsan. Etiam purus quam, convallis non blandit eu, sollicitudin vel sem. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus eleifend euismod euismod. Curabitur interdum sollicitudin est ut volutpat. Suspendisse molestie, mauris sit amet ultricies pulvinar, ante nisl posuere lorem, vel aliquet velit eros quis erat. Aliquam vel neque eu massa rhoncus convallis a non augue. Praesent venenatis magna condimentum nibh pulvinar pretium. Etiam maximus malesuada hendrerit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris mollis erat ut risus mollis, a dictum diam tincidunt");
		printByOperator(test);
		test.resize(8, "Hello World!");
		printByOperator(test);
		test.resize(12, "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		printByOperator(test);
	}
}

static void exceptionTests() {
	NAMESPACE::vector<int> test;
	capacityExceptionCheck(test, test.max_size(), true);
	capacityExceptionCheck(test, 0, true);
	capacityExceptionCheck(test, CHAR_BIT, true);
	capacityExceptionCheck(test, CHAR_MIN, true);
	capacityExceptionCheck(test, CHAR_MAX, true);
	capacityExceptionCheck(test, SCHAR_MIN, true);
	capacityExceptionCheck(test, SCHAR_MAX, true);
	capacityExceptionCheck(test, INT_MIN, true);
	// capacityExceptionCheck(test, INT_MAX, true);
	// capacityExceptionCheck(test, UINT_MAX, true);
	capacityExceptionCheck(test, SHRT_MIN, true);
	capacityExceptionCheck(test, SHRT_MAX, true);
	capacityExceptionCheck(test, USHRT_MAX, true);
	capacityExceptionCheck(test, LONG_MIN, true);
	capacityExceptionCheck(test, LONG_MAX, true);
	capacityExceptionCheck(test, ULONG_MAX, true);
}
