/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:39:42 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/10 01:46:11 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_templates.hpp"

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		NAMESPACE::vector<int> test;
		NAMESPACE::vector<int>::size_type size = 30;
		NAMESPACE::vector<int>::pointer ptr = test.get_allocator().allocate(size);

		for (NAMESPACE::vector<int>::size_type i = 0; i < size; i++) {
			test.get_allocator().construct(ptr + i, 10000 + (std::rand() % 50000));
			std::cout << "ptr[" << i << "] = " << ptr[i] << std::endl;
		}
		printByOperator(test);

		for (NAMESPACE::vector<int>::size_type i = 0; i < size; i++) {
			test.get_allocator().destroy(ptr + i);
		}
		test.get_allocator().deallocate(ptr, size);
		printByOperator(test);
	}

	{
		std::string array[] = { "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing",
		                        "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing",
		                        "lorem", "ipsum", "dolor", "sit", "amet", ",", "consectetur", "adipiscing" };

		NAMESPACE::vector<std::string> test;
		NAMESPACE::vector<std::string>::size_type size = sizeof(array) / sizeof(std::string);
		NAMESPACE::vector<std::string>::pointer ptr = test.get_allocator().allocate(size);

		for (NAMESPACE::vector<std::string>::size_type i = 0; i < size; i++) {
			test.get_allocator().construct(ptr + i, *(array + i));
			std::cout << "ptr[" << i << "] = " << ptr[i] << std::endl;
		}
		printByOperator(test);

		for (NAMESPACE::vector<std::string>::size_type i = 0; i < size; i++) {
			test.get_allocator().destroy(ptr + i);
		}
		test.get_allocator().deallocate(ptr, size);
		printByOperator(test);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
	return 0;
}
