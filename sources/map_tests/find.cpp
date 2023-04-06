/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:58:30 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 01:09:39 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define TIMEOUT 12
#ifndef ENABLE_THREAD
# define ENABLE_THREAD false
#endif

void* timer_thread(void* arg)
{
	(void)arg;
    time_t start_time = time(NULL);
    while (true) {
        time_t current_time = time(NULL);
        if (difftime(current_time, start_time) > TIMEOUT) {
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

	{
		NAMESPACE::map<int, int> test;
		NAMESPACE::map<int, int>::iterator it = test.end();
		insertRandomValues(test, 20);
		printContent(test);

		for (NAMESPACE::map<int, int>::iterator it = test.begin(); it != test.end(); it++) {
			std::cout << "map::find(" << it->first << ") = " << test.find(it->first)->first << std::endl;
		}

		NAMESPACE::map<int, int>::key_type value = (++(++test.begin()))->first;
		std::cout << "Is map::find("<< value << ") == map::end()? "
		          << std::boolalpha << (test.find(value) == test.end()) << std::endl;

		value = 42;
		std::cout << "Is map::find("<< value << ") == map::end()? "
		          << (test.find(value) == test.end()) << std::endl
		          << "Is map::find("<< value << ") == it? "
		          << (test.find(value) == it) << std::endl;
	}

	{
		size_t sample_size = 2500000;
		NAMESPACE::map<int, int> test;
		for (size_t i = 0; i <= sample_size; i++) {
			test.insert(NAMESPACE::make_pair(i, i * 2));
		}

		NAMESPACE::map<int, int>::key_type value = sample_size * 0.50;
		std::cout << "map::find("<< value << ")->first = " << test.find(value)->first << std::endl
		          << "map::find("<< value << ")->second = " << test.find(value)->second << std::endl;

		value = sample_size * 0.85;
		std::cout << "map::find("<< value << ")->first = " << test.find(value)->first << std::endl
		          << "map::find("<< value << ")->second = " << test.find(value)->second << std::endl;

		value = sample_size;
		std::cout << "map::find("<< value << ")->first = " << test.find(value)->first << std::endl
		          << "map::find("<< value << ")->second = " << test.find(value)->second << std::endl;
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
