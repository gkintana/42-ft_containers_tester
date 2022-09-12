/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_07_mix.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:20:48 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/12 11:53:01 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_templates.hpp>

template <typename T>
void tempTest(vectorTester test, ft::vector< ft::vector<T> > &ft, std::vector< std::vector<T> > &std) {
	for (size_t i = 0; i < ft.size(); i++) {
        for (size_t j = 0; j < ft[i].size(); j++) {
			ft[i][j] == std[i][j] ? test.addOK() : test.addKO();
        }
		ft[i].empty() == std[i].empty() ? test.addOK() : test.addKO();
		ft[i].size() == std[i].size() ? test.addOK() : test.addKO();
		ft[i].capacity() == std[i].capacity() ? test.addOK() : test.addKO();
		ft[i].max_size() == std[i].max_size() ? test.addOK() : test.addKO();
    }
	
	ft.empty() == std.empty() ? test.addOK() : test.addKO();
	ft.size() == std.size() ? test.addOK() : test.addKO();
	ft.capacity() == std.capacity() ? test.addOK() : test.addKO();
	ft.max_size() == std.max_size() ? test.addOK() : test.addKO();
}

int main() {
	vectorTester test;

	ft::vector<int> ft_v1;
	std::vector<int> std_v1;
	test.pushLoop(ft_v1, std_v1, 42);


	ft::vector< ft::vector<int> > ft;
	std::vector< std::vector<int> > std;


	ft.push_back(ft_v1);
	std.push_back(std_v1);
	// test.compareVectors(ft, std);
	tempTest(test, ft, std);
	
	test.pushLoop(ft_v1, std_v1, 21);
	ft.push_back(ft_v1);
	std.push_back(std_v1);
	// test.compareVectors(ft, std);
	tempTest(test, ft, std);

	// ft.pop_back();
	ft.pop_back();
	ft.pop_back();
	// std.pop_back();
	std.pop_back();
	std.pop_back();
	// for (size_t i = 0; i < ft.size(); i++) {
    //     for (size_t j = 0; j < ft[i].size(); j++) {
	// 		ft[i][j] == std[i][j] ? test.addOK() : test.addKO();
    //     }
    // }
	tempTest(test, ft, std);

	test.pushLoop(ft_v1, std_v1, 30);
	ft.push_back(ft_v1);
	std.push_back(std_v1);
	// test.compareVectors(ft, std);
	tempTest(test, ft, std);
	
	test.printTestResults("Vector of vectors");

	return 0;
}
