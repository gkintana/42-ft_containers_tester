/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:44:57 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/09 11:27:28 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	NAMESPACE::map<char, std::string> test;
	NAMESPACE::pair<const char, std::string> *temp;
	NAMESPACE::map<char, std::string>::size_type temp_size;

	size_t sample_size = 30;
	temp = test.get_allocator().allocate(sample_size);

	for (size_t i = 0; i < sample_size; i++) {
		test.get_allocator().construct(temp + i, NAMESPACE::make_pair(i + '0', "Hello World!"));
		std::cout << "Key = " << (temp + i)->first << "  |  Value = " << (temp + i)->second << std::endl;
	}

	temp_size = sizeof(NAMESPACE::map<char, std::string>::value_type) * sample_size;
	std::cout << "Allocated size = " << temp_size << " bytes." << std::endl;

	for (size_t i = 0; i < sample_size; i++) {
		test.get_allocator().destroy(temp + i);
	}
	test.get_allocator().deallocate(temp, sample_size);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
